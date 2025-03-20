#pragma once

#include <DxLib.h>
#include <string>
#include "IScene.h"
#include "IEffect.h"
#include "Define.h"
#include "Color.h"
#include "Palette.h"
#include "Math.h"
#include "Vec2D.h"
#include "Circle.h"


class System;
class InputManager;
class ImageManager;
class SerialManager;
class SceneManager;
class AudioManager;
class Keyboard;
class TimeManager;
class BPM180;
class HaikaiScene;
class NEXTScene;
class NotesConfig;

class SelectScene : public IScene
{
private:
	Vec2D BPM;
	Vec2D HAIKAI;
	Vec2D NEXT;
	Vec2D nowSelect;

	float spendTime = 0.0f;
	int selectCnt = 0;

	int port = 8;
	char buffer[1000] = { 0 };

	unsigned int frame = 0;
	int volume = 0;
	float spendSoundTime = 0.0;

	std::string SelectImg(int id) const;

public:
	SelectScene();
	~SelectScene();

	virtual void Update() override;
	virtual void Draw() const override;
};