#include "stdafx.h"
#include "ICreation.h"
#include "Player.h"
#include "Game.h"
#include "ScoreResult.h"
#include "MakeEffect.h"
#include <DirectXTK/Inc/Audio.h>

//親クラス
ICreation::ICreation()
{
	//プレイヤーオブジェクト
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("game");
	m_scoreResult = FindGO<ScoreResult>("scoreresult");

	//初期のランダム配置
	float posX = (rand() % 11) * 40;
	int posRandom = rand() % 2;
	if (posRandom == 0)
	{
		posX *= -1.0;
	}

	float posZ = (rand() % 11) * 40;
	posRandom = rand() % 2;
	if (posRandom == 0)
	{
		posZ *= -1.0;
	}

	m_position = { posX , -90.0f , posZ };	//初期位置
}

ICreation::~ICreation()
{

}

void ICreation::Update()
{
	//moveSwichが真の場合にMove()が動く
	if (m_isMove == true)
	{
		//移動処理
		Move();
	}

	//判定
	ResetPos();

	//オーバーライドであめのUpdateを追加
	AddUpdate();

	//レンダー
	m_modelRender.SetPosition(m_position);

	m_modelRender.Update();
}

void ICreation::ResetPos()
{
	//プレイヤーが雨に当たる
	Vector3 diff = m_player->m_position - m_position;
	//ベクトルの長さが60.0ｆより小さかったら
	if (diff.Length() <= 60.0f)
	{
		//エフェクト再生
		//PlayEffect(enEffectName_Chandy, m_position, m_rotation, m_scale);
			
		//拡張用の関数。
		Add();

		//初期位置に戻る
		m_position.y = 600.0f;

		//スコアをゼットスコアに入れる
		m_scoreResult->SetScore(m_score);

		//二回目以降のランダム配置
		InitRandomPos();
	}
	//雫が床に落ちたら
	else if (m_position.y <= -100.0f)
	{
		//初期位置に戻る
		m_position.y = 600.0f;

		//二回目以降のランダム配置
		InitRandomPos();
	}
}

void ICreation::InitRandomPos()
{
	//二回目以降のランダム配置
	float posX = (rand() % 11) * 40;
	int posRandom = rand() % 2;
	if (posRandom == 0)
	{
		posX *= -1.0;
	}

	float posZ = (rand() % 11) * 40;
	posRandom = rand() % 2;
	if (posRandom == 0)
	{
		posZ *= -1.0;
	}

	m_position = { posX , 600.0f , posZ };
}

//移動
void ICreation::Move()
{
	//上から下に落ちる
	m_position.y -= 2.0f;
}

//エフェクト
void ICreation::PlayEffect(EffectName name, Vector3 position, Quaternion rotation, Vector3 scale)
{
	//エフェクトの再生
	EffectEmitter* m_effect = NewGO<EffectEmitter>(0);
	m_effect->Init(name);
	m_effect->SetPosition(m_position);
	m_effect->SetRotation(m_rotation);
	m_effect->SetScale(m_scale);
	m_effect->Play();
}

void ICreation::Render(RenderContext& rc)
{
	//font
	//m_scoreFontRender.Draw(rc);

	//描画
	m_modelRender.Draw(rc);
}