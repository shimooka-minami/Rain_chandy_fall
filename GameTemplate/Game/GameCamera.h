#pragma once

class Player;

//�Q�[�����̃J�����𐧌䂷��
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	void LightCamera();

	//�����o�ϐ�
	Player* m_player; //�v���C���[
	Vector3 m_toCameraPos; //�����_����n�_�Ɍ������x�N�g��

	void Render(RenderContext&rc);
	bool m_isFPS = true;
};
