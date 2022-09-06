#include "pch.h"
#include "CPlayerIdle.h"
#include "CStateMachine.h"
#include "CAnimator.h"
#include "CRigidBody.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CPlayer.h"

CPlayerIdle::CPlayerIdle()
	: CState((int)PLAYER_STATE::IDLE)
{

}

CPlayerIdle::~CPlayerIdle()
{

}

void CPlayerIdle::Enter()
{
	//TODO : LEFT, RIGHT STATE를 두개 만들 필요가 없네..
	CPlayer* pObj = (CPlayer*)GetStateMachine()->GetObj();
	CRigidBody* pRigid = pObj->GetRigidBody();
	wstring strStateName;

	if (pObj->GetDir() == DIR::LEFT)
	{
		strStateName = L"IDLE_LEFT";
	}
	else
	{
		strStateName = L"IDLE_RIGHT";
	}
		

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
	CPlayer* pObj = (CPlayer*)GetStateMachine()->GetObj();
	CRigidBody* pRigid = pObj->GetRigidBody();

	if (KEY_TAP(KEY::SPACE))
	{
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::JUMP);
	}

	if (KEY_TAP(KEY::LEFT_ARROW) || KEY_TAP(KEY::RIGHT_ARROW))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
	}

	if (KEY_HOLD(KEY::RIGHT_ARROW) && KEY_HOLD(KEY::LEFT_ARROW))
	{
		return;
	}

	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		pObj->SetDir(DIR::LEFT);
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::MOVE);
		return;
	}

	if (KEY_HOLD(KEY::RIGHT_ARROW))
	{
		pObj->SetDir(DIR::RIGHT);
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::MOVE);
		return;
	}

	if (KEY_HOLD(KEY::DOWN_ARROW))
	{
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::PRONE);
		return;
	}
}
