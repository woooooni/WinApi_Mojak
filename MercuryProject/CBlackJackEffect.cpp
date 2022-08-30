#include "pch.h"
#include "CSkillEffect.h"
#include "CAnimator.h"
#include "CResMgr.h"
#include "CTexture.h"
#include "CBlackJackEffect.h"



CBlackJackEffect::CBlackJackEffect()
	:CSkillEffect(Vec2(20, -50), true)
{
	CreateAnimator();
	CTexture* pTexEffect = CResMgr::GetInst()->LoadTexture(L"blackjack_effect", L"texture\\skill\\blackjack\\effect\\spritesheet.bmp");
	GetAnimator()->CreateAnimation(L"BLACKJACK_EFFECT_LEFT"
		, pTexEffect
		, Vec2(0, 0)
		, Vec2((float)pTexEffect->Width() / 20, (float)pTexEffect->Height() / 2)
		, Vec2((float)pTexEffect->Width() / 20, 0.f)
		, .05f
		, 20);

	GetAnimator()->CreateAnimation(L"BLACKJACK_EFFECT_RIGHT"
		, pTexEffect
		, Vec2(0.f, (float)pTexEffect->Height() / 2)
		, Vec2((float)pTexEffect->Width() / 20, (float)pTexEffect->Height() / 2)
		, Vec2((float)pTexEffect->Width() / 20, 0.f)
		, .05f
		, 20);
}

CBlackJackEffect::~CBlackJackEffect()
{

}

void CBlackJackEffect::init()
{
	assert(m_pFollowObj);
	if (m_pFollowObj->GetDir() == DIR::LEFT)
	{
		GetAnimator()->Play(L"BLACKJACK_EFFECT_LEFT", false);
	}
	else
	{
		GetAnimator()->Play(L"BLACKJACK_EFFECT_RIGHT", false);
	}
}

void CBlackJackEffect::update()
{
	if (m_bFollow && (m_pFollowObj != nullptr))
	{
		SetPos(m_pFollowObj->GetPos() + m_vOffsetPos);
	}

	if (GetAnimator()->IsFinished())
		DeleteObjectEvt(this);
}

void CBlackJackEffect::render(HDC _dc)
{
	component_render(_dc);
}


