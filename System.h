#pragma once

#include<DxLib.h>
#include<memory>
#include<iostream>
#include<string>
#include<nlohmann/json.hpp>
#include "Parameter.h"

class TimeManager;
class InputManager;
class Keyboard;
class SceneManager;
class EffectManager;
class ImageManager;
class NotesManager;
class AudioManager;
class SerialManager;
class PlayerManager;
/*
class TestScene;
class TestScene2;
*/
class TitleScene;
class SelectScene;
class BPM180;
class HaikaiScene;
class NEXTScene;
class ResultScene;
class MusicRoom;
class Museum;
class NotesConfig;

class System
{
private:
	static TimeManager* timeManager;
	static InputManager* inputManager;
	static SceneManager* sceneManager;
	static EffectManager* effectManager;
	static ImageManager* imageManager;
	static AudioManager* audioManager;
	static NotesManager* notesManager;
	static SerialManager* serialManager;
	static PlayerManager* playerManager;
	float spendTime = 0.0f;

	bool requestedShutdown = false;

	int h8Port = 3;
	int arPort = 8;

protected:
	static System* pInstance;
	System(){}

public:
	System(const System& other) = delete;
	void operator=(const System& other) = delete;

	static System* GetInstance();

	static void DeleteInstance();

	bool Initialize() const;

	void Finalize() const;

	void Main();

	bool Update();

	void RequestShutdown();

	static TimeManager* GetTimeManager();
	static InputManager* GetInputManager();
	static SceneManager* GetSceneManager();
	static EffectManager* GetEffectManager();
	static ImageManager* GetImageManager();
	static AudioManager* GetAudioManager();
	static NotesManager* GetNotesManager();
	static SerialManager* GetSerialManager();
	static PlayerManager* GetPlayerManager();
};

#define SYSTEM System::GetInstance()
#define TIMER System::GetInstance()->GetTimeManager()
#define INPUT System::GetInstance()->GetInputManager()
#define KEYBOARD System::GetInstance()->GetInputManager()->GetKeyboardInput()
#define SCENE System::GetInstance()->GetSceneManager()
#define EFFECT System::GetInstance()->GetEffectManager()
#define IMAGE System::GetInstance()->GetImageManager()
#define AUDIO System::GetInstance()->GetAudioManager()
#define NOTES System::GetInstance()->GetNotesManager()
#define SERIAL System::GetInstance()->GetSerialManager()
#define PLAYER System::GetInstance()->GetPlayerManager()