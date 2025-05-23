#include "stdafx.h"
#include "MakeEffect.h"

MakeEffect::MakeEffect()
{
}

MakeEffect::~MakeEffect()
{
}

bool MakeEffect::Start()
{
	EffectEngine::GetInstance()->ResistEffect(enEffectName_Chandy, u"Assets/Effect/chandypikapika.efk");
	EffectEngine::GetInstance()->ResistEffect(enEffectName_Rain, u"Assets/Effect/rainhit.efk");
	return true;
}

void MakeEffect::Updata()
{
}

void MakeEffect::Render(RenderContext& rc)
{
}
