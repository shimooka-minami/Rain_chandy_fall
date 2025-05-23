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
	void Update();  //�x�N�g��

	/// <summary>
	/// ���͒��g�i {  } �j���Ȃ����߁A�q�N���X��Rein.cpp�Œǉ��̏������ł���
	/// </summary>
	virtual void AddUpdate() {};
	//�������override�̂��
	virtual void Add() {};

	void Move();    //�ォ�牺�ɗ�����
	void Render(RenderContext& rc);

	void InitRandomPos();
	void ResetPos();

	void PlayEffect(EffectName name,Vector3 position,Quaternion rotation,Vector3 scale);

	ModelRender m_modelRender;
	FontRender m_scoreFontRender;
	Player* m_player;
	Game* m_game;
	
	//�G�t�F�N�g
	//Vector3 m_position = Vector3::Zero; //���W
	Vector3 m_position;
	Quaternion m_rotation;              //��]
	Vector3 m_scale = Vector3{ 10.0f,10.0f,10.0f };     //�g��

	ScoreResult* m_scoreResult;

	//�����������Ȃ���
	bool m_isMove = false;

	//�����o�ϐ�
	int m_score = 0;

	int m_moveSpeed = 0;
	
};

