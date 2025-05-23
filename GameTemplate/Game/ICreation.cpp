#include "stdafx.h"
#include "ICreation.h"
#include "Player.h"
#include "Game.h"
#include "ScoreResult.h"
#include "MakeEffect.h"
#include <DirectXTK/Inc/Audio.h>

//�e�N���X
ICreation::ICreation()
{
	//�v���C���[�I�u�W�F�N�g
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("game");
	m_scoreResult = FindGO<ScoreResult>("scoreresult");

	//�����̃����_���z�u
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

	m_position = { posX , -90.0f , posZ };	//�����ʒu
}

ICreation::~ICreation()
{

}

void ICreation::Update()
{
	//moveSwich���^�̏ꍇ��Move()������
	if (m_isMove == true)
	{
		//�ړ�����
		Move();
	}

	//����
	ResetPos();

	//�I�[�o�[���C�h�ł��߂�Update��ǉ�
	AddUpdate();

	//�����_�[
	m_modelRender.SetPosition(m_position);

	m_modelRender.Update();
}

void ICreation::ResetPos()
{
	//�v���C���[���J�ɓ�����
	Vector3 diff = m_player->m_position - m_position;
	//�x�N�g���̒�����60.0����菬����������
	if (diff.Length() <= 60.0f)
	{
		//�G�t�F�N�g�Đ�
		//PlayEffect(enEffectName_Chandy, m_position, m_rotation, m_scale);
			
		//�g���p�̊֐��B
		Add();

		//�����ʒu�ɖ߂�
		m_position.y = 600.0f;

		//�X�R�A���[�b�g�X�R�A�ɓ����
		m_scoreResult->SetScore(m_score);

		//���ڈȍ~�̃����_���z�u
		InitRandomPos();
	}
	//�������ɗ�������
	else if (m_position.y <= -100.0f)
	{
		//�����ʒu�ɖ߂�
		m_position.y = 600.0f;

		//���ڈȍ~�̃����_���z�u
		InitRandomPos();
	}
}

void ICreation::InitRandomPos()
{
	//���ڈȍ~�̃����_���z�u
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

//�ړ�
void ICreation::Move()
{
	//�ォ�牺�ɗ�����
	m_position.y -= 2.0f;
}

//�G�t�F�N�g
void ICreation::PlayEffect(EffectName name, Vector3 position, Quaternion rotation, Vector3 scale)
{
	//�G�t�F�N�g�̍Đ�
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

	//�`��
	m_modelRender.Draw(rc);
}