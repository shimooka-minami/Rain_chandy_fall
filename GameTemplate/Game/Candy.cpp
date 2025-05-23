#include "stdafx.h"
#include "Candy.h"
#include "Player.h"
#include "Game.h"

#include "ICreation.h"
#include "ScoreResult.h"


//子クラス
Candy::Candy()
{
	//モデル
	ICreation::m_modelRender.Init("Assets/BackGround/candy1.tkm");

	//飴のスコアを100にする
	m_score = 100;
}


Candy::~Candy()
{

}

void Candy::AddUpdate()//overrideで追加の処理ができる
{
	
}

void Candy::Add()
{
	//エフェクト再生
	PlayEffect(enEffectName_Chandy, m_position, m_rotation, m_scale);
}




