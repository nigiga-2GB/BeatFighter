#pragma once

#include<iostream>

namespace Math{}

class Vec2DF;

class Vec2D
{
public:
	int x, y;

	Vec2D(int x = 0, int y = 0);
	Vec2D& operator=(const Vec2D& vec);
	~Vec2D() = default;

	Vec2D& operator=(const Vec2DF& vec);
	Vec2D& operator+=(const Vec2D& vec);
	Vec2D& operator-=(const Vec2D& vec);

	float Size() const;

	void Show() const;
};

class Vec2DF
{
public:
	float x, y;

	Vec2DF(float x = 0, float y = 0);
	~Vec2DF() = default;

	Vec2DF& operator=(const Vec2DF& vec);
	Vec2DF& operator=(const Vec2D& vec);
	Vec2DF& operator+=(const Vec2DF& vec);
	Vec2DF& operator-=(const Vec2DF& vec);

	float Size() const;

	void Show() const;
};

static int DotI(const Vec2D& v1, const Vec2D& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

static float DotF(const Vec2DF& v1, const Vec2DF& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}