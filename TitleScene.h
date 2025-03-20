#pragma once

#include <DxLib.h>
#include <nlohmann/json.hpp>
#include "IScene.h"
#include "IEffect.h"
#include "Define.h"
#include "Color.h"
#include "Palette.h"

class System;
class InputManager;
class Keyboard;
class SceneManager;
class ImageManager;
class AudioManager;
class TimeManager;
class SerialManager;
class SelectScene;
class MusicRoom;
class Museum;

class TitleScene : public IScene
{
private:
	int port = 3;
	//int port = 8;
	char buffer[100] = { 0 };
	char buffer_2[1000] = { 0 };

	float spendTime = 0.0f;

	bool isAppeared = false;
	bool isFirst = true;

	unsigned int r = 0;

public:
	TitleScene();
	~TitleScene();

	virtual void Update() override;
	virtual void Draw() const override;
};

