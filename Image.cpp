#include "Image.h"
#include "Vec2D.h"

Image::Image(const std::filesystem::path& path) : filePath(path)
{
	this->handle = LoadGraph(filePath.c_str());
}

void Image::Draw(int x, int y) const
{
	if (this->handle == -1) return;

	DrawGraph(x, y, this->handle, FALSE);
}

void Image::Draw(const Vec2D& vec) const
{
	if (this->handle == -1) return;

	DrawGraph(vec.x, vec.y, this->handle, FALSE);
}

void Image::Draw(const Vec2DF& vec) const
{
	if (this->handle == -1) return;

	DrawGraph((int)vec.x, (int)vec.y, this->handle, FALSE);
}