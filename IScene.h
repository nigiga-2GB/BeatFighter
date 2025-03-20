#pragma once

#include "Parameter.h"
#include "IEffect.h"
#include<nlohmann/json.hpp>

class System;
class TimeManager;
class EffectManager;
class ImageManager;
class Circle;

class Excellent : public IEffect
{
public:
	Excellent(float maxLifeTime);
	virtual ~Excellent() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class Good : public IEffect
{
public:
	Good(float maxLifeTime);
	virtual ~Good() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class Bad : public IEffect
{
public:
	Bad(float maxLifeTime);
	virtual ~Bad() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class Miss : public IEffect
{
public:
	Miss(float maxLifeTime);
	virtual ~Miss() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class PunchEffect : public IEffect
{
public:
	PunchEffect(float maxLifeTime);
	virtual ~PunchEffect() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class JumpEffect : public IEffect
{
public:
	JumpEffect(float maxLifeTime);
	virtual ~JumpEffect() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class PunchHuttobi : public IEffect
{
private:
	unsigned int angle = 0;

public:
	PunchHuttobi(float maxLifeTime);
	virtual ~PunchHuttobi() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

class NotesCfgEft : public IEffect
{
public:
	NotesCfgEft(float maxLifeTime);
	virtual ~NotesCfgEft() = default;

	virtual bool Update() override;
	virtual void Draw() const override;
};

enum class JUDGE_TYPE
{
	Excellent,
	Good,
	Bad,
	Miss,
	Non,
};

class IScene
{
protected:
	//Parameter param;
	nlohmann::json param;

public:
	virtual ~IScene() = default;

	virtual void Update(){}
	virtual void Draw() const{}

	virtual void SetParam(const nlohmann::json& param) final
	{
		this->param = param;
	}
};

