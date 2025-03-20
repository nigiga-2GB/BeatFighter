#include "PlayerManager.h"
#include "System.h"
#include "ImageManager.h"
#include "TimeManager.h"
#include "Vec2D.h"
#include "Circle.h"
#include "Color.h"
#include "Palette.h"
#include "Math.h"

bool JumpCommand::Exec()
{
	spendTime += TIMER->GetDeltaTimeS();

	return spendTime <= finishTime;
}

void JumpCommand::Draw() const
{
	Vec2DF drawPos = Vec2DF(playerX, playerY - 100.0f * Math::Sin((spendTime / finishTime) * Math::PI));

	//IMAGE->DrawRotaAdv("chara_jump_1", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
	IMAGE->DrawRotaAdv("chara_jump_1", drawPos, Vec2DF{ 512.f, 512.f }, 0.0f, 0.4f, 0.4f);
}

bool PunchCommand::Exec()
{
	spendTime += TIMER->GetDeltaTimeS();

	return spendTime <= finishTime;
}

void PunchCommand::Draw() const
{
	Vec2DF drawPos = Vec2DF(playerX - 100.f + 20.0f * Math::Sin((spendTime / finishTime) * Math::PI), playerY - 100.f);

	//CircleF{ drawPos.x, drawPos.y, 100 }.Draw(Palette::Red);
	//Circle{ 80, 300, 30 }.Draw(Palette::Red);
	IMAGE->DrawRotaAdv("chara_punch_1", drawPos, Vec2DF{ 512.f, 512.f }, 0.0f, 0.20f, 0.20f);
}

bool NonCommand::Exec()
{
	/*
	spendTime += TIMER->GetDeltaTimeS();

	return finishTime <= spendTime;
	*/
	return false;
}

void NonCommand::Draw() const
{
	Vec2D drawPos = Vec2D(playerX + 20 * Math::Sin(Math::ToRadian(spendTime / finishTime) * Math::PI), playerY);

	//Circle{ 300, 80, 30 }.Draw(Palette::Black);
	IMAGE->DrawRotaAdv("chara_1", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
}

PlayerManager::PlayerManager()
{
	nowCommand = new NonCommand(0.0f);
}

PlayerManager::~PlayerManager()
{
	if (nowCommand != nullptr)
	{
		delete nowCommand;
		nowCommand = nullptr;
	}
}

void PlayerManager::Jump(float finishTime)
{
	nowAction = PlayerAction::Jumping;
	delete nowCommand;
	nowCommand = nullptr;

	nowCommand = new JumpCommand(finishTime);
	//if (nowCommand == nullptr) std::cout << "jump‚ÌŽžnull‚¾‚Á‚½‚æ" << std::endl;
}

void PlayerManager::Punch(float finishTime)
{
	nowAction = PlayerAction::Punching;
	delete nowCommand;
	nowCommand = nullptr;

	nowCommand = new PunchCommand(finishTime);
	//if (nowCommand == nullptr) std::cout << "punch‚ÌŽžnull‚¾‚Á‚½‚æ" << std::endl;
}

void PlayerManager::Update()
{
	frame++;
	//std::cout << "player update" << std::endl;
	//if(nowCmd == PlayerManager::Jump)
	if (nowCommand != nullptr)
	{
		//std::cout << "now Command: " << typeid(nowCommand).name() << std::endl;
		if (!nowCommand->Exec())
		{
			//std::cout << "exec‚ªfalse" << std::endl;
			delete nowCommand;
			nowCommand = nullptr;

			//std::cout << typeid(nowCommand).name() << " is reseted" << std::endl;
		}
	}

	if (frame % 10 == 0)
	{
		spriteCnt++;
		if (spriteCnt == 9) spriteCnt = 1;
	}

	if (frame == 1000) frame = 0;
}

void PlayerManager::Draw() const
{
	if (nowCommand == nullptr)
	{
		//std::cout << "nowCommand == nullptr" << std::endl;
		//Circle{ 80, 300, 30 }.Draw(Palette::Black);
		if (spriteCnt == 1)
			IMAGE->DrawRotaAdv("chara_1", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if (spriteCnt == 2)
			IMAGE->DrawRotaAdv("chara_4", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if(spriteCnt == 3)
			IMAGE->DrawRotaAdv("chara_5", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if (spriteCnt == 4)
			IMAGE->DrawRotaAdv("chara_3", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if (spriteCnt == 5)
			IMAGE->DrawRotaAdv("chara_2", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if (spriteCnt == 6)
			IMAGE->DrawRotaAdv("chara_3", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if (spriteCnt == 7)
			IMAGE->DrawRotaAdv("chara_5", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
		else if (spriteCnt == 8)
			IMAGE->DrawRotaAdv("chara_4", Vec2D{ 180, 500 }, Vec2D{ 512, 512 }, 0.0f, 0.40f, 0.40f);
	}
	else if(nowCommand != nullptr)
	{
		//std::cout << "nowCommand != nullptr" << std::endl;
		nowCommand->Draw();
	}
}