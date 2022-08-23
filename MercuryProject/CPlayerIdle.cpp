#include "pch.h"
#include "CPlayerIdle.h"
#include "CStateMachine.h"
#include "CAnimator.h"
#include "CRigidBody.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

CPlayerIdle::CPlayerIdle(wstring _strName)
	: CState(_strName)
{

}

CPlayerIdle::~CPlayerIdle()
{

}

void CPlayerIdle::Enter()
{
	wstring strStateName = GetStateName();
	GetStateMachine()->GetAnimator()->Play(strStateName, true);
}

void CPlayerIdle::update()
{
	PlayerMove();
}

void CPlayerIdle::Exit()
{

}

void CPlayerIdle::PlayerMove()
{
	CObject* pObj = GetStateMachine()->GetObj();
	CRigidBody* pRigid = pObj->GetRigidBody();
	Vec2 vPos = pObj->GetPos();
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
		pObj->SetDir(-1);
		pObj->GetAnimator()->Play(L"IDLE_LEFT", true);
	}
	if (KEY_TAP(KEY::RIGHT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
		pObj->SetDir(1);
		pObj->GetAnimator()->Play(L"IDLE_RIGHT", true);
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
	GetStateMachine()->GetObj()->SetPos(vPos);
}
