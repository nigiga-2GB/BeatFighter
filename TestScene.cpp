#include "TestScene.h"
#include "System.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "ImageManager.h"
#include "AudioManager.h"
#include "NotesManager.h"
#include "Keyboard.h"
//#include "TestScene2.h"
#include "Circle.h"
#include "Color.h"
#include "Math.h"
#include "Easing.h"
#include "Palette.h"
#include "Vec2D.h"
//#include<erslib.h>
//#include "Image.h"
/*
PunchEffect1::PunchEffect1(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool PunchEffect1::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void PunchEffect1::Draw() const
{
	float e = Easing::EaseOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255 * (1 - Math::Min(e, 1.0))));
	Circle{ 220, 400, static_cast<int>(100.0 * Math::Min(e, 1.0)) }.Draw(Palette::Blue);
	//Image{ "Img/test.png" }.Draw(Vec2D{ 400, 400 });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	//std::cout << "waaaa" << std::endl;
}

JumpEffect2::JumpEffect2(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool JumpEffect2::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void JumpEffect2::Draw() const
{
	float e = Easing::EaseOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255 * (1 - Math::Min(e, 1.0))));
	Circle{ 220, Define::WIN_H - 125, static_cast<int>(100.0 * Math::Min(e, 1.0)) }.Draw(Palette::Red);
	//Image{ "Img/test.png" }.Draw(Vec2D{ 400, 400 });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

NonEffect0::NonEffect0(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool NonEffect0::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void NonEffect0::Draw() const
{
	float e = Easing::EaseOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255 * (1 - Math::Min(e, 1.0))));
	Circle{ 500, 500, static_cast<int>(100.0 * Math::Min(e, 1.0)) }.Draw(Palette::Green);
	//Image{ "Img/test.png" }.Draw(Vec2D{ 400, 400 });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Excellent::Excellent(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Excellent::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Excellent::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("excellent", Vec2DF{ (float)Define::WIN_W / 2 - 150, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Good::Good(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Good::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Good::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("good", Vec2DF{ (float)Define::WIN_W / 2 - 100, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Bad::Bad(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Bad::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Bad::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("bad", Vec2DF{ (float)Define::WIN_W / 2 - 80, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Miss::Miss(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Miss::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Miss::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("miss", Vec2DF{ (float)Define::WIN_W / 2 - 100, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

JUDGE_TYPE TestScene::Judge(int itr, float spendTime)
{
	float judgeTime = notes[itr].judgeTime;
	Vec2DF vec = itis[itr];

	if (Math::Abs(vec.x - judgeLine) > 110.0f) return JUDGE_TYPE::Non;
	if (notes[itr].action == Action::Non) return JUDGE_TYPE::Non;

	float num = judgeTime - spendTime;
	//std::cout << num << std::endl;
	if (Math::Abs(judgeTime - spendTime) < 50.0f / 1000.0f)
	{
		notes[itr].isActive = false;
		return JUDGE_TYPE::Excellent;
	}
	else if (Math::Abs(judgeTime - this->spendTime) < 75.0f / 1000.0f)
	{
		notes[itr].isActive = false;
		return JUDGE_TYPE::Good;
	}
	else if (Math::Abs(judgeTime - this->spendTime) < 125.0f / 1000.0f)
	{
		notes[itr].isActive = false;
		return JUDGE_TYPE::Bad;
	}
	else
	{
		notes[itr].isActive = false;
		return JUDGE_TYPE::Miss;
	}
}

TestScene::TestScene()
{
	IMAGE->AddImage("forest", "Img/forest.png");
	AUDIO->AddAudio("haikai", "Sound/BPM180.wav");
	NOTES->AddNotes("haikai", "Notes/BPM180譜面.txt");
	IMAGE->AddImage("bird", "bird.png");
	IMAGE->AddImage("rock", "rock.png");
	IMAGE->AddImage("excellent", "excellent.png");
	IMAGE->AddImage("good", "good.png");
	IMAGE->AddImage("bad", "bad.png");
	IMAGE->AddImage("miss", "miss.png");

	notes = std::vector<Note>(NOTES->GetNotes("haikai"));
	//player = Vec2D{ 175.0f, 500.0f };

	for (auto& note : notes)
	{
		note.isActive = true;
		hasseiTimes.push_back(note.judgeTime - 5);
		itis.push_back(Vec2DF{ judgeLine + speed * note.judgeTime, 50.0f });
		nowJudges.push_back(JUDGE_TYPE::Non);
		isJudged.push_back(false);
	}

}

TestScene::~TestScene()
{
	IMAGE->RemoveImage("forest");
	IMAGE->RemoveImage("excellent");
	IMAGE->RemoveImage("good");
	IMAGE->RemoveImage("bad");
	IMAGE->RemoveImage("miss");
	IMAGE->RemoveImage("bird");
	IMAGE->RemoveImage("rock");
	AUDIO->RemoveAudio("haikai");
	NOTES->RemoveNotes("haikai");
}

void TestScene::Update()
{
	cnt++;
	spendTime += TIMER->GetDeltaTimeS();

	for (int i = 0; i < notes.size(); i++)
	{
		itis[i].x -= speed * TIMER->GetDeltaTimeS();
		if (itis[i].x < -200.0f && notes[i].isActive == true)
		{
			notes[i].isActive = false;

			//以下に外した時のエフェクトもかく
			isJudged[i] = true;
		}
	}

	if (KEYBOARD->GetPressingCount(KEY_INPUT_LSHIFT) == 1)
	{
		EFFECT->AddEffect<PunchEffect1>(1.0);
	}
	if (KEYBOARD->GetPressingCount(KEY_INPUT_RSHIFT) == 1)
	{
		EFFECT->AddEffect<JumpEffect2>(1.0);
	}

	for (int i = 0; i < notes.size(); i++)
	{
		if (KEYBOARD->GetPressingCount(KEY_INPUT_LSHIFT) == 1 && notes[i].action == Action::Punch)
		{
			nowJudges[i] = Judge(i, spendTime);
			if (nowJudges[i] != JUDGE_TYPE::Non && isJudged[i] == false)
			{
				if (nowJudges[i] == JUDGE_TYPE::Excellent)
				{
					EFFECT->AddEffect<Excellent>(1.0);
					std::cout << "Excellent" << std::endl;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Good)
				{
					EFFECT->AddEffect<Good>(1.0);
					std::cout << "Good" << std::endl;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Bad)
				{
					EFFECT->AddEffect<Bad>(1.0);
					std::cout << "Bad" << std::endl;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Miss)
				{
					EFFECT->AddEffect<Miss>(1.0);
					std::cout << "Miss" << std::endl;
				}

				isJudged[i] = true;
			}
		}
		else if (KEYBOARD->GetPressingCount(KEY_INPUT_RSHIFT) == 1 && notes[i].action == Action::Jump)
		{
			nowJudges[i] = Judge(i, spendTime);
			if (nowJudges[i] != JUDGE_TYPE::Non && isJudged[i] == false)
			{
				if (nowJudges[i] == JUDGE_TYPE::Excellent)
				{
					EFFECT->AddEffect<Excellent>(1.0);
					std::cout << "Excellent" << std::endl;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Good)
				{
					EFFECT->AddEffect<Good>(1.0);
					std::cout << "Good" << std::endl;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Bad)
				{
					EFFECT->AddEffect<Bad>(1.0);
					std::cout << "Bad" << std::endl;
				}
				else if (nowJudges[i] == JUDGE_TYPE::Miss)
				{
					EFFECT->AddEffect<Miss>(1.0);
					std::cout << "Miss" << std::endl;
				}

				isJudged[i] = true;
			}
		}
	}

	AUDIO->Play("haikai", PLAY_TYPE::BackGround);
}

void TestScene::Draw() const
{
	IMAGE->Draw("forest", Vec2D{ Define::WIN_W - ((int)cnt % Define::WIN_W) , 0 });
	IMAGE->Draw("forest", Vec2D{ Define::WIN_W - ((int)cnt % Define::WIN_W) - Define::WIN_W , 0 });

	DrawLine(judgeLine, 0, judgeLine, Define::WIN_H, Palette::Red.Get());
	DrawLine(realJudgeLine, 0, realJudgeLine, Define::WIN_H, Palette::LightCyan.Get());

	for (int i = 0; i < notes.size(); i++)
	{
		if (notes[i].isActive)
		{
			if (notes[i].action == Action::Punch)
				IMAGE->Draw("bird", Vec2DF{ itis[i].x, itis[i].y + 350 - (30 * Math::Sin((float)(cnt + i * 10) / 10))});
				//Circle{ (int)itis[i].x, (int)itis[i].y + 450, 30 }.Draw(Palette::Red);
			else if (notes[i].action == Action::Jump)
				IMAGE->Draw("rock", Vec2D{ (int)itis[i].x, Define::WIN_H - 125});
				//Circle{ (int)itis[i].x, (int)itis[i].y + Define::WIN_H - 80, 30 }.Draw(Palette::Blue);
		}
	}
}
*/

//テスト用コード
	/*
	if (vecItr != notes.size())
	{
		if (notes[vecItr].judgeTime <= spendTime && notes[vecItr].isActive == false)
		{
			notes[vecItr].isActive = true;
			vecItr++;
		}

		for (int i = 0; i < vecItr; i++)
		{
			if (notes[i].isActive == true)
			{
				if (notes[i].action == Action::Non)
				{
					EFFECT->AddEffect<NonEffect0>(1.0);
					notes[i].isActive = false;
				}
				else if (notes[i].action == Action::Punch)
				{
					EFFECT->AddEffect<PunchEffect1>(1.0);
					notes[i].isActive = false;
				}
				else if(notes[i].action == Action::Jump)
				{
					EFFECT->AddEffect<JumpEffect2>(1.0);
					notes[i].isActive = false;
				}
			}
		}
	}
	*/