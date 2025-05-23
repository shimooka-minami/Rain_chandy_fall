#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

}

bool GameCamera::Start()
{

	//�����_���王�_�܂ł̃x�N�g����ݒ�
	m_toCameraPos.Set(0.0f, 500.0f, -1000.0f);

	//�v���C���[�̃C���X�^���X��T��
	m_player = FindGO<Player>("player");

	//�J�����̃j�A�N���b�v�ƃt�@�[�N���b�v��ݒ肷��
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(10000.0f);

	return true;
}

void GameCamera::Update()
{
	//�J�������X�V

	//�����_���v�Z���� //��ʂ̌Œ�
	Vector3 target;
	//�v���C���[�̑������炿����Ə�𒍎��_�Ƃ���
	target.y += 100.0f;

	Vector3 toCameraPosOld = m_toCameraPos;

	//���_���v�Z����
	Vector3 pos = target + m_toCameraPos;

	//���C���J�����ɒ����_�Ǝ��_��ݒ肷��
	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	//�J�����̍X�V
	g_camera3D->Update();

	LightCamera();
}

//���C�g�J����
void GameCamera::LightCamera()
{
	//K2engine�̃V�[�����C�g��r�f�B���N�V�������C�g�������Ă���
	//0�͔z��A�|�W�V�����̓��C�g�̕����A�J���[�̓��C�g�̐F
	g_sceneLight->SetDirectionLight(0, Vector3::Down, Vector3{ 1.0f,1.0f,1.0f });
}

void GameCamera::Render(RenderContext& rc)
{

}
