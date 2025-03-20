#pragma once

#include "IScene.h"
#include <nlohmann/json.hpp>
#include <string>

class System;
class AudioManager;
class SceneManager;
class InputManager;
class Keyboard;
class TitleScene;

class MusicRoom : public IScene
{
private:
	unsigned int nowCursor = 0;
	unsigned int nowSelect = 0;

public:
	MusicRoom();
	~MusicRoom();

	virtual void Update() override;
	virtual void Draw() const override;
};

