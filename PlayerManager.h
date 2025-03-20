#pragma once

#include <memory>
#include <iostream>

class System;
class ImageManager;
class TimeManager;
class Vec2D;
class Circle;
class CircleF;
class Color;

enum class PlayerAction
{
	Jumping,
	Punching,
	Non,
};

class ICommand
{
protected:
	float spendTime = 0.0f;
	float finishTime;

	const float playerX = 180;
	const float playerY = 500;

public:
	ICommand(float finishTime = 0.0f) : finishTime(finishTime){}
	virtual ~ICommand() = default;

	virtual bool Exec() { return true; }
	virtual void Draw() const{}
};

class JumpCommand : public ICommand
{
public:
	JumpCommand(float finishTime) : ICommand(finishTime){}

	virtual bool Exec() override;
	virtual void Draw() const override;
};

class PunchCommand : public ICommand
{
public:
	PunchCommand(float finishTime) : ICommand(finishTime){}

	virtual bool Exec() override;
	virtual void Draw() const override;
};

class NonCommand : public ICommand
{
public:
	NonCommand(float finishTime) : ICommand(finishTime) {}

	virtual bool Exec() override;
	virtual void Draw() const override;
};

class PlayerManager
{
private:
	PlayerAction nowAction = PlayerAction::Non;
	
	int frame = 0;
	int spriteCnt = 1;

	ICommand* nowCommand{ nullptr };

public:
	PlayerManager();
	~PlayerManager();

	void Jump(float finishTime = 0.0f);
	void Punch(float finishTime = 0.0f);
	void Update();
	void Draw() const;
};