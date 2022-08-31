#include "pch.h"
#include "CBlackJackObj.h"
#include "CTexture.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CTimeMgr.h"
#include "CResMgr.h"
#include "CCollider.h"

CBlackJackObj::CBlackJackObj(float _fDeleteTime)
	: m_iCount(3)
	, m_fAccTime(0.f)
	, m_fDeleteTime(_fDeleteTime)
	, m_pTarget(nullptr)
	, m_fSpeed(500.f)
{
	SetScale(Vec2(30, 30));

	CreateAnimator();
	CTexture* pTexObj = CResMgr::GetInst()->LoadTexture(L"blackjack_obj", L"texture\\skill\\blackjack\\object\\spritesheet.bmp");
	GetAnimator()->CreateAnimation(L"BlackJackObj"
		, pTexObj
		, Vec2(0, 0)
		, Vec2((float)pTexObj->Width() / 8, (float)pTexObj->Height())
		, Vec2((float)pTexObj->Width() / 8, 0.f)
		, .05f
		, 8);

	CreateCollider();
	GetCollider()->SetScale(GetScale());
	
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

	if (m_pTarget->IsDead())
	{
		m_pTarget = nullptr;
		return;
	}
		

	if (m_pTarget != nullptr)
	{
		Vec2 vPos = GetPos();
		Vec2 vTargetPos = m_pTarget->GetPos();

		float vDist = sqrt(((vPos.x - vTargetPos.x) * (vPos.x - vTargetPos.x)) + ((vPos.y - vTargetPos.y) * (vPos.y - vTargetPos.y)));
		Vec2 vDir = (vTargetPos - vPos) * m_fSpeed * DeltaTime;
		vDir.Normalize();

		Vec2 vNewPos = vPos + vDir * m_fSpeed * DeltaTime;
		if (vDist > 5.f)
			SetPos(vNewPos);
	}

	
}

void CBlackJackObj::render(HDC _dc)
{
	component_render(_dc);
}

void CBlackJackObj::OnCollisionEnter()
{
}

void CBlackJackObj::OnCollision()
{
}

void CBlackJackObj::OnCollisionExit()
{
}
