#include "stdafx.h"
#include "Candy.h"
#include "Player.h"
#include "Game.h"

#include "ICreation.h"
#include "ScoreResult.h"


//�q�N���X
Candy::Candy()
{
	//���f��
	ICreation::m_modelRender.Init("Assets/BackGround/candy1.tkm");

	//���̃X�R�A��100�ɂ���
	m_score = 100;
}


Candy::~Candy()
{

}

void Candy::AddUpdate()//override�Œǉ��̏������ł���
{
	
}

void Candy::Add()
{
	//�G�t�F�N�g�Đ�
	PlayEffect(enEffectName_Chandy, m_position, m_rotation, m_scale);
}




