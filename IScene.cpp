#include "IScene.h"
#include "Vec2D.h"
#include "System.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "ImageManager.h"
#include "Easing.h"
#include "Define.h"
#include "Math.h"
#include "Circle.h"
#include "Palette.h"
#include "Color.h"


Excellent::Excellent(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Excellent::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Excellent::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("excellent", Vec2DF{ (float)Define::WIN_W / 2 - 150, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Good::Good(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Good::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Good::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("good", Vec2DF{ (float)Define::WIN_W / 2 - 100, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Bad::Bad(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Bad::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Bad::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("bad", Vec2DF{ (float)Define::WIN_W / 2 - 80, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

Miss::Miss(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool Miss::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void Miss::Draw() const
{
	float e = Easing::EaseInOutCirc(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0 * (1 - Math::Min(e, 1.0))));
	IMAGE->Draw("miss", Vec2DF{ (float)Define::WIN_W / 2 - 100, (float)Define::WIN_H / 2 - 100 * Math::Min(e, 1.0) });
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

PunchEffect::PunchEffect(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool PunchEffect::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void PunchEffect::Draw() const
{
	float e = Easing::EaseOutExpo(spendTime);
	float t = Easing::EaseOutQuart(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * (1.0f - Math::Min(t, 1.0f))));
	CircleF{ 400.f, 450.f, 110.f * Math::Min(e, 1.0) }.DrawFrame(Palette::Red, 15);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

JumpEffect::JumpEffect(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool JumpEffect::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void JumpEffect::Draw() const
{
	float e = Easing::EaseOutExpo(spendTime);
	float t = Easing::EaseOutQuart(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * (1.0f - Math::Min(t, 1.0f))));
	CircleF{ 400.f, static_cast<float>(Define::WIN_H - 100), 110.f * Math::Min(e, 1.0) }.DrawFrame(Palette::AliceBlue, 15);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

PunchHuttobi::PunchHuttobi(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool PunchHuttobi::Update()
{
	angle += 10;
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void PunchHuttobi::Draw() const
{
	float e = Easing::EaseOutExpo(spendTime);
	float t = Easing::EaseOutQuart(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * (1.0f - Math::Min(t, 1.0f))));
	//CircleF{ 400.f, static_cast<float>(Define::WIN_H - 100), 110.f * Math::Min(e, 1.0) }.DrawFrame(Palette::AliceBlue, 15);
	IMAGE->DrawRotaAdv("bird", Vec2DF{ 400.f + ((float)Define::WIN_W - 100.f) * Math::Min(t, 1.0), 450.f - 400.f * Math::Min(t, 1.0) }, Vec2DF{64.f, 64.f}, Math::ToRadian((float)angle), 1.f - Math::Min(t, 1.0), 1.f - Math::Min(t, 1.0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

NotesCfgEft::NotesCfgEft(float maxLifeTime) : IEffect(maxLifeTime)
{

}

bool NotesCfgEft::Update()
{
	spendTime += TIMER->GetDeltaTimeS();
	return spendTime <= maxLifeTime;
}

void NotesCfgEft::Draw() const
{
	float e = Easing::EaseOutExpo(spendTime);
	float t = Easing::EaseOutQuart(spendTime);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * (1.0f - Math::Min(t, 1.0f))));
	CircleF{ (float)Define::WIN_W / 2.f, (float)Define::WIN_H / 2.f, 300.f * Math::Min(e, 1.0) }.DrawFrame(Palette::Red, 15);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}