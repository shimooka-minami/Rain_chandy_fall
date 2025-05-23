#include "stdafx.h"
#include "Rain.h"
#include "Player.h"
#include "Game.h"

#include "ICreation.h"

//子クラス
Rain::Rain()
{
	//モデル
	ICreation::m_modelRender.Init("Assets/BackGround/shizukuyo.tkm");
}

Rain::~Rain()
{

}

//overrideで追加の処理ができる
void Rain::AddUpdate()
{
	
}

void Rain::Add()
{

	//エフェクト再生
	PlayEffect(enEffectName_Rain, m_position, m_rotation, m_scale);

	//雨に触れたら一時停止
	m_player->m_moveStop = true;
}


