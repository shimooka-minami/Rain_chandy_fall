#include "stdafx.h"
#include "Controller.h"
#include "GameStart.h"
#include "Game.h"

Controller::Controller()
{
	//‘€ìà–¾
	spriteRender.Init("Assets/title/sousa.dds", 1920.0f, 1080.0f);
}

Controller::~Controller()
{
}

void Controller::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<GameStart>(0, "gamestart");
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Controller::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
