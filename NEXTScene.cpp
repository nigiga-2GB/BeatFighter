#include "NEXTScene.h"
#include "System.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "ImageManager.h"
#include "AudioManager.h"
#include "NotesManager.h"
#include "SerialManager.h"
#include "PlayerManager.h"
#include "Keyboard.h"

#include "Circle.h"
#include "Color.h"
#include "Math.h"
#include "Easing.h"
#include "Palette.h"
#include "Vec2D.h"
#include "ResultScene.h"


JUDGE_TYPE NEXTScene::Judge(int itr, float spendTime)
{
	//v4.3 added
	std::filesystem::path cfgPath = "NotesConfig/NotesConfig.txt";
	std::ifstream file(cfgPath);
	std::string offset;
	std::getline(file, offset);
	file.close();

	float judgeTime = notes[itr].judgeTime + std::stof(offset);
	Vec2DF vec = itis[itr];

	if (Math::Abs(vec.x - judgeLine) > 110.0f) return JUDGE_TYPE::Non;
	if (notes[itr].action == Action::Non) return JUDGE_TYPE::Non;

	float num = judgeTime - spendTime;
	if (Math::Abs(judgeTime - spendTime) < 50.0f / 1000.0f)
	{
		notes[itr].isActive = false;

		//v4.2 added
		if (notes[itr].action == Action::Punch)
			EFFECT->AddEffect<PunchHuttobi>(1.0f);

		return JUDGE_TYPE::Excellent;
	}
	else if (Math::Abs(judgeTime - this->spendTime) < 75.0f / 1000.0f)
	{
		notes[itr].isActive = false;

		//v4.2 added
		if(notes[itr].action == Action::Punch)
			EFFECT->AddEffect<PunchHuttobi>(1.0f);

		return JUDGE_TYPE::Good;
	}
	else if (Math::Abs(judgeTime - this->spendTime) < 125.0f / 1000.0f)
	{
		notes[itr].isActive = false;

		//v4.2 added
		EFFECT->AddEffect<PunchHuttobi>(1.0f);

		return JUDGE_TYPE::Bad;
	}
	else
	{
		notes[itr].isActive = false;
		return JUDGE_TYPE::Miss;
	}
}

NEXTScene::NEXTScene()
{
	notes = std::vector<Note>(NOTES->GetNotes("notes_next"));

	//v4.3 added
	std::filesystem::path cfgPath = "NotesConfig/NotesConfig.txt";
	std::ifstream file(cfgPath);
	std::string offset;
	std::getline(file, offset);
	file.close();

	for (auto& note : notes)
	{
		note.isActive = true;
		hasseiTimes.push_back(note.judgeTime + std::stof(offset)/* - 5*/);
		itis.push_back(Vec2DF{ judgeLine + speed * (note.judgeTime + std::stof(offset)), 50.0f });
		nowJudges.push_back(JUDGE_TYPE::Non);
		isJudged.push_back(false);
	}
}

NEXTScene::~NEXTScene()
{
	
}

