#include "stdafx.h"
#include "FinalResult.h"

#include "ScoreResult.h"
#include "ICreation.h"

#include "Title.h"
#include "BackGround.h"
#include "Transparent.h"

FinalResult::FinalResult()
{
	//タイトル
	m_finalrRender.Init("Assets/title/scorer.dds", 1920.0f, 1080.0f);
	//ステージ
	m_background = FindGO<BackGround>("ground");
	//透明な壁
	m_transparent = FindGO<Transparent>("transparent");
	//スコアリザルト
	m_scorer = FindGO<ScoreResult>("scoreresult");

	g_soundEngine->ResistWaveFileBank(2, "Assets/bgm/finbgm.wav");
	m_finBGM = NewGO<SoundSource>(2);
	m_finBGM->Init(2);
	m_finBGM->Play(false);


	//ランクA
	m_rankA_Sprite.Init("Assets/title/scoreA.dds", 1920.f, 1080.0f);
	m_rankA_Sprite.SetPosition(m_position);
	m_rankA_Sprite.SetScale(m_scale);
	m_rankA_Sprite.Update();

	//ランクB
	m_rankB_Sprite.Init("Assets/title/scoreB.dds", 1920.f, 1080.0f);
	m_rankB_Sprite.SetPosition(m_position);
	m_rankB_Sprite.SetScale(m_scale);
	m_rankB_Sprite.Update();

	//ランクC
	m_rankC_Sprite.Init("Assets/title/scoreC.dds", 1920.f, 1080.0f);
	m_rankC_Sprite.SetPosition(m_position);
	m_rankC_Sprite.SetScale(m_scale);
	m_rankC_Sprite.Update();

	return;
}

FinalResult::~FinalResult()
{

}

void FinalResult::Update()
{
	Display();

	if (g_pad[0]->IsPress(enButtonA))
	{
		NewGO<Title>(0, "title");
		//背景を削除する
		DeleteGO(m_scorer);
		DeleteGO(m_background);
		DeleteGO(m_transparent);
		DeleteGO(this);
	}
}

//スコア表示したーい
void FinalResult::Display()
{
	m_finalScore = m_scorer->m_resultScore;

	wchar_t scorew[256];
	swprintf_s(scorew, 256, L"%d", int(m_finalScore));

	m_FontRender.SetText(scorew);
	m_FontRender.SetPosition({ 300.0f, -20.0f, 0.0f });
	m_FontRender.SetScale(2.0);
	m_FontRender.SetColor(g_vec4Black);
	//m_FontRender.Update();
}

void FinalResult::Render(RenderContext& rc)
{
	//ランク表示
	if (m_finalScore >= 1800)
	{
		m_rankA_Sprite.Draw(rc);
	}
	else if (m_finalScore >=1000)
	{
		m_rankB_Sprite.Draw(rc);
	}
	else 
	{
		m_rankC_Sprite.Draw(rc);
	}

	//m_rankC_Sprite.Draw(rc);

	//UI
	m_finalrRender.Draw(rc);
	//フォント
	m_FontRender.Draw(rc);
}


