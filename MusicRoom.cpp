#include "MusicRoom.h"
#include "System.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "TitleScene.h"

MusicRoom::MusicRoom()
{

}

MusicRoom::~MusicRoom()
{

}

void MusicRoom::Update()
{
	if (KEYBOARD->GetPressingCount(KEY_INPUT_J) == 1) nowCursor++;
	nowSelect = nowCursor % 3;

	if (KEYBOARD->GetPressingCount(KEY_INPUT_LSHIFT) == 1)
	{
		if (nowSelect == 0 && AUDIO->IsPlaying("sound_bpm180")) AUDIO->Stop("sound_bpm180");
		if (nowSelect == 1 && AUDIO->IsPlaying("sound_haikai")) AUDIO->Stop("sound_haikai");
		if (nowSelect == 2 && AUDIO->IsPlaying("sound_next")) AUDIO->Stop("sound_next");

		nlohmann::json iii;
		SCENE->ChangeScene<MusicRoom, TitleScene>(iii, true);
	}

	if (nowSelect == 0)
	{
		if (AUDIO->IsPlaying("sound_haikai")) AUDIO->Stop("sound_haikai");
		if (AUDIO->IsPlaying("sound_next")) AUDIO->Stop("sound_next");

		if (!AUDIO->IsPlaying("sound_bpm180")) AUDIO->Play("sound_bpm180", PLAY_TYPE::BackGround);
	}
	else if (nowSelect == 1)
	{
		if (AUDIO->IsPlaying("sound_bpm180")) AUDIO->Stop("sound_bpm180");
		if (AUDIO->IsPlaying("sound_next")) AUDIO->Stop("sound_next");

		if (!AUDIO->IsPlaying("sound_haikai")) AUDIO->Play("sound_haikai", PLAY_TYPE::BackGround);
	}
	else if (nowSelect == 2)
	{
		if (AUDIO->IsPlaying("sound_haikai")) AUDIO->Stop("sound_haikai");
		if (AUDIO->IsPlaying("sound_bpm180")) AUDIO->Stop("sound_bpm180");

		if (!AUDIO->IsPlaying("sound_next")) AUDIO->Play("sound_next", PLAY_TYPE::BackGround);
	}
}

void MusicRoom::Draw() const
{
	SetFontSize(40);
	DrawString(0, 0, L"ここは MusicRoom です\n\nJで曲選択\n左シフトでタイトルに戻る", Palette::White.Get());

	SetFontSize(60);
	if (nowSelect == 0)
	{
		DrawString(Define::WIN_W / 2 - 100, Define::WIN_H / 2, L"BPM180", Palette::White.Get());
	}
	if (nowSelect == 1)
	{
		DrawString(Define::WIN_W / 2 - 50, Define::WIN_H / 2, L"徘徊", Palette::White.Get());
	}
	if (nowSelect == 2)
	{
		DrawString(Define::WIN_W / 2 - 50, Define::WIN_H / 2, L"次へ", Palette::White.Get());
	}
}