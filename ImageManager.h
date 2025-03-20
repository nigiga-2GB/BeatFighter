#pragma once

#include<filesystem>
#include<DxLib.h>
#include<unordered_map>

class Vec2D;
class Vec2DF;

class ImageManager
{
private:
	std::unordered_map<std::string, int> images;

public:
	void AddImage(std::string key, std::filesystem::path path);

	void RemoveImage(std::string key);

	void Draw(std::string key, const Vec2D& vec);
	void DrawRota(std::string key, const Vec2D& vec, const Vec2D& center, float deg = 0.0);
	void DrawRotaAdv(std::string key, const Vec2D& vec, const Vec2D& center, float deg = 0.0, float exRateX = 1.0f, float exRateY = 1.0f);

	void Draw(std::string key, const Vec2DF& vec);
	void DrawRota(std::string key, const Vec2DF& vec, const Vec2DF& center, float deg = 0.0);
	void DrawRotaAdv(std::string key, const Vec2DF& vec, const Vec2DF& center, float deg = 0.0, float exRateX = 1.0f, float exRateY = 1.0f);
};