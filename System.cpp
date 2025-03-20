#include "System.h"

#include "TimeManager.h"
#include "InputManager.h"
#include "Keyboard.h"
#include "SceneManager.h"
#include "EffectManager.h"
#include "ImageManager.h"
#include "AudioManager.h"
#include "NotesManager.h"
#include "SerialManager.h"
#include "PlayerManager.h"
/*
#include "TestScene.h"
#include "TestScene2.h"
*/
#include "TitleScene.h"
#include "SelectScene.h"
#include "BPM180.h"
#include "HaikaiScene.h"
#include "NEXTScene.h"
#include "ResultScene.h"
#include "MusicRoom.h"
#include "Museum.h"
#include "NotesConfig.h"
#include "Define.h"


System* System::pInstance = nullptr;
TimeManager* System::timeManager = nullptr;
InputManager* System::inputManager = nullptr;
SceneManager* System::sceneManager = nullptr;
EffectManager* System::effectManager = nullptr;
ImageManager* System::imageManager = nullptr;
AudioManager* System::audioManager = nullptr;
NotesManager* System::notesManager = nullptr;
SerialManager* System::serialManager = nullptr;
PlayerManager* System::playerManager = nullptr;

System* System::GetInstance()
{
	if (pInstance == nullptr)
	{
		pInstance = new System();
	}

	return pInstance;
}

void System::DeleteInstance()
{
	if (pInstance != nullptr)
	{
		delete pInstance;
		pInstance = nullptr;
	}
}

