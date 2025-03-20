#include "TimeManager.h"

void TimeManager::UpdateAverage()
{
	int length = (int)mList.size();
	if (length < LIST_LEN_MAX) return;

	//LIST_LEN_MAXフレームまでにかかった時間
	std::chrono::duration<float, std::milli> tookTime = mList.back() - mList.front();
	//平均計算
	mAverage = tookTime.count() / (length - 1);

	//0割り防止
	if (mAverage == 0) return;

	mFps = roundf((1000.0f / mAverage) * 100.0f) / 100.0f;
}

void TimeManager::Regist()
{
	//現在の時間を記録
	mList.push_back(std::chrono::high_resolution_clock::now());

	//器から漏れたらポップ
	if (LIST_LEN_MAX < (int)mList.size()) mList.pop_front();
}

float TimeManager::GetWaitTime() const
{
	int length = (int)mList.size();
	if (length == 0) return 0;

	//現在の時間
	std::chrono::high_resolution_clock::time_point nowTime = std::chrono::high_resolution_clock::now();

	//かかるべき時間
	float shouldTookTime = (1000.0f / (float)mFpsConfig * (float)length);
	//実際かかった時間
	std::chrono::duration<float, std::milli> actuallyTookTime = nowTime - mList.front();
	//待つべき時間
	float waitTime = shouldTookTime - actuallyTookTime.count();
	waitTime = 0 < waitTime ? waitTime : 0;

	return waitTime;
}

void TimeManager::Tick()
{
	mCounter++;

	Regist();
	//待つべき時間を取得して待つ
	std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(GetWaitTime()));

	//更新タイミングで平均値を更新
	if (mCounter == UPINTVL)
	{
		UpdateAverage();
		mCounter = 0;
	}
}

float TimeManager::GetDeltaTimeMs() const
{
	if (mList.size() < 2) return 0.0f;

	//現在の時間
	//std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now();
	auto prevTime = *(++mList.rbegin());
	auto nowTime = mList.back();
	//1フレーム前との差
	std::chrono::duration<float, std::milli> spendTime = nowTime - prevTime;//mList.back();

	return spendTime.count();
}

float TimeManager::GetDeltaTimeS() const
{
	if (mList.size() < 2) return 0.0f;

	//現在の時間
	//std::chrono::steady_clock::time_point nowTime = std::chrono::steady_clock::now();
	auto prevTime = *(++mList.rbegin());
	auto nowTime = mList.back();
	//1フレーム前との差
	std::chrono::duration<float> spendTime = nowTime - prevTime;//mList.back();

	return spendTime.count();
}

float TimeManager::GetFPS() const
{
	return mFps;
}