#pragma once

#include<filesystem>
#include<DxLib.h>
#include<iostream>

class Vec2D;
class Vec2DF;

class Image
{
private:
	std::filesystem::path filePath;
	int handle = -1;

public:
	Image(const std::filesystem::path& path = "");
	~Image()
	{
		if (this->handle != -1)
		{
			if (DeleteGraph(this->handle) == -1)
			{
				std::cout << "handle reseted" << std::endl;
			}
		}
	}

	void Draw(int x = 0, int y = 0) const;
	void Draw(const Vec2D& vec) const;
	void Draw(const Vec2DF& vec) const;
};