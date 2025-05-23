#pragma once

#include "MakeEffect.h"
#include "sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Transparent;
class Rain;
class Candy;
class ICreation;
class ScoreResult;
class GameTimer;

//game�V�[�����Ǘ�����
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V����
	bool Start();
	void Update();

	void FontText();  //�t�H���g
	void RainTimer(); //Rain�����Ԍo�߂ŗ����Ă���
	void CandyTimer();
	void StartGame();
	void FontCoutTime(); //�J�E���g�_�E��

	void Memo();
	
	

	//void TimeUp();
	void Render(RenderContext& rc);
	

	//�C���X�^���X�֌W�B
	Player*			m_player;			//�v���C���[
	GameCamera*		m_gameCamera;		//�Q�[���J����
	BackGround*		m_backGround;
	Transparent*    m_transparent;  //�����ȕ�
	ScoreResult*    m_scoreResult;
	SoundSource*	m_gameBGM;		//�Q�[������BGM
	GameTimer*      m_gameTimer;    //�Q�[���^�C�}�[�̃t�H���g

	Rain*			m_rains[10];	//�z��
	Candy*			m_candys[10];	//�z��

	MakeEffect* m_makeEffect;	//�G�t�F�N�g
	SpriteRender spriteRender;  //UI

	

	//�h���b�v�֌W�B
	float	m_timerRain = 0.0f;
	float   m_timerCandy = 0.0f;
	float   m_timerCandyBule = 0.0f;


	int m_nowDropNum = 0;  //���݂̗����Ă镨�̐�

	//�������Ԋ֌W�B
	FontRender m_fontRender;  //�t�H���g
	float m_timer = 10.0f;

	//�J�E���g�_�E��
	float m_countDownTime = 0;

	//�^�C�}�[�̕���
	//SpriteRender m_timerFont;


	bool m_isTimeUp = false;
};






