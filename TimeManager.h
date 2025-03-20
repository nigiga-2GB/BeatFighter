#pragma once

#include<list>
#include<DxLib.h>
#include<thread>
#include<chrono>

class TimeManager
{
private:
	std::list<std::chrono::high_resolution_clock::time_point> mList;
	float mFps;
	unsigned mCounter;
	float mAverage;

	int mFpsConfig;
	const static int LIST_LEN_MAX = 120;
	const static int UPINTVL = 30;

	void UpdateAverage();
	void Regist();
	float GetWaitTime() const;

public:
	TimeManager()
	{
		mFps = 60;
		mAverage = 1000.0f / 60.0f;

		mCounter = 0;
		mFpsConfig = 60;
	}
	~TimeManager() = default;

	void Tick();

	float GetDeltaTimeMs() const;
	float GetDeltaTimeS() const;
	float GetFPS() const;
};