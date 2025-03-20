#include "ImageManager.h"
#include "Vec2D.h"

void ImageManager::AddImage(std::string key, std::filesystem::path path)
{
	if (!std::filesystem::exists(path))
	{
		std::cout << "‰æ‘œƒpƒX‚ª•s³‚Å‚·:" << std::endl;
		std::cout << path << std::endl;
	}

	int handle = LoadGraph(path.c_str());
	if (handle == -1) return;

	images[key] = handle;
}

void ImageManager::RemoveImage(std::string key)
{
	auto itr = images.find(key);
	if (itr == images.end()) return;

	DeleteGraph(itr->second);
	images.erase(itr);
}

void ImageManager::Draw(std::string key, const Vec2D& vec)
{
	DrawGraph(vec.x, vec.y, images[key], TRUE);
}

void ImageManager::DrawRota(std::string key, const Vec2D& vec, const Vec2D& center, float deg)
{
	DrawRotaGraph2(vec.x, vec.y, center.x, center.y, 1.0, deg, images[key], TRUE);
}

void ImageManager::DrawRotaAdv(std::string key, const Vec2D& vec, const Vec2D& center, float deg, float exRateX, float exRateY)
{
	DrawRotaGraph3(vec.x, vec.y, center.x, center.y, exRateX, exRateY, deg, images[key], TRUE);
}

void ImageManager::Draw(std::string key, const Vec2DF& vec)
{
	DrawGraph((int)vec.x, (int)vec.y, images[key], TRUE);
}

void ImageManager::DrawRota(std::string key, const Vec2DF& vec, const Vec2DF& center, float deg)
{
	DrawRotaGraph2((int)vec.x, (int)vec.y, (int)center.x, (int)center.y, 1.0, deg, images[key], TRUE);
}

void ImageManager::DrawRotaAdv(std::string key, const Vec2DF& vec, const Vec2DF& center, float deg, float exRateX, float exRateY)
{
	DrawRotaGraph3((int)vec.x, (int)vec.y, (int)center.x, (int)center.y, exRateX, exRateY, deg, images[key], TRUE);
}