#pragma once

#include "MakeEffect.h"

class Player;
class Game;
class ScoreResult;
//class MakeEffect;
class ICreation : public IGameObject 
{
public:
	ICreation();
	~ICreation();
	void Update();  //ベクトル

	/// <summary>
	/// 今は中身（ {  } ）がないため、子クラスのRein.cppで追加の処理ができる
	/// </summary>
	virtual void AddUpdate() {};
	//もう一つのoverrideのやつ
	virtual void Add() {};

	void Move();    //上から下に落ちる
	void Render(RenderContext& rc);

	void InitRandomPos();
	void ResetPos();

	void PlayEffect(EffectName name,Vector3 position,Quaternion rotation,Vector3 scale);

	ModelRender m_modelRender;
	FontRender m_scoreFontRender;
	Player* m_player;
	Game* m_game;
	
	//エフェクト
	//Vector3 m_position = Vector3::Zero; //座標
	Vector3 m_position;
	Quaternion m_rotation;              //回転
	Vector3 m_scale = Vector3{ 10.0f,10.0f,10.0f };     //拡大

	ScoreResult* m_scoreResult;

	//動くか動かないか
	bool m_isMove = false;

	//メンバ変数
	int m_score = 0;

	int m_moveSpeed = 0;
	
};

