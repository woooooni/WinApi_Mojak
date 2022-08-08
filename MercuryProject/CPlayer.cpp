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
#include "CRole.h";
#include "CRoleAssasin.h";
CPlayer::CPlayer()
{
	
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::init()
{
	//m_pRole = new CRoleAssasin;
	//m_pRole->SetOwner(this);

	CreateRigidBody();
	GetRigidBody()->SetGravity(true);

	CreateCollider();
	Vec2 vScale = GetScale();
	GetCollider()->SetOffsetPos(Vec2(0.f, 10.f));
	GetCollider()->SetScale(Vec2(vScale.x - 50.f, vScale.y - 5.f));

	CreateAnimator();
	//Texture·Îµù
	CTexture* pTexCharacter = CResMgr::GetInst()->LoadTexture(L"character", L"texture\\character\\character_1.bmp");
	
	GetAnimator()->CreateAnimation(
		L"IDLE"
		, pTexCharacter
		, Vec2(0.f, 0.f)
		, Vec2((float)pTexCharacter->Width() / 9
			, (float)pTexCharacter->Height() / 6)
		, Vec2((float)pTexCharacter->Width() / 9, 0.f)
		, .2f
		, 3);

	
	GetAnimator()->CreateAnimation(
		L"MOVE"
		, pTexCharacter
		, Vec2(588.f, 0.f)
		, Vec2((float)pTexCharacter->Width() / 9
			, (float)pTexCharacter->Height() / 6)
		, Vec2((float)pTexCharacter->Width() / 9, 0.f)
		, .2f
		, 3);

	GetAnimator()->Play(L"MOVE", true);
}

void CPlayer::update()
{
	CRigidBody* pRigid = GetRigidBody();
	Vec2 vPos = GetPos();
	if (KEY_TAP(KEY::SPACE))
	{
		pRigid->SetGround(false);
		pRigid->SetVelocity(Vec2(pRigid->GetVelocity().x, -400.f));
	}
	if (KEY_TAP(KEY::SHIFT))
	{
		pRigid->AddVelocity(Vec2(1001.f, pRigid->GetVelocity().y));
	}

	//KEY_TAP
	if (KEY_TAP(KEY::LEFT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
	}
	if (KEY_TAP(KEY::RIGHT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
	}

	if (KEY_TAP(KEY::SPACE))
	{
		pRigid->SetGround(false);
		pRigid->SetVelocity(Vec2(pRigid->GetVelocity().x, -400.f));
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
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		CRigidBody* rigid = GetRigidBody();
		if (rigid == nullptr)
			return;

		rigid->SetGround(true);
	}
}

void CPlayer::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		CRigidBody* rigid = GetRigidBody();
		if (rigid == nullptr)
			return;

		rigid->SetGround(true);
	}
}



void CPlayer::OnCollisionExit(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		CRigidBody* rigid = GetRigidBody();
		if (rigid == nullptr)
			return;

		rigid->SetGround(false);
	}
}

