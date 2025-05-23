#include "stdafx.h"
#include <time.h> //rand
#include "Game.h"
#include "Title.h"
#include "Controller.h"
#include "GameStart.h"
#include "BackGround.h"
#include "Transparent.h"
#include "GameCamera.h"
#include "TimeUp.h"
#include "FinalResult.h";

#include "Player.h"
#include "Rain.h"
#include "Candy.h"
#include "ICreation.h"
#include "ScoreResult.h"
#include "GameTimer.h"

#include "MakeEffect.h"

//最初に4個落ちる
const int INIT_DROP_NUM = 4;

Game::Game()
{
	//タイトル
	spriteRender.Init("Assets/title/uiui.dds", 1920.0f, 1080.0f);

	//効果音
	g_soundEngine->ResistWaveFileBank(0, "Assets/bgm/gamebgm.wav");
	m_gameBGM = NewGO<SoundSource>(0);
	m_gameBGM->Init(0);
	m_gameBGM->Play(true);
}

Game::~Game()
{
	//プレイヤーを削除する
	DeleteGO(m_player);
	//ゲームカメラを削除する
	DeleteGO(m_gameCamera);
	//ゲーム中のＢＧＭを削除する
	DeleteGO(m_gameBGM);
	//背景を削除する
	//DeleteGO(m_backGround);
	//タイマーの文字
	DeleteGO(m_gameTimer);
	//飴と雨
	for (int i = 0; i < 10; i++)
	{
		DeleteGO(m_rains[i]);
		DeleteGO(m_candys[i]);
	}
	//スコア
	//DeleteGO(m_scoreResult);

	m_nowDropNum = INIT_DROP_NUM;
	
}


bool Game::Start()
{	
	//ランダム
	srand(time(nullptr));

	//ゲームカメラ
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//プレイヤー
	m_player = NewGO<Player>(0, "player");

	//エフェクト
	m_makeEffect = NewGO<MakeEffect>(0, "effect");

	//背景
	m_backGround = NewGO<BackGround>(0, "ground");

	//透明な壁
	m_transparent = NewGO<Transparent>(0, "transparent");

	//スコア
	m_scoreResult = NewGO<ScoreResult>(0, "scoreresult");

	//タイマーの文字
	m_gameTimer = NewGO<GameTimer>(0, "gametimer");

	

	//個数 10個生成
	for (int i = 0; i < 10; i++)
	{
		m_rains[i] = NewGO<Rain>(0, "Rain");
		m_candys[i] = NewGO<Candy>(0, "Candy");
	}

	m_nowDropNum = INIT_DROP_NUM;

	return true;
}

void Game::Update()
{
	StartGame();

	RainTimer();
	CandyTimer();

	//TotalScore();

	//FontText();

	//真の場合にTimeUp表示
	if (m_isTimeUp == true)
	{
		//timeUp表示＆~Gameの削除
		NewGO<TimeUp>(0, "TimeUp");
		DeleteGO(this);
		m_isTimeUp = false;
	}	
}


//カウントダウンの処理
void Game::StartGame()
{
	//
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//時間経過
		//FontText();
		m_gameTimer->m_isTimerStart = true;
		//TotalScore();

		//4つのrainが落ち始める。
		for (int i = 0; i < INIT_DROP_NUM; i++)
		{
			m_rains[i]->m_isMove = true;
			m_candys[i]->m_isMove = true;
		}
	}
	m_countDownTime += g_gameTime->GetFrameDeltaTime();
}

//つかわないやつ
void Game::FontCoutTime()
{
	
}

//カウントダウン(5s)
//void Game::FontCoutTime()
//{
//	wchar_t wcsbuf[256];
//	swprintf_s(wcsbuf, 256, L"%d秒経過!!", int(m_countDownTime));
//
//	m_fontRender.SetText(wcsbuf);
//	m_fontRender.SetPosition({ 0.0f, 500.0f, 0.0f });
//	m_fontRender.SetColor(g_vec4White);
//
//	m_countDownTime += g_gameTime->GetFrameDeltaTime();
//
//	if (m_countDownTime >= 5)
//	{
//		DeleteGO(this);
//	}
//
//	return;
//}


//Rainの処理
void Game::RainTimer()
{
	//最大で10個のrainが落ちる	
	if (m_nowDropNum >= 9)
	{
		return;
	}

	if (m_timerRain >= 10) 
	{	
		m_nowDropNum++;
		m_rains[m_nowDropNum]->m_isMove = true;
		m_timerRain = 0;
	}
	
	m_timerRain += g_gameTime->GetFrameDeltaTime();
}

//Chandyの処理
void Game::CandyTimer()
{
	//最大で10個のrainが落ちる
	if (m_nowDropNum >= 9)
	{
		return;
	}

	if (m_timerCandy >= 10)
	{
		m_nowDropNum++;
		m_candys[m_nowDropNum]->m_isMove = true;
		m_timerCandy = 0;
	}

	m_timerCandy += g_gameTime->GetFrameDeltaTime();
}

//時間経過(60s) 使わないやつ
void Game::FontText()
{
	/*wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"のこりじかん:%dびょう", int(m_timer));

	m_fontRender.SetText(wcsbuf);
	m_fontRender.SetPosition({ 0.0f, 500.0f, 0.0f });
	m_fontRender.SetColor(g_vec4White);*/

	//if (m_gameTimer->m_time < 0)
	//{
		//NewGO<TimeUp>(0, "TimeUp");
		//DeleteGO(this);
	//}
	// 

	

	//m_timer -= g_gameTime->GetFrameDeltaTime();
}

//タイムアップを表示＆DeleteGOの呼び出し
void Game::Memo()
{
	m_isTimeUp = true;
}

void Game::Render(RenderContext& rc)
{
	//m_fontRender.Draw(rc);
	spriteRender.Draw(rc);
	//m_gameTimer->Render(rc);
}