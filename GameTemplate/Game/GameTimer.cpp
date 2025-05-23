#include "stdafx.h"
#include "GameTimer.h"

#include "Game.h"

#include "TimeUp.h"



GameTimer::GameTimer()
{
	//10のくらい
	m_timeFontLeft0.Init("Assets/title/time0.dds", 200.0f, 200.0f);
	m_timeFontLeft0.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft0.Update();

	m_timeFontLeft1.Init("Assets/title/time1.dds", 200.0f, 200.0f);
	m_timeFontLeft1.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft1.Update();

	m_timeFontLeft2.Init("Assets/title/time2.dds", 200.0f, 200.0f);
	m_timeFontLeft2.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft2.Update();

	m_timeFontLeft3.Init("Assets/title/time3.dds", 200.0f, 200.0f);
	m_timeFontLeft3.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft3.Update();

	m_timeFontLeft4.Init("Assets/title/time4.dds", 200.0f, 200.0f);
	m_timeFontLeft4.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft4.Update();

	m_timeFontLeft5.Init("Assets/title/time5.dds", 200.0f, 200.0f);
	m_timeFontLeft5.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft5.Update();

	m_timeFontLeft6.Init("Assets/title/time6.dds", 200.0f, 200.0f);
	m_timeFontLeft6.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft6.Update();

	m_timeFontLeft7.Init("Assets/title/time7.dds", 200.0f, 200.0f);
	m_timeFontLeft7.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft7.Update();

	m_timeFontLeft8.Init("Assets/title/time8.dds", 200.0f, 200.0f);
	m_timeFontLeft8.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft8.Update();

	m_timeFontLeft9.Init("Assets/title/time9.dds", 200.0f, 200.0f);
	m_timeFontLeft9.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft9.Update();


	//1のくらい
	m_timeFontRight0.Init("Assets/title/time0.dds", 200.0f, 200.0f);
	m_timeFontRight0.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight0.Update();

	m_timeFontRight1.Init("Assets/title/time1.dds", 200.0f, 200.0f);
	m_timeFontRight1.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight1.Update();

	m_timeFontRight2.Init("Assets/title/time2.dds", 200.0f, 200.0f);
	m_timeFontRight2.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight2.Update();

	m_timeFontRight3.Init("Assets/title/time3.dds", 200.0f, 200.0f);
	m_timeFontRight3.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight3.Update();

	m_timeFontRight4.Init("Assets/title/time4.dds", 200.0f, 200.0f);
	m_timeFontRight4.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight4.Update();

	m_timeFontRight5.Init("Assets/title/time5.dds", 200.0f, 200.0f);
	m_timeFontRight5.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight5.Update();

	m_timeFontRight6.Init("Assets/title/time6.dds", 200.0f, 200.0f);
	m_timeFontRight6.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight6.Update();

	m_timeFontRight7.Init("Assets/title/time7.dds", 200.0f, 200.0f);
	m_timeFontRight7.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight7.Update();

	m_timeFontRight8.Init("Assets/title/time8.dds", 200.0f, 200.0f);
	m_timeFontRight8.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight8.Update();

	m_timeFontRight9.Init("Assets/title/time9.dds", 200.0f, 200.0f);
	m_timeFontRight9.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight9.Update();


	//ゲームのファインドごー
	m_game = FindGO<Game>("game");

}

GameTimer::~GameTimer()
{

}

bool GameTimer::Start()
{
	return true;
}

void GameTimer::Updata()
{
	if (g_pad[0]->IsPress(enButtonA))
	{
		m_isTimerStart = true;
	}

	//if (m_isTimerStart == true)
	//{
	//	//IncreaseTimer();
	//}
	
	//時間の場所
	m_timeFontLeft6.SetPosition(Vector3{ -50.0f, 380.0f, 0.0f });
	m_timeFontLeft6.Update();

	m_timeFontRight0.SetPosition(Vector3{ 50.0f, 380.0f, 0.0f });
	m_timeFontRight0.Update();

}

