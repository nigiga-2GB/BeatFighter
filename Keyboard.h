#pragma once

#include<array>
#include<DxLib.h>

class Keyboard
{
private:
	//�L�[����
	static constexpr int KEY_NUM = 256;

	//������J�E���^
	std::array<int, KEY_NUM> pressingCount{ 0 };
	//������J�E���^
	std::array<int, KEY_NUM> releasingCount{ 0 };

	bool IsAvailableCode(int keyCode);

public:
	Keyboard() = default;

	/// <summary>
	/// �L�[�{�[�h�̓��͏�Ԃ̍X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �L�[��������Ă���t���[�����擾����
	/// </summary>
	/// <param name="keyCode">�L�[�R�[�h</param>
	/// <returns>������Ă���t���[��</returns>
	int GetPressingCount(int keyCode);

	/// <summary>
	/// �L�[��������Ă���t���[�����擾����
	/// </summary>
	/// <param name="keyCode">�L�[�R�[�h</param>
	/// <returns>������Ă���t���[��</returns>
	int GetReleasingCount(int keyCode);
};