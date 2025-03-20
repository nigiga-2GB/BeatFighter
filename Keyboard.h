#pragma once

#include<array>
#include<DxLib.h>

class Keyboard
{
private:
	//キー総数
	static constexpr int KEY_NUM = 256;

	//押されカウンタ
	std::array<int, KEY_NUM> pressingCount{ 0 };
	//離されカウンタ
	std::array<int, KEY_NUM> releasingCount{ 0 };

	bool IsAvailableCode(int keyCode);

public:
	Keyboard() = default;

	/// <summary>
	/// キーボードの入力状態の更新
	/// </summary>
	void Update();

	/// <summary>
	/// キーが押されているフレームを取得する
	/// </summary>
	/// <param name="keyCode">キーコード</param>
	/// <returns>押されているフレーム</returns>
	int GetPressingCount(int keyCode);

	/// <summary>
	/// キーが離されているフレームを取得する
	/// </summary>
	/// <param name="keyCode">キーコード</param>
	/// <returns>離されているフレーム</returns>
	int GetReleasingCount(int keyCode);
};