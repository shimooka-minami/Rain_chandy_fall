#include "stdafx.h"
#include "Transparent.h"

Transparent::Transparent()
{
	//“§–¾‚È•Ç
	modelRender.Init("Assets/BackGround/kabe.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

Transparent::~Transparent()
{
}

void Transparent::Render(RenderContext& rc)
{
	//modelRender.Draw(rc);
}
