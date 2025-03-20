#include "Museum.h"
#include "System.h"
#include "ImageManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Keyboard.h"
#include "TitleScene.h"
#include "Vec2D.h"


Museum::Museum()
{

}

Museum::~Museum()
{

}

void Museum::Update()
{
	if (KEYBOARD->GetPressingCount(KEY_INPUT_J) == 1) nowCursor++;
	nowSelect = nowCursor % 6;

	if (KEYBOARD->GetPressingCount(KEY_INPUT_LSHIFT) == 1)
	{
		nlohmann::json iii;
		SCENE->ChangeScene<Museum, TitleScene>(iii, true);
	}
}

void Museum::Draw() const
{
	SetFontSize(40);
	DrawString(0, 0, L"‚±‚±‚Í Museum ‚Å‚·\n\nJ‚ÅŠG‚Ì‘I‘ğ\n¶ƒVƒtƒg‚Åƒ^ƒCƒgƒ‹‚É–ß‚é", Palette::White.Get());

	SetFontSize(60);
	if (nowSelect == 0)
	{
		IMAGE->DrawRotaAdv("sunny", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 640.f, 380.f }, 0.0f, 0.4f, 0.4f);
		DrawString(Define::WIN_W / 2 - 150, Define::WIN_H / 2 + 200, L"BPM180”wŒi", Palette::White.Get());
	}
	else if (nowSelect == 1)
	{
		IMAGE->DrawRotaAdv("forest", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 640.f, 380.f }, 0.0f, 0.4f, 0.4f);
		DrawString(Define::WIN_W / 2 - 100, Define::WIN_H / 2 + 200, L"œpœj”wŒi", Palette::White.Get());
	}
	else if (nowSelect == 2)
	{
		IMAGE->DrawRotaAdv("sunset", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 640.f, 380.f }, 0.0f, 0.4f, 0.4f);
		DrawString(Define::WIN_W / 2 - 100, Define::WIN_H / 2 + 200, L"Ÿ‚Ö”wŒi", Palette::White.Get());
	}
	else if (nowSelect == 3)
	{
		IMAGE->DrawRotaAdv("bird", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 64.f, 64.f }, 0.0f, 2.0f, 2.0f);
		DrawString(Define::WIN_W / 2 - 10, Define::WIN_H / 2 + 200, L"’¹", Palette::White.Get());
	}
	else if (nowSelect == 4)
	{
		IMAGE->DrawRotaAdv("rock", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 64.f, 64.f }, 0.0f, 2.0f, 2.0f);
		DrawString(Define::WIN_W / 2 - 10, Define::WIN_H / 2 + 200, L"Šâ", Palette::White.Get());
	}
	else if (nowSelect == 5)
	{
		IMAGE->DrawRotaAdv("chara_1", Vec2DF{ (float)Define::WIN_W / 2.0f, (float)Define::WIN_H / 2.0f }, Vec2DF{ 512.f, 512.f }, 0.0f, 0.4f, 0.4f);
		DrawString(Define::WIN_W / 2 - 75, Define::WIN_H / 2 + 200, L"ålŒö", Palette::White.Get());
	}
}