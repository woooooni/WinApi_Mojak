#include "pch.h"
#include "CPlayer.h"
#include "CCollider.h"
#include "CRigidBody.h"
#include "CStateMachine.h"
#include "CAnimator.h"
#include "CKeyMgr.h"
#include "CAnimation.h"
#include "CTimeMgr.h"
#include "CResMgr.h"

CPlayer::CPlayer()
{
	
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::init()
{
	CreateCollider();
	Vec2 vScale = GetScale();
	GetCollider()->SetOffsetPos(Vec2(0.f, 5.f));
	GetCollider()->SetScale(Vec2(vScale.x, vScale.y));

	CreateRigidBody();
	GetRigidBody()->SetGravity(true);

	CreateAnimator();
	//Texture·Îµù
	CTexture* pTexIdle = CResMgr::GetInst()->LoadTexture(L"Jackson", L"texture\\jackson\\jackson.bmp");

	GetAnimator()->CreateAnimation(
									L"IDLE"
									, pTexIdle
									, Vec2(0.f, 0.f)
									, Vec2((float)pTexIdle->Width() / 3
										, (float)pTexIdle->Height())
									, Vec2((float)pTexIdle->Width() / 3, 0.f)
									, .5f
									, 3);
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();
	if (KEY_HOLD(KEY::UP_ARROW))
	{
		vPos.y -= 300.f * DeltaTime;
	}
	if (KEY_HOLD(KEY::DOWN_ARROW))
	{
		vPos.y += 300.f * DeltaTime;
	}
	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		vPos.x -= 300.f * DeltaTime;
	}
	if (KEY_HOLD(KEY::RIGHT_ARROW))
	{
		vPos.x += 300.f * DeltaTime;
	}
	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	/*Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);
	Ellipse(_dc,
		(int)(vRenderPos.x - vScale.x / 2.f),
		(int)(vRenderPos.y - vScale.y / 2.f),
		(int)(vRenderPos.x + vScale.x / 2.f),
		(int)(vRenderPos.y + vScale.y / 2.f));*/

	component_render(_dc);
}

void CPlayer::OnCollisionEnter(CCollider* _pOther)
{
}

void CPlayer::OnCollision(CCollider* _pOther)
{

}



void CPlayer::OnCollisionExit(CCollider* _pOther)
{
}