void NEXTScene::Update()
{
	cnt++;
	spendTime += TIMER->GetDeltaTimeS();

	PLAYER->Update();

	//シリアル通信
	if (SERIAL->CheckRecv(arPort) > 0)
	{
		SERIAL->Recv(arPort, buffer, 1);
	}

	// v4.2 added
	if (KEYBOARD->GetPressingCount(KEY_INPUT_P) == 1 || buffer[0] == 'P')
	{
		EFFECT->AddEffect<PunchEffect>(1.0f);
		PLAYER->Punch(0.3f);
	}
	if (KEYBOARD->GetPressingCount(KEY_INPUT_J) == 1 || buffer[1] == 'J')
	{
		EFFECT->AddEffect<JumpEffect>(1.0f);
		PLAYER->Jump(0.5f);
	}

	//譜面移動＆画面外判定
	for (int i = 0; i < notes.size(); i++)
	{
		itis[i].x -= speed * TIMER->GetDeltaTimeS();
		if (itis[i].x < -200.0f && notes[i].isActive == true)
		{
			notes[i].isActive = false;

			//以下に外した時のエフェクトもかく
			if (isJudged[i] == false/* && (notes[i].action == Action::Punch || notes[i].action == Action::Jump)*/)
			{
				EFFECT->AddEffect<Miss>(1.0);
				std::cout << "Miss" << std::endl;
				nowJudges[i] = JUDGE_TYPE::Miss;
				nowCombo = 0;
			}
			isJudged[i] = true;
		}
	}

	//判定
	for (int i = 0; i < notes.size(); i++)
	{
		if ((KEYBOARD->GetPressingCount(KEY_INPUT_P) == 1 || buffer[0] == 'P') && notes[i].action == Action::Punch)
		{
			if (isJudged[i] == false)
			{
				nowJudges[i] = Judge(i, spendTime);
			}
			
			if (nowJudges[i] != JUDGE_TYPE::Non && isJudged[i] == false)
			{
				if (nowJudges[i] == JUDGE_TYPE::Excellent)
				{
					EFFECT->AddEffect<Excellent>(1.0);
					std::cout << "Excellent" << std::endl;
					nowCombo++;
					if (maxCombo < nowCombo) maxCombo++;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Good)
				{
					EFFECT->AddEffect<Good>(1.0);
					std::cout << "Good" << std::endl;
					nowCombo++;
					if (maxCombo < nowCombo) maxCombo++;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Bad)
				{
					EFFECT->AddEffect<Bad>(1.0);
					std::cout << "Bad" << std::endl;
					nowCombo = 0;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Miss)
				{
					EFFECT->AddEffect<Miss>(1.0);
					std::cout << "Miss" << std::endl;
					nowCombo = 0;
				}

				isJudged[i] = true;
			}
		}
		else if ((KEYBOARD->GetPressingCount(KEY_INPUT_J) == 1 || buffer[0] == 'J') && notes[i].action == Action::Jump)
		{
			if (isJudged[i] == false)
			{
				nowJudges[i] = Judge(i, spendTime);
			}

			if (nowJudges[i] != JUDGE_TYPE::Non && isJudged[i] == false)
			{
				if (nowJudges[i] == JUDGE_TYPE::Excellent)
				{
					EFFECT->AddEffect<Excellent>(1.0);
					std::cout << "Excellent" << std::endl;
					nowCombo++;
					if (maxCombo < nowCombo) maxCombo++;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Good)
				{
					EFFECT->AddEffect<Good>(1.0);
					std::cout << "Good" << std::endl;
					nowCombo++;
					if (maxCombo < nowCombo) maxCombo++;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Bad)
				{
					EFFECT->AddEffect<Bad>(1.0);
					std::cout << "Bad" << std::endl;
					nowCombo = 0;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Miss)
				{
					EFFECT->AddEffect<Miss>(1.0);
					std::cout << "Miss" << std::endl;
					nowCombo = 0;
				}

				isJudged[i] = true;
			}
		}
	}

	if (spendTime <= notes[notes.size() - 1].judgeTime)
		AUDIO->Play("sound_next", PLAY_TYPE::BackGround);
	else
	{
		AUDIO->Stop("sound_next");
		if (spendTime >= notes[notes.size() - 1].judgeTime + 2)
		{
			std::cout << "play ended." << std::endl;

			nlohmann::json result;
			result["excellent"] = /*exCnt;*/std::count(nowJudges.begin(), nowJudges.end(), JUDGE_TYPE::Excellent);
			result["good"] = /*goCnt;*/std::count(nowJudges.begin(), nowJudges.end(), JUDGE_TYPE::Good);
			result["bad"] = /*baCnt;*/std::count(nowJudges.begin(), nowJudges.end(), JUDGE_TYPE::Bad);
			result["miss"] = /*miCnt;*/std::count(nowJudges.begin(), nowJudges.end(), JUDGE_TYPE::Miss);
			result["maxCombo"] = maxCombo;

			std::string sceneId = "NEXT";
			result["sceneId"] = sceneId;

			std::cout << "excellent: " << result["excellent"] << std::endl;
			std::cout << "good: " << result["good"] << std::endl;
			std::cout << "bad: " << result["bad"] << std::endl;
			std::cout << "miss: " << result["miss"] << std::endl;
			std::cout << "max combo: " << result["maxCombo"] << std::endl;

			SCENE->ChangeScene<NEXTScene, ResultScene>(result, true);
		}
	}
}

void NEXTScene::Draw() const
{
	IMAGE->Draw("sunset", Vec2D{ Define::WIN_W - ((int)cnt % Define::WIN_W) , 0 });
	IMAGE->Draw("sunset", Vec2D{ Define::WIN_W - ((int)cnt % Define::WIN_W) - Define::WIN_W , 0 });

	//DrawLine(judgeLine, 0, judgeLine, Define::WIN_H, Palette::Red.Get());
	//DrawLine(realJudgeLine, 0, realJudgeLine, Define::WIN_H, Palette::LightCyan.Get());

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	Circle{ realJudgeLine, 450, 90 }.DrawFrame(Palette::White, 10);
	Circle{ realJudgeLine, Define::WIN_H - 100, 90 }.DrawFrame(Palette::White, 10);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	for (int i = 0; i < notes.size(); i++)
	{
		if (notes[i].isActive)
		{
			if (notes[i].action == Action::Punch)
				IMAGE->Draw("bird", Vec2DF{ itis[i].x, itis[i].y + 350 - (30 * Math::Sin((float)(cnt + i * 10) / 10)) });
			/*else if (notes[i].action == Action::Jump)
				IMAGE->Draw("rock", Vec2D{ (int)itis[i].x, Define::WIN_H - 125 });*/
		}

		if (notes[i].action == Action::Jump)
			IMAGE->Draw("rock", Vec2D{ (int)itis[i].x, Define::WIN_H - 125 });
	}

	if (nowCombo >= 5)
	{
		SetFontSize(280);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 65);
		DrawFormatString(0, 0, Palette::White.Get(), L"Combo:%3d", nowCombo);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

	PLAYER->Draw();
	//IMAGE->DrawRotaAdv("chara_1", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
}