#include "ResultScene.h"
#include "System.h"
#include "ImageManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SerialManager.h"
#include "AudioManager.h"
#include "Keyboard.h"
#include "Vec2D.h"
#include "TitleScene.h"
#include "SelectScene.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

void ResultScene::Update()
{
	//シリアル通信
	if (SERIAL->CheckRecv(port) > 0)
	{
		SERIAL->Recv(port, buffer, 1);
	}

	exceCnt = param["excellent"];
	goodCnt = param["good"];
	badCnt = param["bad"];
	missCnt = param["miss"];
	notesCnt = exceCnt + goodCnt + badCnt + missCnt;

	maxCombo = param["maxCombo"];

	previousScene = param["sceneId"];

	pointPerNote = MAX_POINT / notesCnt;

	result = exceCnt * pointPerNote * exceRate + goodCnt * pointPerNote * goodRate + badCnt * pointPerNote * badRate + missCnt * pointPerNote * missRate;

	if (result >= 95.0f) AUDIO->Play("rank_S_kansei", PLAY_TYPE::BackGround);
	else if (result >= 90) AUDIO->Play("rank_A_kansei", PLAY_TYPE::BackGround);
	else if (result >= 85) AUDIO->Play("rank_B_kansei", PLAY_TYPE::BackGround);

	if (KEYBOARD->GetPressingCount(KEY_INPUT_J) == 1 || buffer[0] == 'J')
	{
		nlohmann::json result;
		SCENE->ChangeScene<ResultScene, TitleScene>(result, true);
	}
	else if (KEYBOARD->GetPressingCount(KEY_INPUT_P) == 1 || buffer[0] == 'P')
	{
		nlohmann::json result;
		SCENE->ChangeScene<ResultScene, SelectScene>(result, true);
	}
}

void ResultScene::Draw() const
{
	//DrawBox(0, 0, Define::WIN_W, Define::WIN_H, Palette::MediumSeaGreen.Get(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 175);
	if (previousScene == "NEXT")
	{
		IMAGE->Draw("sunset", Vec2D{ 0, 0 });
	}
	else if (previousScene == "Haikai")
	{
		IMAGE->Draw("forest", Vec2D{ 0, 0 });
	}
	else if (previousScene == "BPM180")
	{
		IMAGE->Draw("sunny", Vec2D{ 0, 0 });
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	IMAGE->Draw("total_result", Vec2D{ 429, 60 });
	IMAGE->Draw("excellent_result", Vec2D{ 200, 160 });
	IMAGE->Draw("good_result", Vec2D{ 250, 280 });
	IMAGE->Draw("bad_result", Vec2D{ 260, 400 });
	IMAGE->Draw("miss_result", Vec2D{ 255, 520 });
	IMAGE->Draw("maxcombo_result", Vec2D{ 180, 640 });

	if (badCnt + missCnt == 0)
	{
		if (goodCnt == 0)
		{
			IMAGE->Draw("allexcellent_result", Vec2D{ 710, 200 });
		}
		else
		{
			IMAGE->Draw("fullcombo_result", Vec2D{ 760, 200 });
		}
	}

	//excellent
	{
		IMAGE->Draw(GetNumberN(exceCnt, 3), Vec2D{ 520, 170 });
		IMAGE->Draw(GetNumberN(exceCnt, 2), Vec2D{ 550, 170 });
		IMAGE->Draw(GetNumberN(exceCnt, 1), Vec2D{ 580, 170 });
	}
	//good
	{
		IMAGE->Draw(GetNumberN(goodCnt, 3), Vec2D{ 520, 290 });
		IMAGE->Draw(GetNumberN(goodCnt, 2), Vec2D{ 550, 290 });
		IMAGE->Draw(GetNumberN(goodCnt, 1), Vec2D{ 580, 290 });
	}
	//bad
	{
		IMAGE->Draw(GetNumberN(badCnt, 3), Vec2D{ 520, 410 });
		IMAGE->Draw(GetNumberN(badCnt, 2), Vec2D{ 550, 410 });
		IMAGE->Draw(GetNumberN(badCnt, 1), Vec2D{ 580, 410 });
	}
	//miss
	{
		IMAGE->Draw(GetNumberN(missCnt, 3), Vec2D{ 520, 530 });
		IMAGE->Draw(GetNumberN(missCnt, 2), Vec2D{ 550, 530 });
		IMAGE->Draw(GetNumberN(missCnt, 1), Vec2D{ 580, 530 });
	}

	/*
	SetFontSize(50);
	DrawFormatString(200, 610, Palette::White.Get(), L"MAX COMBO   %d", maxCombo);
	*/
	//maxCombo
	{
		IMAGE->Draw(GetNumberN(maxCombo, 3), Vec2D{ 520, 650 });
		IMAGE->Draw(GetNumberN(maxCombo, 2), Vec2D{ 550, 650 });
		IMAGE->Draw(GetNumberN(maxCombo, 1), Vec2D{ 580, 650 });
	}

	SetFontSize(40);
	DrawFormatString(730, 300, Palette::White.Get(), L"Rank");

	if (result >= 95.0f) IMAGE->Draw("rank_S", Vec2D{ 800, 350 });
	else if (result >= 90) IMAGE->Draw("rank_A", Vec2D{ 800, 350 });
	else if (result >= 85) IMAGE->Draw("rank_B", Vec2D{ 800, 350 });
	else if (result >= 75) IMAGE->Draw("rank_C", Vec2D{ 800, 350 });
	else IMAGE->Draw("rank_D", Vec2D{ 800, 350 });

	SetFontSize(50);
	DrawFormatString(Define::WIN_W / 2 + 30, Define::WIN_H - 100, Palette::White.Get(), L"パンチで曲選択に戻る");
}