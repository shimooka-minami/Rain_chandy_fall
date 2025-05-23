#include "stdafx.h"
#include "Player.h"
#include "GameCamera.h"
#include "GameTimer.h"

namespace
{
	const float STOP_TIME = 3.0f;
}

Player::Player()
{
	//�A�j���[�V�����N���b�v�̃��[�h
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	m_animationClips[enAnimationClip_Run].SetLoopFlag(true);
	//���j�e�B�����̃��f����ǂݍ���
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R����������
	m_characterController.Init(25.0f, 75.0f, m_position);

	m_gameCamera = FindGO<GameCamera>("gamecamera");

	//�Q�[���^�C�}�[
	m_gameTimer = FindGO<GameTimer>("gametimer");
}

Player::~Player()
{

}

//�X�V����
void Player::Update()
{
	//�X�e�[�g�Ǘ�
	ManageState();

	/*switch (m_playerState)
	{
	default:
		break;
	}*/

	//�ꎞ��~
	CoolTime();

	//�ړ�����
	Move();

	//��]����
	Rotation();

	//�A�j���[�V�����̍Đ�
	PlayAnimation();

	//�G�`������̍X�V����
	m_modelRender.Update();

}
	
void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�����̃x�N�g���������Ă���
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	//y�����ɂ͈ړ������Ȃ�
	forward.y = 0.0f;
	right.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ����Z����(�Ƃ肠����120.0�j
	right *= stickL.x * 300.0f;
	forward *= stickL.y * 300.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����
	m_moveSpeed += right + forward;


	//�ꎞ��~
	if (m_moveStop == true)
	{
		right *= stickL.x * 0.0f;
		forward *= stickL.y * 0.0f;

		//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����
		m_moveSpeed += right + forward;

		return;
	}

	////�͂��肽��(key��K�j
	//if (m_playerState == enPlayerRun)
	//{
	//	right *= stickL.x + 5.0f;
	//	forward *= stickL.y + 5.0f;
	//	moveSpeed += right + forward;
	//}

	//�L�����N�^�[�R���g���[�^�[���g���č��W���ړ�������
	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������
	m_modelRender.SetPosition(m_position);
}


void Player::Rotation()
{
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕�����ς���
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);

		//�G�`������ɉ�]��ς���
		m_modelRender.SetRotation(m_rotation);
	}
}

//�v���C���[�̓������ꎞ��~
void Player::CoolTime()
{
	if (m_moveStop == true)
	{
		m_stopTime += g_gameTime->GetFrameDeltaTime();
		if (m_stopTime >= STOP_TIME)
		{
			m_moveStop = false;
			m_stopTime = 0.0f;
		}
	}
}

//�X�e�[�g�Ǘ�
void Player::ManageState()
{
	//�n�ʂɂ��Ă��Ȃ�������
	if (m_characterController.IsOnGround() == false)
	{
		//�X�e�[�g��1(�W�����v��)�ɂ���
		m_playerState = enPlayerJump;
		//������ManageState�̏������I��点��
		return;
	}

	//�n�ʂɂ��Ă�����
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		//�X�e�[�g��2(����)�ɂ���
		m_playerState = enPlayerWalk;
		//m_gameTimer->m_isTimerStart = true;
	}
	else
	{
		//�e�[�g��0(�ҋ@)�ɂ���
		m_playerState = enPlayerIdle;
	}
}


//�A�j���[�V�����̍Đ�
void Player::PlayAnimation()
{
	//switch��
	switch (m_playerState)
	{
		//�v���C���[�̃X�e�[�g��0(�ҋ@)��������
	case enPlayerIdle:
		//�ҋ@�A�j���[�V�������Đ�����
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//�v���C���[�̃X�e�[�g��1(�W�����v��)��������
	case enPlayerJump:
		//�W�����v�A�j���[�V�������Đ�����
		m_modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
		//�v���C���[�X�e�[�g��2(����)��������
	case enPlayerWalk:
		//�����A�j���[�V�������Đ�����
		m_modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	case enPlayerRun:
		//����A�j���[�V�������Đ�
		m_modelRender.PlayAnimation(enAnimationClip_Run);
		break;
	}

}

//�`�揈��
void Player::Render(RenderContext& rc)
{
	//���j�e�B������`�悷��
	m_modelRender.Draw(rc);
}