bool System::Initialize() const
{
	//ウィンドウがノンアクティブでも実行
	SetAlwaysRunFlag(true);
	//ウィンドウサイズを自由に変更できるようにする
	SetWindowSizeChangeEnableFlag(false);
	//ログ出力しない
	//SetOutApplicationLogValidFlag(false);
	//フルスクリーン時に縦横比を維持する
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	//ウィンドウタイトルをつける
	SetWindowText(L"BeatFighter");
	//ウィンドウモードに変更
	//ChangeWindowMode(true);
	//ウィンドウサイズを変更したいときはここに倍率を指定
	SetWindowSizeExtendRate(1.0);
	//色のビット数
	const int COLOR_BIT = 32;
	//ゲーム画面の解像度を設定
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);

	
	//DxLib初期化処理
	if (DxLib_Init())
	{
		return false;
	}

	//裏画面処理を設定
	SetDrawScreen(DX_SCREEN_BACK);


	timeManager = new TimeManager();
	if (timeManager == nullptr)
	{
		std::cout << "TimeManagerの作成に失敗しました" << std::endl;
		return false;
	}
	inputManager = new InputManager();
	if (inputManager == nullptr)
	{
		std::cout << "InputManagerの作成に失敗しました" << std::endl;
		return false;
	}
	sceneManager = new SceneManager();
	if (sceneManager == nullptr)
	{
		std::cout << "SceneManagerの作成に失敗しました" << std::endl;
		return false;
	}
	effectManager = new EffectManager();
	if (effectManager == nullptr)
	{
		std::cout << "EffectManagerの作成に失敗しました" << std::endl;
		return false;
	}
	imageManager = new ImageManager();
	if (imageManager == nullptr)
	{
		std::cout << "ImageManagerの作成に失敗しました" << std::endl;
		return false;
	}
	audioManager = new AudioManager();
	if (audioManager == nullptr)
	{
		std::cout << "AudioManagerの作成に失敗しました" << std::endl;
		return false;
	}
	notesManager = new NotesManager();
	if (notesManager == nullptr)
	{
		std::cout << "NotesManagerの作成に失敗しました" << std::endl;
		return false;
	}
	serialManager = new SerialManager();
	if (serialManager == nullptr)
	{
		std::cout << "SerialManagerの作成に失敗しました" << std::endl;
		return false;
	}
	playerManager = new PlayerManager();
	if (playerManager == nullptr)
	{
		std::cout << "PlayerManagerの作成に失敗しました" << std::endl;
		return false;
	}

	//選曲
	IMAGE->AddImage("sunny_select", "Img/sunny_select.png");
	IMAGE->AddImage("forest_select", "Img/forest_select.png");
	IMAGE->AddImage("sunset_select", "Img/sunset_select.png");
	IMAGE->AddImage("BGIMG_select", "Img/BGIMG_select.jpeg");
	IMAGE->AddImage("ui_select", "Img/UI_select改_transparent.png");
	IMAGE->AddImage("bpm180_select", "Img/bpm180_select.png");
	IMAGE->AddImage("haikai_select", "Img/徘徊_select.png");
	IMAGE->AddImage("next_select", "Img/next_select.png");
	IMAGE->AddImage("jump_select", "Img/jump_select.png");
	IMAGE->AddImage("punch_select", "Img/punch_select.png");

	//リザルト
	IMAGE->AddImage("total_result", "Img/TOTALRESULT.png");
	IMAGE->AddImage("excellent_result", "Img/excellent_result改.png");
	IMAGE->AddImage("good_result", "Img/good_result改.png");
	IMAGE->AddImage("bad_result", "Img/bad_result改.png");
	IMAGE->AddImage("miss_result", "Img/miss_result改.png");
	IMAGE->AddImage("maxcombo_result", "Img/maxcombo_result改.png");
	IMAGE->AddImage("fullcombo_result", "Img/fullcombo_result改.png");
	IMAGE->AddImage("allexcellent_result", "Img/allexcellent_result改.png");
	IMAGE->AddImage("rank_S", "Img/rank_S.png");
	IMAGE->AddImage("rank_A", "Img/rank_A.png");
	IMAGE->AddImage("rank_B", "Img/rank_B.png");
	IMAGE->AddImage("rank_C", "Img/rank_C.png");
	IMAGE->AddImage("rank_D", "Img/rank_D.png");
	AUDIO->AddAudio("rank_S_kansei", "Sound/歓声S.mp3");
	AUDIO->AddAudio("rank_A_kansei", "Sound/歓声A.mp3");
	AUDIO->AddAudio("rank_B_kansei", "Sound/歓声B.mp3");

	//数字フォント
	IMAGE->AddImage("1", "Img/font_one.png");
	IMAGE->AddImage("2", "Img/font_two.png");
	IMAGE->AddImage("3", "Img/font_three.png");
	IMAGE->AddImage("4", "Img/font_four.png");
	IMAGE->AddImage("5", "Img/font_five.png");
	IMAGE->AddImage("6", "Img/font_six.png");
	IMAGE->AddImage("7", "Img/font_seven.png");
	IMAGE->AddImage("8", "Img/font_eight.png");
	IMAGE->AddImage("9", "Img/font_nine.png");
	IMAGE->AddImage("0", "Img/font_zero.png");

	//判定系リソース
	IMAGE->AddImage("excellent", "Img/excellent.png");
	IMAGE->AddImage("good", "Img/good.png");
	IMAGE->AddImage("bad", "Img/bad.png");
	IMAGE->AddImage("miss", "Img/miss.png");

	//各ステージ画像
	IMAGE->AddImage("sunny", "Img/sunny.png");
	IMAGE->AddImage("forest", "Img/forest.png");
	IMAGE->AddImage("sunset", "Img/sunset.png");
	//各ステージ譜面
	NOTES->AddNotes("notes_bpm180", "Notes/BPM180譜面.txt");
	NOTES->AddNotes("notes_haikai", "Notes/徘徊譜面2.txt");
	NOTES->AddNotes("notes_next", "Notes/次へ譜面.txt");
	//各ステージ音楽
	AUDIO->AddAudio("sound_bpm180", "Sound/BPM180.wav");
	AUDIO->AddAudio("sound_haikai", "Sound/徘徊.wav");
	AUDIO->AddAudio("sound_next", "Sound/次へ.wav");

	//障害物
	IMAGE->AddImage("bird", "Img/bird.png");
	IMAGE->AddImage("rock", "Img/rock.png");

	//キャラクター
	IMAGE->AddImage("chara_1", "Img/chara_1.png");
	IMAGE->AddImage("chara_2", "Img/chara_2.png");
	IMAGE->AddImage("chara_3", "Img/chara_3.png");
	IMAGE->AddImage("chara_4", "Img/chara_4.png");
	IMAGE->AddImage("chara_5", "Img/chara_5.png");
	IMAGE->AddImage("chara_jump_1", "Img/chara_jump_1.png");
	IMAGE->AddImage("chara_punch_1", "Img/chara_punch_1.png");

	//判定調節
	AUDIO->AddAudio("notes_config", "Sound/判定調節.wav");

	std::cout << "System Initialized." << std::endl;

	sceneManager->AddScene<TitleScene>();
	sceneManager->AddScene<SelectScene>();
	sceneManager->AddScene<BPM180>();
	sceneManager->AddScene<HaikaiScene>();
	sceneManager->AddScene<NEXTScene>();
	sceneManager->AddScene<ResultScene>();
	sceneManager->AddScene<MusicRoom>();
	sceneManager->AddScene<Museum>();
	sceneManager->AddScene<NotesConfig>();
	nlohmann::json first;
	first["first"] = "FIRST SCENE";
	sceneManager->ChangeScene<TitleScene>(first);

	SERIAL->ClosePort(arPort);

	int err = SERIAL->OpenPort(arPort);
	if (err == 0)
	{
		std::cout << "オープンできた" << std::endl;
	}
	else if (err == 1)
	{
		std::cout << "ポート番号が範囲外" << std::endl;
	}
	else if (err == 2)
	{
		std::cout << "すでにオープンされている" << std::endl;
	}
	else if (err == 3)
	{
		std::cout << "他で使用中か装備されていない" << std::endl;
	}
	else if (err == 4)
	{
		std::cout << "指定のボーレートでオープンできない" << std::endl;
	}

	SERIAL->OpenPort(h8Port, 9600);
	//SERIAL->OpenPort(arPort, 9600);

	return true;
}

