#pragma once

class Player;

//ゲーム中のカメラを制御する
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	void LightCamera();

	//メンバ変数
	Player* m_player; //プレイヤー
	Vector3 m_toCameraPos; //注視点から始点に向かうベクトル

	void Render(RenderContext&rc);
	bool m_isFPS = true;
};
