#pragma once
class Game;
class GameStart : public IGameObject
{
public:
	GameStart();
	~GameStart();

	void Update();
	void Render(RenderContext& rc);

	Game* m_game;
	SpriteRender spriteRender;
};

