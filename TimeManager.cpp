#include "TimeManager.h"

void TimeManager::UpdateAverage()
{
	int length = (int)mList.size();
	if (length < LIST_LEN_MAX) return;

	//LIST_LEN_MAX�t���[���܂łɂ�����������
	std::chrono::duration<float, std::milli> tookTime = mList.back() - mList.front();
	//���όv�Z
	mAverage = tookTime.count() / (length - 1);

	//0����h�~
	if (mAverage == 0) return;

	mFps = roundf((1000.0f / mAverage) * 100.0f) / 100.0f;
}

void TimeManager::Regist()
{
	//���݂̎��Ԃ��L�^
	mList.push_back(std::chrono::high_resolution_clock::now());

	//�킩��R�ꂽ��|�b�v
	if (LIST_LEN_MAX < (int)mList.size()) mList.pop_front();
}

float TimeManager::GetWaitTime() const
{
	int length = (int)mList.size();
	if (length == 0) return 0;

	//���݂̎���
	std::chrono::high_resolution_clock::time_point nowTime = std::chrono::high_resolution_clock::now();

	//������ׂ�����
	float shouldTookTime = (1000.0f / (float)mFpsConfig * (float)length);
	//���ۂ�����������
	std::chrono::duration<float, std::milli> actuallyTookTime = nowTime - mList.front();
	//�҂ׂ�����
	float waitTime = shouldTookTime - actuallyTookTime.count();
	waitTime = 0 < waitTime ? waitTime : 0;

	return waitTime;
}

void TimeManager::Tick()
{
	mCounter++;

	Regist();
	//�҂ׂ����Ԃ��擾���đ҂�
	std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(GetWaitTime()));

	//�X�V�^�C�~���O�ŕ��ϒl���X�V
	if (mCounter == UPINTVL)
	{
		UpdateAverage();
		mCounter = 0;
	}
}

float TimeManager::GetDeltaTimeMs() const
{
	if (mList.size() < 2) return 0.0f;

	//���݂̎���
	//std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now();
	auto prevTime = *(++mList.rbegin());
	auto nowTime = mList.back();
	//1�t���[���O�Ƃ̍�
	std::chrono::duration<float, std::milli> spendTime = nowTime - prevTime;//mList.back();

	return spendTime.count();
}

float TimeManager::GetDeltaTimeS() const
{
	if (mList.size() < 2) return 0.0f;

	//���݂̎���
	//std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now();
	auto prevTime = *(++mList.rbegin());
	auto nowTime = mList.back();
	//1�t���[���O�Ƃ̍�
	std::chrono::duration<float> spendTime = nowTime - prevTime;//mList.back();

	return spendTime.count();
}

float TimeManager::GetFPS() const
{
	return mFps;
}