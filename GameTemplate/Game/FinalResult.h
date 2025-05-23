#pragma once


class ScoreResult;
class BackGround;
class Transparent;
//class ICreation;

class FinalResult : public IGameObject
{
public:
	FinalResult();
	~FinalResult();

	void Update();
	void Display();

	void Render(RenderContext& rc);

	ScoreResult* m_scorer;
	BackGround* m_background;
	Transparent* m_transparent;
	//ICreation* m_iCreation;


	SpriteRender m_finalrRender;
	SpriteRender m_rankC_Sprite;
	SpriteRender m_rankB_Sprite;
	SpriteRender m_rankA_Sprite;

	SoundSource* m_finBGM;

	//リザルトスコアの代入先
	int m_finalScore = 0;

	//フォント
	FontRender m_FontRender;

	Vector3 m_position = Vector3::Zero;
	Vector3 m_scale = Vector3::One;

};

