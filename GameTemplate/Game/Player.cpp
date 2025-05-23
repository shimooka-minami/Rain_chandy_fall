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
	//アニメーションクリップのロード
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	m_animationClips[enAnimationClip_Run].SetLoopFlag(true);
	//ユニティちゃんのモデルを読み込む
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);

	//キャラコンを初期化
	m_characterController.Init(25.0f, 75.0f, m_position);

	m_gameCamera = FindGO<GameCamera>("gamecamera");

	//ゲームタイマー
	m_gameTimer = FindGO<GameTimer>("gametimer");
}

Player::~Player()
{

}

//更新処理
void Player::Update()
{
	//ステート管理
	ManageState();

	/*switch (m_playerState)
	{
	default:
		break;
	}*/

	//一時停止
	CoolTime();

	//移動処理
	Move();

	//回転処理
	Rotation();

	//アニメーションの再生
	PlayAnimation();

	//絵描きさんの更新処理
	m_modelRender.Update();

}
	
void Player::Move()
{
	//xzの移動速度を0.0fにする
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	//左スティックの入力量を取得
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向のベクトルを持ってくる
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	//y方向には移動させない
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量を加算する(とりあえず120.0）
	right *= stickL.x * 300.0f;
	forward *= stickL.y * 300.0f;

	//移動速度にスティックの入力量を加算する
	m_moveSpeed += right + forward;


	//一時停止
	if (m_moveStop == true)
	{
		right *= stickL.x * 0.0f;
		forward *= stickL.y * 0.0f;

		//移動速度にスティックの入力量を加算する
		m_moveSpeed += right + forward;

		return;
	}

	////はしりたい(keyはK）
	//if (m_playerState == enPlayerRun)
	//{
	//	right *= stickL.x + 5.0f;
	//	forward *= stickL.y + 5.0f;
	//	moveSpeed += right + forward;
	//}

	//キャラクターコントローターを使って座標を移動させる
	m_position = m_characterController.Execute(m_moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える
	m_modelRender.SetPosition(m_position);
}


void Player::Rotation()
{
	//xかzの移動速度があったら(スティックの入力があったら)
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		//キャラクターの方向を変える
		m_rotation.SetRotationYFromDirectionXZ(m_moveSpeed);

		//絵描きさんに回転を変える
		m_modelRender.SetRotation(m_rotation);
	}
}

//プレイヤーの動きを一時停止
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

//ステート管理
void Player::ManageState()
{
	//地面についていなかったら
	if (m_characterController.IsOnGround() == false)
	{
		//ステートを1(ジャンプ中)にする
		m_playerState = enPlayerJump;
		//ここでManageStateの処理を終わらせる
		return;
	}

	//地面についていたら
	//xかzの移動速度があったら(スティックの入力があったら)
	if (fabsf(m_moveSpeed.x) >= 0.001f || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		//ステートを2(歩き)にする
		m_playerState = enPlayerWalk;
		//m_gameTimer->m_isTimerStart = true;
	}
	else
	{
		//テートを0(待機)にする
		m_playerState = enPlayerIdle;
	}
}


//アニメーションの再生
void Player::PlayAnimation()
{
	//switch文
	switch (m_playerState)
	{
		//プレイヤーのステートが0(待機)だったら
	case enPlayerIdle:
		//待機アニメーションを再生する
		m_modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//プレイヤーのステートが1(ジャンプ中)だったら
	case enPlayerJump:
		//ジャンプアニメーションを再生する
		m_modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
		//プレイヤーステートが2(歩き)だったら
	case enPlayerWalk:
		//歩きアニメーションを再生する
		m_modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	case enPlayerRun:
		//走るアニメーションを再生
		m_modelRender.PlayAnimation(enAnimationClip_Run);
		break;
	}

}

//描画処理
void Player::Render(RenderContext& rc)
{
	//ユニティちゃんを描画する
	m_modelRender.Draw(rc);
}