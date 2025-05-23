#pragma once

class ICreation;
class Game;
class FinalResult;
class ScoreResult : public IGameObject
{
public:
	ScoreResult();
	~ScoreResult();

	void Update();
	void ResultScore();
	void Render(RenderContext& rc);
	
	//resultScoreに飴のスコアを代入
	void SetScore(int score) {
		m_resultScore += score;
	};

	

	FontRender m_resultRender;
	SpriteRender spriteRender;

	//Score
	FontRender m_ScoreFontRender;

	//メンバ変数
	int m_resultScore = 0;

	
};

