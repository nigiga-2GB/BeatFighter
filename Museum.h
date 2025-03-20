#pragma once
#include "IScene.h"

class System;
class ImageManager;
class SceneManager;
class InputManager;
class Keyboard;
class TitleScene;
class Vec2DF;

class Museum : public IScene
{
private:
	unsigned int nowCursor = 0;
	unsigned int nowSelect = 0;

public:
	Museum();
	~Museum();

	virtual void Update() override;
	virtual void Draw() const override;
};