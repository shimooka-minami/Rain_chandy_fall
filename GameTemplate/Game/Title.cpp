#include "stdafx.h"
#include "Title.h"
#include "Controller.h"

Title::Title()
{
	//�^�C�g��
	spriteRender.Init("Assets/title/newtitle.dds", 1920.0f, 1080.0f);
}

Title::~Title()
{

}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Controller>(0, "controller");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}