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

//�ŏ���4������
const int INIT_DROP_NUM = 4;

Game::Game()
{
	//�^�C�g��
	spriteRender.Init("Assets/title/uiui.dds", 1920.0f, 1080.0f);

	//���ʉ�
	g_soundEngine->ResistWaveFileBank(0, "Assets/bgm/gamebgm.wav");
	m_gameBGM = NewGO<SoundSource>(0);
	m_gameBGM->Init(0);
	m_gameBGM->Play(true);
}

Game::~Game()
{
	//�v���C���[���폜����
	DeleteGO(m_player);
	//�Q�[���J�������폜����
	DeleteGO(m_gameCamera);
	//�Q�[�����̂a�f�l���폜����
	DeleteGO(m_gameBGM);
	//�w�i���폜����
	//DeleteGO(m_backGround);
	//�^�C�}�[�̕���
	DeleteGO(m_gameTimer);
	//���ƉJ
	for (int i = 0; i < 10; i++)
	{
		DeleteGO(m_rains[i]);
		DeleteGO(m_candys[i]);
	}
	//�X�R�A
	//DeleteGO(m_scoreResult);

	m_nowDropNum = INIT_DROP_NUM;
	
}


bool Game::Start()
{	
	//�����_��
	srand(time(nullptr));

	//�Q�[���J����
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//�v���C���[
	m_player = NewGO<Player>(0, "player");

	//�G�t�F�N�g
	m_makeEffect = NewGO<MakeEffect>(0, "effect");

	//�w�i
	m_backGround = NewGO<BackGround>(0, "ground");

	//�����ȕ�
	m_transparent = NewGO<Transparent>(0, "transparent");

	//�X�R�A
	m_scoreResult = NewGO<ScoreResult>(0, "scoreresult");

	//�^�C�}�[�̕���
	m_gameTimer = NewGO<GameTimer>(0, "gametimer");

	

	//�� 10����
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

	//�^�̏ꍇ��TimeUp�\��
	if (m_isTimeUp == true)
	{
		//timeUp�\����~Game�̍폜
		NewGO<TimeUp>(0, "TimeUp");
		DeleteGO(this);
		m_isTimeUp = false;
	}	
}


//�J�E���g�_�E���̏���
void Game::StartGame()
{
	//
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//���Ԍo��
		//FontText();
		m_gameTimer->m_isTimerStart = true;
		//TotalScore();

		//4��rain�������n�߂�B
		for (int i = 0; i < INIT_DROP_NUM; i++)
		{
			m_rains[i]->m_isMove = true;
			m_candys[i]->m_isMove = true;
		}
	}
	m_countDownTime += g_gameTime->GetFrameDeltaTime();
}

//����Ȃ����
void Game::FontCoutTime()
{
	
}

//�J�E���g�_�E��(5s)
//void Game::FontCoutTime()
//{
//	wchar_t wcsbuf[256];
//	swprintf_s(wcsbuf, 256, L"%d�b�o��!!", int(m_countDownTime));
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


//Rain�̏���
void Game::RainTimer()
{
	//�ő��10��rain��������	
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

//Chandy�̏���
void Game::CandyTimer()
{
	//�ő��10��rain��������
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

//���Ԍo��(60s) �g��Ȃ����
void Game::FontText()
{
	/*wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"�̂��肶����:%d�т傤", int(m_timer));

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

//�^�C���A�b�v��\����DeleteGO�̌Ăяo��
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