#include "SelectScene.h"

#include "System.h"
#include "InputManager.h"
#include "ImageManager.h"
#include "Keyboard.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "SerialManager.h"
#include "AudioManager.h"
#include "BPM180.h"
#include "HaikaiScene.h"
#include "NEXTScene.h"
#include "NotesConfig.h"

SelectScene::SelectScene()
{
	/*
	int sp = Define::WIN_W / 4;
	BPM = Vec2D(sp * 1, Define::WIN_H / 2);
	HAIKAI = Vec2D(sp * 2, Define::WIN_H / 2);
	NEXT = Vec2D(sp * 3, Define::WIN_H / 2);
	nowSelect = BPM;
	*/
	/*
	int sp = Define::WIN_H / 4;
	BPM = Vec2D(Define::WIN_W / 2 - 100, sp * 1);
	HAIKAI = Vec2D(Define::WIN_W / 2 - 100, sp * 2);
	NEXT = Vec2D(Define::WIN_W / 2 - 100, sp * 3);
	nowSelect = BPM;
	*/

	SERIAL->OpenPort(port, 9600);
}

SelectScene::~SelectScene()
{

}

void SelectScene::Update()
{
	volume++;
	frame++;
	spendTime += TIMER->GetDeltaTimeS();
	spendSoundTime += TIMER->GetDeltaTimeS();

	if (SERIAL->CheckRecv(port) > 0)
	{
		SERIAL->Recv(port, buffer, 1);
	}

	if (KEYBOARD->GetPressingCount(KEY_INPUT_J) == 1 || buffer[0] == 'J')
	{
		selectCnt++;
		volume = 0;
	}
	nowSelect.y = Define::WIN_H / 4 * (selectCnt % 3 + 1);

	int select = (selectCnt % 3) + 1;

	if (select == 1)
	{
		AUDIO->Stop("sound_haikai");
		AUDIO->Stop("sound_next");

		AUDIO->Play("sound_bpm180", PLAY_TYPE::BackGround);

		if (spendSoundTime >= 18.0f)
		{
			AUDIO->Stop("sound_bpm180");
			volume = 0;
			spendSoundTime = 0;
		}
		else if (spendSoundTime >= 15.0f)
		{
			AUDIO->SetVolumeF("sound_bpm180", Math::Cos((spendSoundTime - 15.0f) / 3 * Math::PI / 2));
		}
		else if (spendSoundTime < 15.0f)
		{
			AUDIO->SetVolume("sound_bpm180", volume * 2);
		}
	}
	else if (select == 2)
	{
		AUDIO->Stop("sound_bpm180");
		AUDIO->Stop("sound_next");

		AUDIO->Play("sound_haikai", PLAY_TYPE::BackGround);

		if (spendSoundTime >= 18.0f)
		{
			AUDIO->Stop("sound_haikai");
			volume = 0;
			spendSoundTime = 0;
		}
		else if (spendSoundTime >= 15.0f)
		{
			AUDIO->SetVolumeF("sound_haikai", Math::Cos((spendSoundTime - 15.0f) / 3 * Math::PI / 2));
		}
		else if (spendSoundTime < 15.0f)
		{
			AUDIO->SetVolume("sound_haikai", volume * 2);
		}
	}
	else if (select == 3)
	{
		AUDIO->Stop("sound_bpm180");
		AUDIO->Stop("sound_haikai");

		AUDIO->Play("sound_next", PLAY_TYPE::BackGround);

		if (spendSoundTime >= 18.0f)
		{
			AUDIO->Stop("sound_next");
			volume = 0;
			spendSoundTime = 0;
		}
		else if (spendSoundTime >= 15.0f)
		{
			AUDIO->SetVolumeF("sound_next", Math::Cos((spendSoundTime - 15.0f) / 3 * Math::PI / 2));
		}
		else if (spendSoundTime < 15.0f)
		{
			AUDIO->SetVolume("sound_next", volume * 2);
		}
	}

	if (KEYBOARD->GetPressingCount(KEY_INPUT_P) == 1 || buffer[0] == 'P')
	{
		if (select == 1)
		{
			nlohmann::json param;
			
			AUDIO->Stop("sound_bpm180");
			AUDIO->SetVolume("sound_bpm180", 255);
			
			SCENE->ChangeScene<SelectScene, BPM180>(param, true);
		}
		else if (select == 2)
		{
			nlohmann::json param;
			
			AUDIO->Stop("sound_haikai");
			AUDIO->SetVolume("sound_haikai", 255);
			
			SCENE->ChangeScene<SelectScene, HaikaiScene>(param, true);
		}
		else if (select == 3)
		{
			nlohmann::json param;
			
			AUDIO->Stop("sound_next");
			AUDIO->SetVolume("sound_next", 255);
			
			SCENE->ChangeScene<SelectScene, NEXTScene>(param, true);
		}
	}

	if (KEYBOARD->GetPressingCount(KEY_INPUT_C) == 1)
	{
		nlohmann::json setting;

		if (AUDIO->IsPlaying("sound_next")) AUDIO->Stop("sound_next");
		if (AUDIO->IsPlaying("sound_haikai")) AUDIO->Stop("sound_haikai");
		if (AUDIO->IsPlaying("sound_bpm180")) AUDIO->Stop("sound_bpm180");

		SCENE->ChangeScene<SelectScene, NotesConfig>(setting);
	}
}

