#pragma once

#include "Keyboard.h"

class InputManager
{
private:
	static Keyboard* keyboard;

public:
	InputManager();
	~InputManager();

	Keyboard* GetKeyboardInput();
};