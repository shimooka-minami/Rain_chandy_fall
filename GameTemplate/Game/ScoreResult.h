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
	
	//resultScore�Ɉ��̃X�R�A����
	void SetScore(int score) {
		m_resultScore += score;
	};

	

	FontRender m_resultRender;
	SpriteRender spriteRender;

	//Score
	FontRender m_ScoreFontRender;

	//�����o�ϐ�
	int m_resultScore = 0;

	
};

