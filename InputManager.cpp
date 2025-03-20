#include "InputManager.h"

Keyboard* InputManager::keyboard = nullptr;

InputManager::InputManager()
{
	keyboard = new Keyboard();
}

InputManager::~InputManager()
{
	delete keyboard;
	keyboard = nullptr;
}

Keyboard* InputManager::GetKeyboardInput()
{
	return keyboard;
}