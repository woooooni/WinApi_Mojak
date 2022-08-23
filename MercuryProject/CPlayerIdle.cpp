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
	if (KEY_TAP(KEY::SPACE))
	{
		pRigid->SetGround(false);
		pRigid->SetVelocity(Vec2(pRigid->GetVelocity().x, -500.f));
		if (pObj->GetDir() == DIR::LEFT)
		{
			GetStateMachine()->ChangeState(L"JUMP_LEFT");
		}
		else 
		{
			GetStateMachine()->ChangeState(L"JUMP_RIGHT");
		}
	}

	if (KEY_TAP(KEY::SHIFT))
	{
		pRigid->AddVelocity(Vec2(1001.f, pRigid->GetVelocity().y));
	}

	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
		pObj->SetDir(DIR::LEFT);
		GetStateMachine()->ChangeState(L"MOVE_LEFT");
	}

	if (KEY_HOLD(KEY::RIGHT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
		pObj->SetDir(DIR::RIGHT);
		GetStateMachine()->ChangeState(L"MOVE_RIGHT");
	}
}
