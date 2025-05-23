#include "stdafx.h"
#include "TimeUp.h"

#include "FinalResult.h"

TimeUp::TimeUp()
{
	spriteRender.Init("Assets/title/timeupyo.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(1, "Assets/bgm/timebgm.wav");
	//
	m_timeUpBGM = NewGO<SoundSource>(1);
	m_timeUpBGM->Init(1);
	m_timeUpBGM->Play(false);
}

TimeUp::~TimeUp()
{
	
}

void TimeUp::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<FinalResult>(0, "finalresult");
		DeleteGO(this);
	}
}

void TimeUp::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}