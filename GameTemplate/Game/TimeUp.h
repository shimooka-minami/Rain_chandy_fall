#pragma once
#include "sound/SoundSource.h"

class TimeUp : public IGameObject
{
public:
	TimeUp();
	~TimeUp();

	void Update();
	void Render(RenderContext& rc);

//private:
	SpriteRender spriteRender;

	SoundSource* m_timeUpBGM;
};

