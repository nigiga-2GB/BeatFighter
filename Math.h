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
	/// �~������
	/// </summary>
	static const float PI = 3.1415926535f;

	/// <summary>
	/// �]���֐�
	/// </summary>
	/// <param name="x">�p�x[rad]</param>
	/// <returns>cos(x)</returns>
	static float Cos(float x)
	{
		return cos(x);
	}

	/// <summary>
	/// �����֐�
	/// </summary>
	/// <param name="x">�p�x[rad]</param>
	/// <returns>sin{x)</returns>
	static float Sin(float x)
	{
		return sin(x);
	}

	/// <summary>
	/// x��expo���Ԃ�
	/// </summary>
	/// <param name="x">�ׂ��悵������</param>
	/// <param name="expo">���悷�邩</param>
	/// <returns>�ׂ��悳�ꂽ�l</returns>
	static float Pow(float x, float expo)
	{
		return pow(x, expo);
	}

	/// <summary>
	/// ��捪��Ԃ�
	/// </summary>
	/// <param name="t">���[�g����肽����</param>
	/// <returns>t�̃��[�g</returns>
	static float Sqrt(float t)
	{
		return sqrt(t);
	}

	/// <summary>
	/// �񐔂̒�����ŏ��l��Ԃ�
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns>�������ق��̒l</returns>
	static float Min(float a, float b)
	{
		if (a > b) return b;
		else return a;
	}

	/// <summary>
	/// ���`�⊮
	/// </summary>
	/// <param name="a">���1</param>
	/// <param name="b">���2</param>
	/// <param name="t">����(0�`1)</param>
	/// <returns>�⊮���ꂽ�l</returns>
	static float Lerp(float a, float b, float t)
	{
		return std::lerp(a, b, t);
	}

	/// <summary>
	/// �x�������W�A���ɕϊ�
	/// </summary>
	/// <param name="x">�ϊ���������</param>
	/// <returns>���W�A��</returns>
	static float ToRadian(float x)
	{
		return (Math::PI / 180) * x;
	}

	/// <summary>
	/// ��Βl�擾
	/// </summary>
	/// <param name="x">��Βl���擾��������</param>
	/// <returns>��Βl</returns>
	static int Abs(int x)
	{
		if (x > 0) return x;
		else return -x;
	}

	/// <summary>
	/// ��Βl�擾
	/// </summary>
	/// <param name="x">��Βl���擾��������</param>
	/// <returns>��Βl</returns>
	static float Abs(float x)
	{
		if (x > 0) return x;
		else return -x;
	}

	/// <summary>
	/// �^����������
	/// </summary>
	/// <param name="min">�����̍ŏ��l</param>
	/// <param name="max">�����̍ő�l</param>
	/// <returns>����</returns>
	static int Random(unsigned int min, unsigned int max)
	{
		std::random_device rnd;
		std::mt19937 mt(rnd());

		std::uniform_int_distribution<int> rangedRand(min, max);

		return rangedRand(mt);
	}
}