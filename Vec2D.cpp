#include "Vec2D.h"
#include "Math.h"

Vec2D::Vec2D(int x, int y) : x(x), y(y)
{

}

Vec2D& Vec2D::operator=(const Vec2D& vec)
{
	this->x = vec.x;
	this->y = vec.y;

	return *this;
}

Vec2D& Vec2D::operator=(const Vec2DF& vec)
{
	this->x = static_cast<int>(vec.x);
	this->y = static_cast<int>(vec.y);

	return *this;
}

Vec2D& Vec2D::operator+=(const Vec2D& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

float Vec2D::Size() const
{
	return Math::Sqrt(Math::Pow(static_cast<float>(this->x), 2) * Math::Pow(static_cast<float>(this->y), 2));
}

void Vec2D::Show() const
{
	std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}

Vec2DF::Vec2DF(float x, float y) : x(x), y(y)
{

}

Vec2DF& Vec2DF::operator=(const Vec2DF& vec)
{
	this->x = vec.x;
	this->y = vec.y;

	return *this;
}

Vec2DF& Vec2DF::operator=(const Vec2D& vec)
{
	this->x = static_cast<float>(vec.x);
	this->y = static_cast<float>(vec.y);

	return *this;
}

Vec2DF& Vec2DF::operator+=(const Vec2DF& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vec2DF& Vec2DF::operator-=(const Vec2DF& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

float Vec2DF::Size() const
{
	return Math::Sqrt(Math::Pow(this->x, 2) * Math::Pow(this->y, 2));
}

void Vec2DF::Show() const
{
	std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}