void System::Finalize() const
{
	IMAGE->RemoveImage("sunny_select");
	IMAGE->RemoveImage("forest_select");
	IMAGE->RemoveImage("sunset_select");
	IMAGE->RemoveImage("BGIMG_select");
	IMAGE->RemoveImage("ui_select");
	IMAGE->RemoveImage("bpm180_select");
	IMAGE->RemoveImage("haikai_select");
	IMAGE->RemoveImage("next_select");
	IMAGE->RemoveImage("jump_select");
	IMAGE->RemoveImage("punch_select");

	IMAGE->RemoveImage("total_result");
	IMAGE->RemoveImage("excellent_result");
	IMAGE->RemoveImage("good_result");
	IMAGE->RemoveImage("bad_result");
	IMAGE->RemoveImage("miss_result");
	IMAGE->RemoveImage("maxcombo_result");
	IMAGE->RemoveImage("fullcombo_result");
	IMAGE->RemoveImage("allexcellent_result");
	IMAGE->RemoveImage("rank_S");
	IMAGE->RemoveImage("rank_A");
	IMAGE->RemoveImage("rank_B");
	IMAGE->RemoveImage("rank_C");
	IMAGE->RemoveImage("rank_D");
	AUDIO->RemoveAudio("rank_S_kansei");
	AUDIO->RemoveAudio("rank_A_kansei");
	AUDIO->RemoveAudio("rank_B_kansei");

	IMAGE->RemoveImage("1");
	IMAGE->RemoveImage("2");
	IMAGE->RemoveImage("3");
	IMAGE->RemoveImage("4");
	IMAGE->RemoveImage("5");
	IMAGE->RemoveImage("6");
	IMAGE->RemoveImage("7");
	IMAGE->RemoveImage("8");
	IMAGE->RemoveImage("9");
	IMAGE->RemoveImage("0");


	SERIAL->ClosePort(h8Port);
	SERIAL->ClosePort(arPort);

	//判定系リソース
	IMAGE->RemoveImage("excellent");
	IMAGE->RemoveImage("good");
	IMAGE->RemoveImage("bad");
	IMAGE->RemoveImage("miss");

	//各ステージ画像
	IMAGE->RemoveImage("sunny");
	IMAGE->RemoveImage("forest");
	IMAGE->RemoveImage("sunset");
	//各ステージ譜面
	NOTES->RemoveNotes("notes_bpm180");
	NOTES->RemoveNotes("notes_haikai");
	NOTES->RemoveNotes("notes_next");
	//各ステージ音楽
	AUDIO->RemoveAudio("sound_bpm180");
	AUDIO->RemoveAudio("sound_haikai");
	AUDIO->RemoveAudio("sound_next");

	//障害物
	IMAGE->RemoveImage("bird");
	IMAGE->RemoveImage("rock");

	//キャラ
	IMAGE->RemoveImage("chara_1");
	IMAGE->RemoveImage("chara_2");
	IMAGE->RemoveImage("chara_3");
	IMAGE->RemoveImage("chara_4");
	IMAGE->RemoveImage("chara_5");
	IMAGE->RemoveImage("chara_jump_1");
	IMAGE->RemoveImage("chara_punch_1");

	//譜面調整
	AUDIO->RemoveAudio("notes_config");

	if (timeManager != nullptr)
	{
		delete timeManager;
		timeManager = nullptr;
	}
	if (inputManager != nullptr)
	{
		delete inputManager;
		inputManager = nullptr;
	}
	if (sceneManager != nullptr)
	{
		delete sceneManager;
		sceneManager = nullptr;
	}
	if (effectManager != nullptr)
	{
		delete effectManager;
		effectManager = nullptr;
	}
	if (imageManager != nullptr)
	{
		delete imageManager;
		imageManager = nullptr;
	}
	if (audioManager != nullptr)
	{
		delete audioManager;
		audioManager = nullptr;
	}
	if (notesManager != nullptr)
	{
		delete notesManager;
		notesManager = nullptr;
	}
	if (serialManager != nullptr)
	{
		delete serialManager;
		serialManager = nullptr;
	}
	if (playerManager != nullptr)
	{
		delete playerManager;
		playerManager = nullptr;
	}
	
	System::GetInstance()->DeleteInstance();

	DxLib_End();

	std::cout << "System Finalized." << std::endl;
}

