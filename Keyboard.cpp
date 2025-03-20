#include "Keyboard.h"

void Keyboard::Update()
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);

	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStatus[i] != 0)
		{
			if (releasingCount[i] > 0) releasingCount[i] = 0;

			pressingCount[i]++;
		}
		else
		{
			if (pressingCount[i] > 0) pressingCount[i] = 0;

			releasingCount[i]++;
		}
	}
}

int Keyboard::GetPressingCount(int keyCode)
{
	if (!IsAvailableCode(keyCode)) return -1;

	return pressingCount[keyCode];
}

int Keyboard::GetReleasingCount(int keyCode)
{
	if (!IsAvailableCode(keyCode)) return -1;

	return releasingCount[keyCode];
}

bool Keyboard::IsAvailableCode(int keyCode)
{
	if (!(0 <= keyCode && keyCode < KEY_NUM)) return false;

	return true;
}