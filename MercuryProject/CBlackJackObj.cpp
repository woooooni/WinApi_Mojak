#include "pch.h"
#include "CBlackJackObj.h"
#include "CTexture.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CTimeMgr.h"
#include "CResMgr.h"


CBlackJackObj::CBlackJackObj(float _fDeleteTime)
	: m_fAccTime(0.f)
	, m_fDeleteTime(_fDeleteTime)
	, m_pTarget(nullptr)
{
	CreateAnimator();
	CTexture* pTexObj = CResMgr::GetInst()->LoadTexture(L"blackjack_obj", L"texture\\skill\\blackjack\\object\\spritesheet.bmp");
	GetAnimator()->CreateAnimation(L"BlackJackObj"
		, pTexObj
		, Vec2(0, 0)
		, Vec2((float)pTexObj->Width() / 8, (float)pTexObj->Height())
		, Vec2((float)pTexObj->Width() / 8, 0.f)
		, .05f
		, 8);
}

CBlackJackObj::~CBlackJackObj()
{

}

void CBlackJackObj::init()
{
	GetAnimator()->Play(L"BlackJackObj", true);
}

void CBlackJackObj::update()
{
	m_fAccTime += DeltaTime;
	if (m_fAccTime >= m_fDeleteTime)
		DeleteObjectEvt(this);
}

void CBlackJackObj::render(HDC _dc)
{
	component_render(_dc);
}
