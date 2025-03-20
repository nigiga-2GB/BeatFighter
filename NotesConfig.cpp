#include "NotesConfig.h"
#include "System.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "EffectManager.h"
#include "ImageManager.h"
#include "AudioManager.h"
#include "SerialManager.h"
#include "Keyboard.h"
#include "Circle.h"
#include "Color.h"
#include "Math.h"
#include "Easing.h"
#include "Palette.h"
#include "Vec2D.h"
#include "SelectScene.h"

NotesConfig::NotesConfig()
{

}

NotesConfig::~NotesConfig()
{

}

void NotesConfig::Update()
{
	std::ofstream file(this->cfgPath);
	
	file << CalcAve();

	//シリアル通信
	if (SERIAL->CheckRecv(arPort) > 0)
	{
		SERIAL->Recv(arPort, buffer, 1);
	}

	if (!startFlag)
	{
		spendTime += TIMER->GetDeltaTimeS();
		if (KEYBOARD->GetPressingCount(KEY_INPUT_SPACE) == 1 || buffer[0] == 'P')
		{
			startFlag = true;
			AUDIO->Stop("notes_config");
			spendTime = 0.0f;
			return;
		}

		if (!AUDIO->IsPlaying("notes_config"))
		{
			AUDIO->Play("notes_config", PLAY_TYPE::BackGround);
			spendTime = 0.0f;
			effectFlag = false;
		}

		if (spendTime >= 1.0f)
		{
			if (!effectFlag)
			{
				EFFECT->AddEffect<NotesCfgEft>(1.0f);
				effectFlag = true;
			}
		}

		DrawFormatString(300, 300, Palette::Yellow.Get(), L"SPACEを押して調節スタート");
	}
	else
	{
		spendTime += TIMER->GetDeltaTimeS();
		DrawFormatString(300, 300, Palette::FloralWhite.Get(), L"平均: %.3f", CalcAve());

		std::queue<float> tmp = times;
		for (int i = 0; i < times.size(); i++)
		{
			float num = tmp.front();
			tmp.pop();
			DrawFormatString(200 + i * 200, 500, Palette::White.Get(), L"%.3f", num);
		}
		
		if (!AUDIO->IsPlaying("notes_config"))
		{
			AUDIO->Play("notes_config", PLAY_TYPE::BackGround);
			spendTime = 0.0f;
			effectFlag = false;
		}

		if (spendTime >= 1.0f)
		{
			if (!effectFlag)
			{
				EFFECT->AddEffect<NotesCfgEft>(1.0f);
				effectFlag = true;
			}
		}

		if (KEYBOARD->GetPressingCount(KEY_INPUT_SPACE) == 1)
		{
			if (0.75f < spendTime && spendTime < 1.25f)
			{
				//printfDx(L"%f\n", spendTime - 1.0f);
				times.push(spendTime - 1.0f);
			}
		}

		if (KEYBOARD->GetPressingCount(KEY_INPUT_E) == 1)
		{
			nlohmann::json par;

			SCENE->ChangeScene<NotesConfig, SelectScene>(param);
		}
	}
}

void NotesConfig::Draw() const
{

}

float NotesConfig::CalcAve()
{
	if (times.size() > 5)
	{
		times.pop();
	}
	
	std::queue<float> tmp = times;

	float sum = 0.0f;
	
	while (!tmp.empty())
	{
		sum += tmp.front();
		tmp.pop();
	}

	return sum / times.size();
}