#pragma once

#include<DxLib.h>
#include<algorithm>

class ColorF;

class Color
{
public:
	int r, g, b;

	Color(int r = 0, int g = 0, int b = 0);
	~Color() = default;

	unsigned int Get() const;
};

class ColorF
{
public:
	float r, g, b;

	ColorF(float r = 0, float g = 0, float b = 0);
	~ColorF() = default;

	unsigned int Get() const;
};