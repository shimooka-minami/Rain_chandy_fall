#pragma once

//�^�C�g��
class Title : public IGameObject
{
public:
	Title();
	~Title();

	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
};

