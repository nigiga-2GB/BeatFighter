#pragma once

#include<iostream>
#include<string>
#include<nlohmann/json.hpp>
#include<DxLib.h>
#include<vector>
#include<algorithm>
#include "IScene.h"
#include "IEffect.h"
#include "Define.h"

class System;
class ImputManager;
class SceneManager;
class TimeManager;
class EffectManager;
class ImageManager;
class NotesManager;
class SerialManager;
class PlayerManager;
struct Note;
class Circle;
class Color;
class Vec2D;
class Vec2DF;
class ResultScene;

class BPM180 : public IScene
{
private:
	float spendTime = 0.0f;
	unsigned long cnt = 0;
	std::vector<Note> notes;
	std::vector<bool> isJudged;
	std::vector<float> hasseiTimes;
	std::vector<Vec2DF> itis;
	int judgeLine = 350;
	int realJudgeLine = 400;
	int playerX = 175;
	int playerY = 750;
	float speed = 500.0f;
	int vecItr = 0;

	JUDGE_TYPE Judge(int itr, float spendTime);
	std::vector<JUDGE_TYPE> nowJudges;

	int arPort = 8;
	char buffer[1000] = { 0 };

	int nowCombo = 0;
	int maxCombo = 0;

public:
	BPM180();
	~BPM180();

	virtual void Update() override;
	virtual void Draw() const override;
};