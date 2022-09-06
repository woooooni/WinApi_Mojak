#include "pch.h"
#include "CPlayerMove.h"
#include "CRigidBody.h"
#include "CStateMachine.h"
#include "CAnimator.h"
#include "CKeyMgr.h"
#include "CEventMgr.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CPlayer.h"

CPlayerMove::CPlayerMove()
	:CState((int)PLAYER_STATE::MOVE)
{
	
}

CPlayerMove::~CPlayerMove()
{
}

void CPlayerMove::Enter()
{
	CObject* pObj = GetStateMachine()->GetObj();
	wstring strStateName;
	if (pObj->GetDir() == DIR::LEFT)
		strStateName = L"MOVE_LEFT";
	else
		strStateName = L"MOVE_RIGHT";

	GetStateMachine()->GetAnimator()->Play(strStateName, true);
}

void CPlayerMove::update()
{
	PlayerMove();
}

void CPlayerMove::Exit()
{
}

void CPlayerMove::PlayerMove()
{
	CPlayer* pPlayer = (CPlayer*)GetStateMachine()->GetObj();
	CRigidBody* pRigid = pPlayer->GetRigidBody();
	Vec2 vPos = pPlayer->GetPos();

	if (KEY_TAP(KEY::SPACE))
	{	
		//TODO:: JUMP State·Î º¯°æ.
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::JUMP);
	}

	if (KEY_HOLD(KEY::RIGHT_ARROW) && KEY_HOLD(KEY::LEFT_ARROW))
	{
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::IDLE);
	}

	if (KEY_TAP(KEY::LEFT_ARROW))
	{
		pPlayer->SetDir(DIR::LEFT);
		GetStateMachine()->GetAnimator()->Play(L"MOVE_LEFT", true);
	}
		
	if (KEY_TAP(KEY::RIGHT_ARROW))
	{
		pPlayer->SetDir(DIR::RIGHT);
		GetStateMachine()->GetAnimator()->Play(L"MOVE_RIGHT", true);
	}
		

	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		if (pPlayer->GetDir() == DIR::LEFT)
			pRigid->SetVelocity(Vec2(0, 0));
		pRigid->AddVelocity(Vec2(-300.f, 0.f));
	}

	if (KEY_HOLD(KEY::RIGHT_ARROW))
	{
		if (pPlayer->GetDir() == DIR::RIGHT)
			pRigid->SetVelocity(Vec2(0, 0));
		pRigid->AddVelocity(Vec2(300.f, 0.f));
	}
	

	if ((KEY_NONE(KEY::RIGHT_ARROW) && KEY_NONE(KEY::LEFT_ARROW)))
	{
		pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::IDLE);
	}
	GetStateMachine()->GetObj()->SetPos(vPos);
}

