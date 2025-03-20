#include "EffectManager.h"
#include "IEffect.h"

void EffectManager::UpdateEffect()
{
	auto itr = effects.begin();
	for (itr; itr != effects.end();)
	{
		if (*itr && !((*itr)->Update()))
		{
			delete *itr;
			*itr = nullptr;
			if (*itr != nullptr) std::cout << "memory leaked" << std::endl;
			itr = effects.erase(itr);
			//std::cout << "effect reseted" << std::endl;
			//std::cout << "after size: " << effects.size() << std::endl;
		}
		else itr++;
	}
}

void EffectManager::DrawEffect() const
{
	auto itr = effects.begin();
	for (itr; itr != effects.end(); itr++)
	{
		if (*itr)
		{
			(*itr)->Draw();
		}
	}
}