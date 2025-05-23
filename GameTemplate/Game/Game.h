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

//gameシーンを管理する
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理
	bool Start();
	void Update();

	void FontText();  //フォント
	void RainTimer(); //Rainが時間経過で落ちてくる
	void CandyTimer();
	void StartGame();
	void FontCoutTime(); //カウントダウン

	void Memo();
	
	

	//void TimeUp();
	void Render(RenderContext& rc);
	

	//インスタンス関係。
	Player*			m_player;			//プレイヤー
	GameCamera*		m_gameCamera;		//ゲームカメラ
	BackGround*		m_backGround;
	Transparent*    m_transparent;  //透明な壁
	ScoreResult*    m_scoreResult;
	SoundSource*	m_gameBGM;		//ゲーム中のBGM
	GameTimer*      m_gameTimer;    //ゲームタイマーのフォント

	Rain*			m_rains[10];	//配列
	Candy*			m_candys[10];	//配列

	MakeEffect* m_makeEffect;	//エフェクト
	SpriteRender spriteRender;  //UI

	

	//ドロップ関係。
	float	m_timerRain = 0.0f;
	float   m_timerCandy = 0.0f;
	float   m_timerCandyBule = 0.0f;


	int m_nowDropNum = 0;  //現在の落ちてる物の数

	//制限時間関係。
	FontRender m_fontRender;  //フォント
	float m_timer = 10.0f;

	//カウントダウン
	float m_countDownTime = 0;

	//タイマーの文字
	//SpriteRender m_timerFont;


	bool m_isTimeUp = false;
};