void System::Main()
{
	while (Update())
	{
		sceneManager->Update();
		effectManager->UpdateEffect();
	
		spendTime += timeManager->GetDeltaTimeMs();

		sceneManager->Draw();
		effectManager->DrawEffect();
		//DrawFormatString(0, 0, GetColor(255, 255, 255), L"%.2f", timeManager->GetFPS());
		//DrawFormatString(0, 50, GetColor(255, 255, 255), L"%.2f", spendTime / 1000.0f);
	}
}

bool System::Update()
{
	//スクリーン処理実行
	if (ScreenFlip() || ProcessMessage() || ClearDrawScreen()) return false;

	//シャットダウン要求で終了
	if (requestedShutdown) return false;

	//キーボード更新
	inputManager->GetKeyboardInput()->Update();
	//FPS制御
	timeManager->Tick();

	//音楽更新
	audioManager->Update();

	//ESCAPEで終了
	if (inputManager->GetKeyboardInput()->GetPressingCount(KEY_INPUT_ESCAPE) == 1)
	{
		RequestShutdown();
	}

	return true;
}

void System::RequestShutdown()
{
	requestedShutdown = true;
}

TimeManager* System::GetTimeManager()
{
	return timeManager;
}

InputManager* System::GetInputManager()
{
	return inputManager;
}

SceneManager* System::GetSceneManager()
{
	return sceneManager;
}

EffectManager* System::GetEffectManager()
{
	return effectManager;
}

ImageManager* System::GetImageManager()
{
	return imageManager;
}

AudioManager* System::GetAudioManager()
{
	return audioManager;
}

NotesManager* System::GetNotesManager()
{
	return notesManager;
}

SerialManager* System::GetSerialManager()
{
	return serialManager;
}

PlayerManager* System::GetPlayerManager()
{
	return playerManager;
}