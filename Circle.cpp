#include "Circle.h"
#include "Color.h"

Circle::Circle(int x, int y, int r) : x(x), y(y), r(r)
{

}

void Circle::Draw(const Color& color) const
{
	DrawCircle(x, y, r, color.Get());
}

void Circle::Draw(const ColorF& color) const
{
	DrawCircle(x, y, r, color.Get());
}

void Circle::DrawFrame(const Color& color, int width) const
{
	//DrawCircle(x, y, r, color.Get(), FALSE);
	for (int i = 0; i < width; i++)
	{
		DrawCircle(x, y, r + i, color.Get(), FALSE);
	}
}

void Circle::DrawFrame(const ColorF& color, int width) const
{
	//DrawCircle(x, y, r, color.Get(), FALSE);
	for (int i = 0; i < width; i++)
	{
		DrawCircle(x, y, r + i, color.Get(), FALSE);
	}
}

CircleF::CircleF(float x, float y, float r) : x(x), y(y), r(r)
{

}

void CircleF::Draw(const Color& color) const
{
	DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r), color.Get());
}

void CircleF::Draw(const ColorF& color) const
{
	DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r), color.Get());
}

void CircleF::DrawFrame(const Color& color, int width) const
{
	//DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r), color.Get(), FALSE);
	for (int i = 0; i < width; i++)
	{
		DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r + i), color.Get(), FALSE);
	}
}

void CircleF::DrawFrame(const ColorF& color, int width) const
{
	//DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r), color.Get(), FALSE);
	for (int i = 0; i < width; i++)
	{
		DrawCircle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(r + i), color.Get(), FALSE);
	}
}