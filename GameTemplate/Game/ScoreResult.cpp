#include "stdafx.h"
#include "ScoreResult.h"

#include "Game.h"
#include "Player.h"
//#include "ICreation.h"


ScoreResult::ScoreResult()
{
	//タイトル
	//spriteRender.Init("Assets/title/karis.dds", 1920.0f, 1080.0f);
}

ScoreResult::~ScoreResult()
{

}

void ScoreResult::Update()
{
	ResultScore();

	//if (g_pad[0]->IsTrigger(enButtonA))
	//{
	//	NewGO<Game>(0, "title");
	//	DeleteGO(this);
	//}
}


//トータルスコア
void ScoreResult::ResultScore()
{
	wchar_t scorew[256];
	swprintf_s(scorew, 256, L"%dてん", int(m_resultScore));

	m_ScoreFontRender.SetText(scorew);
	m_ScoreFontRender.SetPosition({ 700.0f, 480.0f, 0.0f });
	m_ScoreFontRender.SetScale(1.0);
	m_ScoreFontRender.SetColor(g_vec4Black);
}

void ScoreResult::Render(RenderContext& rc)
{
	//m_resultRender.Draw(rc);
	//spriteRender.Draw(rc);
	m_ScoreFontRender.Draw(rc);
}
