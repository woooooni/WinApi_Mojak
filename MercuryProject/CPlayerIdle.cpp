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
	//TODO : LEFT, RIGHT STATE를 두개 만들 필요가 없네..
	CObject* pObj = GetStateMachine()->GetObj();
 	wstring strStateName = GetStateName();

	if (pObj->GetDir() == DIR::LEFT)
		strStateName += L"_LEFT";
	else
		strStateName += L"_RIGHT";
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
	if (KEY_TAP(KEY::SPACE))
	{
		pRigid->SetGround(false);
		pRigid->SetVelocity(Vec2(pRigid->GetVelocity().x, -500.f));
		GetStateMachine()->ChangeState(L"JUMP");
	}

	if (KEY_TAP(KEY::SHIFT))
	{
		pRigid->AddVelocity(Vec2(1001.f, pRigid->GetVelocity().y));
	}

	if (KEY_TAP(KEY::LEFT_ARROW) || KEY_TAP(KEY::RIGHT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
	}

	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		pObj->SetDir(DIR::LEFT);
		GetStateMachine()->ChangeState(L"MOVE");
		return;
	}

	if (KEY_HOLD(KEY::RIGHT_ARROW))
	{
		pObj->SetDir(DIR::RIGHT);
		GetStateMachine()->ChangeState(L"MOVE");
		return;
	}
}
