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

	//注視点から視点までのベクトルを設定
	m_toCameraPos.Set(0.0f, 500.0f, -1000.0f);

	//プレイヤーのインスタンスを探す
	m_player = FindGO<Player>("player");

	//カメラのニアクリップとファークリップを設定する
	g_camera3D->SetNear(1.0f);
	g_camera3D->SetFar(10000.0f);

	return true;
}

void GameCamera::Update()
{
	//カメラを更新

	//注視点を計算する //画面の固定
	Vector3 target;
	//プレイヤーの足元からちょっと上を注視点とする
	target.y += 100.0f;

	Vector3 toCameraPosOld = m_toCameraPos;

	//視点を計算する
	Vector3 pos = target + m_toCameraPos;

	//メインカメラに注視点と視点を設定する
	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	//カメラの更新
	g_camera3D->Update();

	LightCamera();
}

//ライトカメラ
void GameCamera::LightCamera()
{
	//K2engineのシーンライト化rディレクションライトを持ってくる
	//0は配列、ポジションはライトの方向、カラーはライトの色
	g_sceneLight->SetDirectionLight(0, Vector3::Down, Vector3{ 1.0f,1.0f,1.0f });
}

void GameCamera::Render(RenderContext& rc)
{

}