void GameTimer::TimeFontLeft()
{
	switch (m_timeLeftState)
	{
	case TIME_LEFT_0:
		//m_timeLeftState = TIME_LEFT_6;
		break;
	case TIME_LEFT_1:
		m_timeLeftState = TIME_LEFT_0;
		break;
	case TIME_LEFT_2:
		m_timeLeftState = TIME_LEFT_1;
		break;
	case TIME_LEFT_3:
		m_timeLeftState = TIME_LEFT_2;
		break;
	case TIME_LEFT_4:
		m_timeLeftState = TIME_LEFT_3;
		break;
	case TIME_LEFT_5:
		m_timeLeftState = TIME_LEFT_4;
		break;
	case TIME_LEFT_6:
		m_timeLeftState = TIME_LEFT_5;
		break;
	case TIME_LEFT_7:
		m_timeLeftState = TIME_LEFT_6;
		break;
	case TIME_LEFT_8:
		m_timeLeftState = TIME_LEFT_7;
		break;
	case TIME_LEFT_9:
		m_timeLeftState = TIME_LEFT_8;
	}
}

void GameTimer::TimeFontRight()
{
	switch (m_timeRightState) 
	{
	case TIME_RIGHT_0:
		m_timeRightState = TIME_RIGHT_9;
		break;
	case TIME_RIGHT_1:
		m_timeRightState = TIME_RIGHT_0;
		break;
	case TIME_RIGHT_2:
		m_timeRightState = TIME_RIGHT_1;
		break;
	case TIME_RIGHT_3:
		m_timeRightState = TIME_RIGHT_2;
		break;
	case TIME_RIGHT_4:
		m_timeRightState = TIME_RIGHT_3;
		break;
	case TIME_RIGHT_5:
		m_timeRightState = TIME_RIGHT_4;
		break;
	case TIME_RIGHT_6:
		m_timeRightState = TIME_RIGHT_5;
		break;
	case TIME_RIGHT_7:
		m_timeRightState = TIME_RIGHT_6;
		break;
	case TIME_RIGHT_8:
		m_timeRightState = TIME_RIGHT_7;
		break;
	case TIME_RIGHT_9:
		m_timeRightState = TIME_RIGHT_8;
		break;
	default:
		break;
	}
}

//動いてない
void GameTimer::IncreaseTimer()
{
	//
	/*m_second -= g_gameTime->GetFrameDeltaTime();
	if (m_second < 0.0f)
	{
		m_second = 0.0f;
	}*/
}

void GameTimer::Render(RenderContext& rc)
{
	if (m_isTimerStart == true)
	{
		m_time -= g_gameTime->GetFrameDeltaTime();

		if (m_time < 0.0f)
		{
			
			//NewGO<TimeUp>(0, "TimeUp");

			m_game->Memo();
			m_time = 0.0f;
			m_isTimerStart = false;
			
			
			DeleteGO(this);
		}
		
	}

	//static = 値が変換されることはない　cast = 型変換
	int seconds = static_cast<int>(m_time) % 90;
	int secondLeft = seconds / 10;
	int secondRight = seconds % 10;

	switch (secondLeft)
	{
	case 0:
		m_timeFontLeft0.Draw(rc);
		break;
	case 1:
		m_timeFontLeft1.Draw(rc);
		break;
	case 2:
		m_timeFontLeft2.Draw(rc);
		break;
	case 3:
		m_timeFontLeft3.Draw(rc);
		break;
	case 4:
		m_timeFontLeft4.Draw(rc);
		break;
	case 5:
		m_timeFontLeft5.Draw(rc);
		break;
	case 6:
		m_timeFontLeft6.Draw(rc);
		break;
	case 7:
		m_timeFontLeft7.Draw(rc);
		break;
	case 8:
		m_timeFontLeft8.Draw(rc);
		break;

	}

	switch (secondRight)
	{
	case 0:
		m_timeFontRight0.Draw(rc);
		break;
	case 1:
		m_timeFontRight1.Draw(rc);
		break;
	case 2:
		m_timeFontRight2.Draw(rc);
		break;
	case 3:
		m_timeFontRight3.Draw(rc);
		break;
	case 4:
		m_timeFontRight4.Draw(rc);
		break;
	case 5:
		m_timeFontRight5.Draw(rc);
		break;
	case 6:
		m_timeFontRight6.Draw(rc);
		break;
	case 7:
		m_timeFontRight7.Draw(rc);
		break;
	case 8:
		m_timeFontRight8.Draw(rc);
		break;
	case 9:
		m_timeFontRight9.Draw(rc);
		break;
	}	
}
