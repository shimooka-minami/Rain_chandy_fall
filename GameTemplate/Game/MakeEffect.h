#pragma once

enum EffectName
{
	enEffectName_Chandy,
	enEffectName_Rain,
	enEffectName_Num,
};

class MakeEffect : public IGameObject
{
public:
	MakeEffect();
	~MakeEffect();
	bool Start();
	void Updata();
	void Render(RenderContext& rc);
};

