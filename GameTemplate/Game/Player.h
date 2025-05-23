#pragma once
class GameCamera;
class GameTimer;

class Player : public IGameObject
{
public:
	Player();
	~Player();

	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void ManageState();
	void PlayAnimation();

	void CoolTime();

	//�����o�ϐ�
	ModelRender m_modelRender;  //���f�������_�[
	Vector3 m_position;  //���W
	enum EnAnimationClip  //�A�j���[�V����
	{
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];  //�A�j���[�V�����N���b�v
	CharacterController m_characterController;  //�L�����N�^�[�R���g���[�^�[
	Vector3 m_moveSpeed;  //�ړ����x
	Quaternion m_rotation;  //�N�H�[�^�j�I��
	GameCamera* m_gameCamera = nullptr;
	GameTimer* m_gameTimer = nullptr;

	enum PlayerState
	{
		enPlayerIdle,
		enPlayerWalk,
		enPlayerJump,
		enPlayerRun,
		enPlayerNum,
	};
	int m_playerState = enPlayerIdle;  //�v���C���[�̃X�e�[�g�i��ԁj��\���ϐ�
	
	//
	bool m_moveStop = false;
	float m_stopTime = 0.0f;
};

