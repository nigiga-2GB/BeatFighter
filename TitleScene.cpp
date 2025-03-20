#include "TitleScene.h"

#include "System.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "ImageManager.h"
#include "SerialManager.h"

#include "SelectScene.h"
#include "MusicRoom.h"
#include "Museum.h"
#include "Math.h"

TitleScene::TitleScene()
{
	//リソース作成
	IMAGE->AddImage("titleImg", "Img/ゲームタイトル画面.png");
	IMAGE->AddImage("setumei", "Img/説明.png");
	
	//SERIAL->OpenPort(port);
}

TitleScene::~TitleScene()
{
	//リソース削除
	IMAGE->RemoveImage("titleImg");
	IMAGE->RemoveImage("setumei");

	//SERIAL->ClosePort(port);
}

void TitleScene::Update()
{
	if (!isAppeared)
	{
		isFirst = true;
	}
	else if (isAppeared)
	{
		isFirst = false;
	}

	spendTime += TIMER->GetDeltaTimeS();
	
	if (SERIAL->CheckRecv(port) > 0)
	{
		SERIAL->Recv(port, buffer, 1);
	}
	

	if (SERIAL->CheckRecv(8) > 0)
	{
		SERIAL->Recv(8, buffer_2, 1);
	}

	if (KEYBOARD->GetPressingCount(KEY_INPUT_SPACE) == 1 || buffer[0] == 'S')
	{
		nlohmann::json param;
		SCENE->ChangeScene<SelectScene>(param);
	}

	//おまけ: ミュージックルーム遷移
	if (KEYBOARD->GetPressingCount(KEY_INPUT_M) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_U) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_S) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_I) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_C) > 20)
	{
		nlohmann::json waaa;
		SCENE->ChangeScene<MusicRoom>(waaa);
	}

	//おまけ: 美術館遷移
	if (KEYBOARD->GetPressingCount(KEY_INPUT_I) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_M) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_A) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_G) > 20
		&& KEYBOARD->GetPressingCount(KEY_INPUT_E) > 20)
	{
		nlohmann::json waaa;
		SCENE->ChangeScene<Museum>(waaa);
	}

	//ESCAPEでシャットダウン要求したい
	/*
	if (KEYBOARD->GetPressingCount(KEY_INPUT_ESCAPE) == 1)
	{
		SYSTEM->RequestShutdown();
	}
	*/
	/*
	if (buffer[0] != ' ')
		std::cout << buffer[0] << " ";
		*/

	/*
	if (buffer_2[0] != ' ')
	{
		std::cout << buffer_2[0] << " ";
	}
	*/

	if ((int)spendTime % 2 == 0 && !isAppeared)
	{
		isAppeared = true;
		isFirst = true;
	}
	if ((int)spendTime % 2 != 0)
	{
		isAppeared = false;
	}

	if (isAppeared && isFirst)
	{
		r = Math::Random(1, 20);

		//std::cout << r << std::endl;
	}
}

void TitleScene::Draw() const
{
	IMAGE->Draw("titleImg", Vec2D{ 0, 0 });

	if ((int)spendTime % 2 == 0)
	{
		IMAGE->Draw("setumei", Vec2D{ 910, 540 });

		if (r == 1)
		{
			DrawString(910, 600, L"Museum には [i,m,a,g,e]\nMusicRoom には [m,u,s,i,c] で移動できる", Palette::White.Get());
		}
	}
}