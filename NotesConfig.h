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

	//�o�ߎ���
	float spendTime = 0.0f;

	//���ϒl�p�z��
	std::queue<float> times;

	//�J�n�O�G�t�F�N�g�t���O
	bool effectFlag = false;

	//�v���J�n�t���O
	bool startFlag = false;
	//�v���p�J�E���^
	unsigned int cnt = 0;

	//���όv�Z
	float CalcAve();

	//�ݒ�t�@�C���̃p�X
	std::filesystem::path cfgPath = "NotesConfig/NotesConfig.txt";

public:
	NotesConfig();
	~NotesConfig();

	virtual void Update() override;
	virtual void Draw() const override;
};