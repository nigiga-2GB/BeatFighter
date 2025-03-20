#pragma once

#include<filesystem>
#include<iostream>
#include<DxLib.h>
#include<unordered_map>
#include<algorithm>

enum class AUDIO_STATE
{
	Playing,
	Stopping,
};

enum class PLAY_TYPE
{
	Normal = DX_PLAYTYPE_NORMAL,
	BackGround = DX_PLAYTYPE_BACK,
};

struct Audio
{
	int handle = -1;
	AUDIO_STATE state;
};

class AudioManager
{
private:
	std::unordered_map<std::string, Audio> audios;

public:
	void AddAudio(std::string key, std::filesystem::path path);
	void RemoveAudio(std::string key);

	void Play(std::string key, PLAY_TYPE playType);
	void Stop(std::string key);

	void Update();

	bool IsPlaying(std::string key);

	void SetVolume(std::string key, int volume);
	void SetVolumeF(std::string key, float volume);
};