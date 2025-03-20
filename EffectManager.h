#pragma once

#include<list>
#include<DxLib.h>
#include<iostream>
#include<memory>

class IEffect;

class EffectManager
{
private:
	std::list<IEffect*> effects;

	template<typename Effect>
	bool CheckIsEffect()
	{
		bool result = std::is_base_of<IEffect, Effect>::value;
		if (!result)
		{
			std::cout << "エフェクト以外が指定されました" << std::endl;
			return false;
		}

		return true;
	}

public:
	EffectManager() = default;
	~EffectManager() = default;

	template<typename Effect>
	void AddEffect(float lifeTime)
	{
		if (!CheckIsEffect<Effect>()) return;
		Effect* effect = new Effect(lifeTime);
		if (!effect) return;

		effects.push_back(effect);
		if (effects.size() > 0)
		{
			std::cout << "effect added: " << typeid(Effect).name() << std::endl;
		}
	}

	void UpdateEffect();

	void DrawEffect() const;
};