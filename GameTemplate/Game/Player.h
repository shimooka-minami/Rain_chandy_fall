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

	//メンバ変数
	ModelRender m_modelRender;  //モデルレンダー
	Vector3 m_position;  //座標
	enum EnAnimationClip  //アニメーション
	{
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];  //アニメーションクリップ
	CharacterController m_characterController;  //キャラクターコントローター
	Vector3 m_moveSpeed;  //移動速度
	Quaternion m_rotation;  //クォータニオン
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
	int m_playerState = enPlayerIdle;  //プレイヤーのステート（状態）を表す変数
	
	//
	bool m_moveStop = false;
	float m_stopTime = 0.0f;
};

