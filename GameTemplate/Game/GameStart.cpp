#include "stdafx.h"
#include "GameStart.h"
#include "Game.h"

GameStart::GameStart()
{
	//ゲームスタート
	spriteRender.Init("Assets/title/startplz.dds", 1920.0f, 1080.0f);

	m_game = FindGO<Game>("game");
}

GameStart::~GameStart()
{

}

void GameStart::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//m_game->StartGame();
		DeleteGO(this);
	}
}

void GameStart::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
