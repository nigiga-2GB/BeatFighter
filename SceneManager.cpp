#include "SceneManager.h"

void SceneManager::Update()
{
	nowScene->Update();
}

void SceneManager::Draw()
{
	nowScene->Draw();
}