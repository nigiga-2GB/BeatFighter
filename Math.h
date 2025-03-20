#pragma once

#include<cmath>
#include<random>

namespace Math
{
	template<class T>
	static T operator+(const T& t1, const T& t2)
	{
		return T(t1) += t2;
	}

	template<class T>
	static T operator-(const T& t1, const T& t2)
	{
		return T(t1) -= t2;
	}

	/// <summary>
	/// 円周率π
	/// </summary>
	static const float PI = 3.1415926535f;

	/// <summary>
	/// 余弦関数
	/// </summary>
	/// <param name="x">角度[rad]</param>
	/// <returns>cos(x)</returns>
	static float Cos(float x)
	{
		return cos(x);
	}

	/// <summary>
	/// 正弦関数
	/// </summary>
	/// <param name="x">角度[rad]</param>
	/// <returns>sin{x)</returns>
	static float Sin(float x)
	{
		return sin(x);
	}

	/// <summary>
	/// xのexpo乗を返す
	/// </summary>
	/// <param name="x">べき乗したい数</param>
	/// <param name="expo">何乗するか</param>
	/// <returns>べき乗された値</returns>
	static float Pow(float x, float expo)
	{
		return pow(x, expo);
	}

	/// <summary>
	/// 二乗根を返す
	/// </summary>
	/// <param name="t">ルートを取りたい数</param>
	/// <returns>tのルート</returns>
	static float Sqrt(float t)
	{
		return sqrt(t);
	}

	/// <summary>
	/// 二数の中から最小値を返す
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>小さいほうの値</returns>
	static float Min(float a, float b)
	{
		if (a > b) return b;
		else return a;
	}

	/// <summary>
	/// 線形補完
	/// </summary>
	/// <param name="a">状態1</param>
	/// <param name="b">状態2</param>
	/// <param name="t">時間(0～1)</param>
	/// <returns>補完された値</returns>
	static float Lerp(float a, float b, float t)
	{
		return std::lerp(a, b, t);
	}

	/// <summary>
	/// 度数をラジアンに変換
	/// </summary>
	/// <param name="x">変換したい数</param>
	/// <returns>ラジアン</returns>
	static float ToRadian(float x)
	{
		return (Math::PI / 180) * x;
	}

	/// <summary>
	/// 絶対値取得
	/// </summary>
	/// <param name="x">絶対値を取得したい数</param>
	/// <returns>絶対値</returns>
	static int Abs(int x)
	{
		if (x > 0) return x;
		else return -x;
	}

	/// <summary>
	/// 絶対値取得
	/// </summary>
	/// <param name="x">絶対値を取得したい数</param>
	/// <returns>絶対値</returns>
	static float Abs(float x)
	{
		if (x > 0) return x;
		else return -x;
	}

	/// <summary>
	/// 疑似乱数生成
	/// </summary>
	/// <param name="min">乱数の最小値</param>
	/// <param name="max">乱数の最大値</param>
	/// <returns>乱数</returns>
	static int Random(unsigned int min, unsigned int max)
	{
		std::random_device rnd;
		std::mt19937 mt(rnd());

		std::uniform_int_distribution<int> rangedRand(min, max);

		return rangedRand(mt);
	}
}