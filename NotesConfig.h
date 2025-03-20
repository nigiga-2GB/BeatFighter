#pragma once

#include<iostream>
#include<nlohmann/json.hpp>
#include<DxLib.h>
#include<queue>
#include<string>
#include<fstream>
#include<filesystem>
#include "IScene.h"
#include "IEffect.h"
#include "Define.h"

class System;
class InputManager;
class SceneManager;
class TimeManager;
class EffectManager;
class ImageManager;
class SerialManager;
class Circle;
class Color;
class Vec2D;
class Vec2DF;
class SelectScene;

class NotesConfig : public IScene
{
private:
	int arPort = 8;
	char buffer[1000] = { 0 };

	//経過時間
	float spendTime = 0.0f;

	//平均値用配列
	std::queue<float> times;

	//開始前エフェクトフラグ
	bool effectFlag = false;

	//計測開始フラグ
	bool startFlag = false;
	//計測用カウンタ
	unsigned int cnt = 0;

	//平均計算
	float CalcAve();

	//設定ファイルのパス
	std::filesystem::path cfgPath = "NotesConfig/NotesConfig.txt";

public:
	NotesConfig();
	~NotesConfig();

	virtual void Update() override;
	virtual void Draw() const override;
};