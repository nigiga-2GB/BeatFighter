#include "Color.h"

Color::Color(int r, int g, int b) : r(r), g(g), b(b)
{

}

unsigned int Color::Get() const
{
	return GetColor(this->r, this->g, this->b);
}

ColorF::ColorF(float r, float g, float b) : r(r), g(g), b(b)
{
	r = static_cast<float>(std::clamp<float>(r, 0.0, 1.0));
	g = static_cast<float>(std::clamp<float>(g, 0.0, 1.0));
	b = static_cast<float>(std::clamp<float>(b, 0.0, 1.0));
}

unsigned int ColorF::Get() const
{
	return GetColor(static_cast<int>(255 * r), static_cast<int>(255 * g), static_cast<int>(255 * b));
}