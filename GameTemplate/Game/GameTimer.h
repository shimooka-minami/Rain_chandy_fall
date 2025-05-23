#pragma once

class Game;
class GameTimer:public IGameObject
{
public:
	//10のくらい
	enum GameTimerFontLeft
	{
		TIME_LEFT_0,
		TIME_LEFT_1,
		TIME_LEFT_2,
		TIME_LEFT_3,
		TIME_LEFT_4,
		TIME_LEFT_5,
		TIME_LEFT_6,
		TIME_LEFT_7,
		TIME_LEFT_8,
		TIME_LEFT_9
	};
	//1のくらい
	enum GameTimerFontRight
	{
		TIME_RIGHT_0,
		TIME_RIGHT_1,
		TIME_RIGHT_2,
		TIME_RIGHT_3,
		TIME_RIGHT_4,
		TIME_RIGHT_5,
		TIME_RIGHT_6,
		TIME_RIGHT_7,
		TIME_RIGHT_8,
		TIME_RIGHT_9
	};

	//関数
	GameTimer();
	~GameTimer();

	bool Start();
	void Updata();

	//数字のステート処理
	void TimeFontLeft();
	void TimeFontRight();


	//増加するタイム
	void IncreaseTimer();

	void Render(RenderContext& rc);

	SpriteRender m_timeFontLeft; //タイマーのやつ
	SpriteRender m_fontRender;

	Game* m_game;

	//10のくらい
	SpriteRender m_timeFontLeft0;
	SpriteRender m_timeFontLeft1;
	SpriteRender m_timeFontLeft2;
	SpriteRender m_timeFontLeft3;
	SpriteRender m_timeFontLeft4;
	SpriteRender m_timeFontLeft5;
	SpriteRender m_timeFontLeft6;
	SpriteRender m_timeFontLeft7;
	SpriteRender m_timeFontLeft8;
	SpriteRender m_timeFontLeft9;

	//1のくらい
	SpriteRender m_timeFontRight0;
	SpriteRender m_timeFontRight1;
	SpriteRender m_timeFontRight2;
	SpriteRender m_timeFontRight3;
	SpriteRender m_timeFontRight4;
	SpriteRender m_timeFontRight5;
	SpriteRender m_timeFontRight6;
	SpriteRender m_timeFontRight7;
	SpriteRender m_timeFontRight8;
	SpriteRender m_timeFontRight9;

	//10のくらいと1のくらい
	int m_timeLeftState;
	int m_timeRightState;

	//タイマーの秒数
	float m_second = 0.0f;
	float m_time = 60.0f;
	bool m_isTimerStart = false;
};

