#pragma once
#include "IScene.h"
#include <nlohmann/json.hpp>
#include <DxLib.h>
#include <iostream>
#include <string>
#include "Color.h"
#include "Palette.h"
#include "Define.h"
#include "Math.h"

class System;
class ImageManager;
class InputManager;
class SceneManager;
class AudioManager;
class SerialManager;
class Keyboard;
class Vec2D;
class TitleScene;
class SelectScene;

class ResultScene : public IScene
{
private:
	int exceCnt = 0;
	int goodCnt = 0;
	int badCnt = 0;
	int missCnt = 0;
	int notesCnt = 0;

	int maxCombo = 0;

	std::string previousScene;

	float pointPerNote = 0.0f;
	const float MAX_POINT = 100;
	const float exceRate = 1.0f;
	const float goodRate = 0.8f;
	const float badRate = 0.5f;
	const float missRate = 0.0f;

	float result = 0.0f;

	int port = 8;
	char buffer[1] = { 0 };

	std::string GetNumberN(int num, int n) const
	{
		int result = (int)((num / (int)Math::Pow(10, (float)(n - 1))) % 10);

		std::stringstream ssResult;
		ssResult << result;

		return ssResult.str();
	}

	std::string GetNumberN(float num, int n) const
	{
		
		int result = (int)(num / (int)Math::Pow(10, (float)(n - 1))) % 10;

		std::stringstream ssResult;
		ssResult << result;
		
		return ssResult.str();
	}

public:
	ResultScene();
	~ResultScene();

	virtual void Update() override;
	virtual void Draw() const override;
};

