#pragma once

#include<iostream>
#include<nlohmann/json.hpp>
#include<DxLib.h>
#include<vector>
#include "IScene.h"
#include "IEffect.h"
#include "Define.h"

/*
class System;
class InputManager;
class SceneManager;
class TimeManager;
class EffectManager;
class ImageManager;
class AudioManager;
class NotesManager;
struct Note;
class TestScene2;
class Circle;
class Color;
class Vec2D;
class Vec2DF;
//class Image;

class PunchEffect1 : public IEffect
{
public:
	//EEffect() = default;
	PunchEffect1(float maxLifeTime);
	virtual ~PunchEffect1() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class JumpEffect2 : public IEffect
{
public:
	JumpEffect2(float maxLifeTime);
	virtual ~JumpEffect2() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class NonEffect0 : public IEffect
{
public:
	NonEffect0(float maxLifeTime);
	virtual ~NonEffect0() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class Excellent : public IEffect
{
public:
	Excellent(float maxLifeTime);
	virtual ~Excellent() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class Good : public IEffect
{
public:
	Good(float maxLifeTime);
	virtual ~Good() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class Bad : public IEffect
{
public:
	Bad(float maxLifeTime);
	virtual ~Bad() = default;
	
	virtual bool Update() override;
	virtual void Draw() const override;
};

class Miss : public IEffect
{
public:
	Miss(float maxLifeTime);
	virtual ~Miss() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

enum class JUDGE_TYPE
{
	Excellent,
	Good,
	Bad,
	Miss,
	Non,
};

class TestScene : public IScene
{
private:
	float spendTime = 0.0;
	unsigned long cnt = 0;
	std::vector<Note> notes;
	std::vector<bool> isJudged;
	std::vector<float> hasseiTimes;
	std::vector<Vec2DF> itis;
	int judgeLine = 220;
	int realJudgeLine = 270;
	int playerX = 175;
	int playerY = 750;
	float speed = 500.0f;
	int vecItr = 0;

	JUDGE_TYPE Judge(int itr, float spendTime);
	std::vector<JUDGE_TYPE> nowJudges;
	
public:
	TestScene();
	~TestScene();

	virtual void Update() override;

	virtual void Draw() const override;
};
*/