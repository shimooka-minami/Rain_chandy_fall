#pragma once

class Transparent : public IGameObject
{
public:
	Transparent();
	~Transparent();

	void Render(RenderContext& rc);

	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
};

