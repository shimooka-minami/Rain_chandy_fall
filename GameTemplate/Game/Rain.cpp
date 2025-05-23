#include "stdafx.h"
#include "Rain.h"
#include "Player.h"
#include "Game.h"

#include "ICreation.h"

//�q�N���X
Rain::Rain()
{
	//���f��
	ICreation::m_modelRender.Init("Assets/BackGround/shizukuyo.tkm");
}

Rain::~Rain()
{

}

//override�Œǉ��̏������ł���
void Rain::AddUpdate()
{
	
}

void Rain::Add()
{

	//�G�t�F�N�g�Đ�
	PlayEffect(enEffectName_Rain, m_position, m_rotation, m_scale);

	//�J�ɐG�ꂽ��ꎞ��~
	m_player->m_moveStop = true;
}


