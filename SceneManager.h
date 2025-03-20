#pragma once

#include<memory>
#include<unordered_map>
#include<iostream>
#include<nlohmann/json.hpp>
#include "IScene.h"

class SceneManager
{
private:
	std::unordered_map<size_t, std::shared_ptr<IScene>> mScenes;
	std::shared_ptr<IScene> nowScene;

	template<typename Scene>
	bool CheckIsScene()
	{
		bool result = std::is_base_of<IScene, Scene>::value;
		if (!result)
		{
			std::cout << "ƒV[ƒ“ˆÈŠO‚ª“n‚³‚ê‚Ü‚µ‚½" << std::endl;
			return false;
		}

		return true;
	}

public:
	SceneManager()
	{
		nowScene = std::make_shared<IScene>();
	}
	~SceneManager()
	{
		for (auto itr = mScenes.begin(); itr != mScenes.end();)
		{
			itr->second.reset();
			itr = mScenes.erase(itr);
		}
	}

	template<typename Scene>
	void AddScene()
	{
		if (!CheckIsScene<Scene>()) return;

		std::shared_ptr<Scene> sScene = std::make_shared<Scene>();
		if (!sScene)
		{
			std::cout << "Null Scene" << std::endl;
			return;
		}

		mScenes[typeid(Scene).hash_code()] = sScene;
		if (!nowScene)
		{
			nlohmann::json first;
			ChangeScene<Scene>(first);
		}
	}

	template<typename Scene>
	void RemoveScene()
	{
		if (!CheckIsScene<Scene>()) return;

		auto itr = mScenes.find(typeid(Scene).hash_code());
		if (itr == mScenes.end()) return;

		(*itr).second.reset();
		mScenes.erase(itr);
	}

	template<typename NowScene, typename NextScene>
	void ChangeScene(const nlohmann::json& param, bool resetNowScene = false)
	{
		if (!CheckIsScene<NextScene>()) return;

		if (resetNowScene)
		{
			RemoveScene<NowScene>();
			AddScene<NowScene>();
		}

		auto& sScene = mScenes[typeid(NextScene).hash_code()];
		if (sScene)
		{
			sScene->SetParam(param);
			nowScene = sScene;
			std::cout << "Scene: " << typeid(NextScene).name() << std::endl;
		}
	}

	template<typename Scene>
	void ChangeScene(const nlohmann::json& param)
	{
		if (!CheckIsScene<Scene>()) return;

		auto& sScene = mScenes[typeid(Scene).hash_code()];
		if (sScene)
		{
			sScene->SetParam(param);
			nowScene = sScene;
			std::cout << "Scene: " << typeid(Scene).name() << std::endl;
		}
	}

	void Update();
	void Draw();
};