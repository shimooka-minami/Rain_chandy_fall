#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//ÉXÉeÅ[ÉWîwåi
	modelRender.Init("Assets/BackGround/mappp.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}