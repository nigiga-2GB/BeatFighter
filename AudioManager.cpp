#include "AudioManager.h"

void AudioManager::AddAudio(std::string key, std::filesystem::path path)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "音楽パスが不正です" << std::endl;
		std::cout << path << std::endl;
	}

	int handle = LoadSoundMem(path.c_str());
	if (handle == -1) return;

	audios[key] = Audio{ .handle = handle, .state = AUDIO_STATE::Stopping };
}

void AudioManager::RemoveAudio(std::string key)
{
	auto itr = audios.find(key);
	if (itr == audios.end()) return;

	if (audios[key].state == AUDIO_STATE::Playing) Stop(key);

	DeleteSoundMem(itr->second.handle);
	audios.erase(itr);
}

void AudioManager::Play(std::string key, PLAY_TYPE playType)
{
	if (CheckSoundMem(audios[key].handle) == 1 && audios[key].state == AUDIO_STATE::Playing) return;

	PlaySoundMem(audios[key].handle, (int)playType);
	audios[key].state = AUDIO_STATE::Playing;
}

void AudioManager::Stop(std::string key)
{
	if (CheckSoundMem(audios[key].handle) == 0 && audios[key].state == AUDIO_STATE::Stopping) return;

	StopSoundMem(audios[key].handle);
	audios[key].state = AUDIO_STATE::Stopping;
}

void AudioManager::SetVolume(std::string key, int volume)
{
	auto itr = audios.find(key);
	if (itr == audios.end()) return;

	volume = std::clamp<int>(volume, 0, 255);

	ChangeVolumeSoundMem(volume, audios[key].handle);
}

void AudioManager::SetVolumeF(std::string key, float volume)
{
	auto itr = audios.find(key);
	if (itr == audios.end()) return;

	volume = std::clamp<float>(volume, 0.0, 1.0);

	ChangeVolumeSoundMem(255 * volume, audios[key].handle);
}

bool AudioManager::IsPlaying(std::string key)
{
	return audios[key].state == AUDIO_STATE::Playing;
}

void AudioManager::Update()
{
	for (auto& audio : audios)
	{
		if (CheckSoundMem(audio.second.handle) == 0)
		{
			audio.second.state = AUDIO_STATE::Stopping;
		}
	}
}