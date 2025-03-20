#pragma once

class IEffect
{
protected:
	float spendTime;
	float maxLifeTime;

public:
	IEffect(float maxLifeTime = 0.0f);

	virtual ~IEffect() = default;
	virtual bool Update() = 0;
	virtual void Draw() const = 0;
};