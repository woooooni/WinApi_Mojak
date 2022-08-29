#include "pch.h"
#include "CProjectile.h"
#include "CTimeMgr.h"
#include "CCollider.h"

CProjectile::CProjectile()
	: m_fDuration(3.f)
	, m_fAcc(0.f)
{
}

CProjectile::~CProjectile()
{
}

void CProjectile::init()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(10.f, 10.f));
}

void CProjectile::update()
{
	m_fAcc += DeltaTime;
	Vec2 vPos = GetPos();
	if (GetDir() == DIR::LEFT)
	{
		vPos.x += 200.f * DeltaTime;
	}
	else
	{
		vPos.x -= 200.f * DeltaTime;
	}
	SetPos(vPos);

	if (m_fAcc >= m_fDuration)
	{
		DeleteObjectEvt(this);
	}
}

void CProjectile::render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);
	Rectangle(_dc,
		(int)(vRenderPos.x - vScale.x / 2.f),
		(int)(vRenderPos.y - vScale.y / 2.f),
		(int)(vRenderPos.x + vScale.x / 2.f),
		(int)(vRenderPos.y + vScale.y / 2.f));
}


