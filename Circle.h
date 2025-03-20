#pragma once

#include<DxLib.h>

class Color;
class ColorF;

class Circle
{
public:
	int x, y, r;

	Circle(int x = 0, int y = 0, int r = 0);

	void Draw(const Color& color) const;
	void Draw(const ColorF& color) const;

	void DrawFrame(const Color& color, int width = 1) const;
	void DrawFrame(const ColorF& color, int width = 1) const;
};

class CircleF
{
public:
	float x, y, r;

	CircleF(float x = 0.0, float y = 0.0, float r = 0.0);

	void Draw(const Color& color) const;
	void Draw(const ColorF& color) const;

	void DrawFrame(const Color& color, int width = 1) const;
	void DrawFrame(const ColorF& color, int width = 1) const;
};