void SelectScene::Draw() const
{
	DrawBox(0, 0, Define::WIN_W, Define::WIN_H, GetColor(32, 40, 79), TRUE);
	//IMAGE->Draw("ui_select", Vec2D{ 0, 0 });
	SetDrawBlendMode(DX_BLENDMODE_ADD, (int)(70.0f - 40.0f * Math::Abs(Math::Cos(spendTime / 3.0f * Math::PI / 2.0f))));
	IMAGE->DrawRotaAdv("BGIMG_select", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 512.0f, 512.0f }, 0.1f * Math::Sin(spendTime / 2.0f * Math::PI / 2), 1.5f, 1.5f);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	IMAGE->Draw("ui_select", Vec2D{ 0, 0 });

	//Circle{ nowSelect.x, nowSelect.y, 75 }.Draw(Palette::White);
	//Circle{ BPM.x, BPM.y, 50 }.Draw(Palette::Aqua);
	//Circle{ HAIKAI.x, HAIKAI.y, 50 }.Draw(Palette::Pink);
	//Circle{ NEXT.x, NEXT.y, 50 }.Draw(Palette::Yellow);

	int left = selectCnt % 3;
	int nowSel = (selectCnt + 1) % 3;
	int right = (selectCnt + 2) % 3;
	
	//¶
	{
		Circle{ Define::WIN_W / 4 - 50, Define::WIN_H / 5 * 3, 150 }.Draw(Palette::Black);
		//IMAGE->DrawRotaAdv("forest_select", Vec2D{ Define::WIN_W / 4 - 50, Define::WIN_H / 5 * 3 }, Vec2D{ 250, 250 }, 0.0f, 0.5, 0.5);
		IMAGE->DrawRotaAdv(SelectImg(left), Vec2D{ Define::WIN_W / 4 - 50, Define::WIN_H / 5 * 3 }, Vec2D{ 250, 250 }, Math::ToRadian(-10), 0.5, 0.5);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 175);
		Circle{ Define::WIN_W / 4 - 50, Define::WIN_H / 5 * 3, 150 }.Draw(Palette::Black);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

	//^‚ñ’†
	{
		Circle{ Define::WIN_W / 2, Define::WIN_H / 2, 150 }.Draw(Palette::Black);
		//IMAGE->DrawRotaAdv("forest_select", Vec2D{ Define::WIN_W / 2, Define::WIN_H / 2 }, Vec2D{ 250, 250 }, 0.0f, 0.5, 0.5);
		IMAGE->DrawRotaAdv(SelectImg(nowSel), Vec2D{ Define::WIN_W / 2, Define::WIN_H / 2 }, Vec2D{ 250, 250 }, 0.0f, 0.5, 0.5);

		SetDrawBlendMode(DX_BLENDMODE_ADD, 30 + 30 * Math::Sin(spendTime * Math::PI / 2 * 2));
		Circle{ Define::WIN_W / 2, Define::WIN_H / 2, 200 }.Draw(Palette::Yellow);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	
	//‰E
	{
		Circle{ Define::WIN_W / 4 * 3 + 50, Define::WIN_H / 5 * 3, 150 }.Draw(Palette::Black);
		//IMAGE->DrawRotaAdv("forest_select", Vec2D{ Define::WIN_W / 4 * 3 + 50, Define::WIN_H / 5 * 3 }, Vec2D{ 250, 250 }, 0.0f, 0.5, 0.5);
		IMAGE->DrawRotaAdv(SelectImg(right), Vec2D{ Define::WIN_W / 4 * 3 + 50, Define::WIN_H / 5 * 3 }, Vec2D{ 250, 250 }, Math::ToRadian(10), 0.5, 0.5);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 175);
		Circle{ Define::WIN_W / 4 * 3 + 50, Define::WIN_H / 5 * 3, 150 }.Draw(Palette::Black);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

	if (nowSel == 0)
	{
		//DrawFormatString(Define::WIN_W / 2 - 100, Define::WIN_H - 100, Palette::White.Get(), L"ŽŸ‚Ö");
		IMAGE->Draw("next_select", Vec2DF{ (float)Define::WIN_W / 2.0f - 54.2f, Define::WIN_H - 100.0f });
	}
	else if (nowSel == 1)
	{
		//DrawFormatString(Define::WIN_W / 2 - 100, Define::WIN_H - 100, Palette::White.Get(), L"BPM180");
		IMAGE->Draw("bpm180_select", Vec2DF{(float)Define::WIN_W / 2.0f - 94.5f, Define::WIN_H - 100.0f});
	}
	else if (nowSel == 2)
	{
		//DrawFormatString(Define::WIN_W / 2 - 100, Define::WIN_H - 100, Palette::White.Get(), L"œpœj");
		IMAGE->Draw("haikai_select", Vec2DF{ (float)Define::WIN_W / 2.0f - 54.0f, Define::WIN_H - 100.0f });
	}

	IMAGE->Draw("jump_select", Vec2DF{ (float)Define::WIN_W / 2.0f - 300.0f - 169.0f, Define::WIN_H - 50.0f });
	IMAGE->Draw("punch_select", Vec2DF{ (float)Define::WIN_W / 2.0f + 300.0f - 169.0f, Define::WIN_H - 50.0f });

	/*
	SetFontSize(80);
	Circle{ nowSelect.x - 100, nowSelect.y + 50, 75 }.Draw(Palette::White);
	DrawFormatString(BPM.x, BPM.y, Palette::Aqua.Get(), L"BPM180");
	DrawFormatString(HAIKAI.x, HAIKAI.y, Palette::Pink.Get(), L"œpœj");
	DrawFormatString(NEXT.x, NEXT.y, Palette::Yellow.Get(), L"ŽŸ‚Ö");
	*/
}

std::string SelectScene::SelectImg(int id) const
{
	if (id == 0)
	{
		return "sunset_select";
	}
	else if (id == 1)
	{
		return "sunny_select";
	}
	else if (id == 2)
	{
		return "forest_select";
	}

	std::cout << "non‚Å‚·‚ª" << std::endl;
	return "non";
}