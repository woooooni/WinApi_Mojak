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

CPlayerMove::CPlayerMove(wstring _strName)
	:CState(_strName)
{
	
}

CPlayerMove::~CPlayerMove()
{
}

void CPlayerMove::Enter()
{
	wstring strStateName = GetStateName();
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
		pRigid->SetGround(false);

		//TODO:: JUMP State·Î º¯°æ.
		pRigid->AddVelocity(Vec2(pRigid->GetVelocity().x, -500.f));
		
		if (pPlayer->GetDir() == DIR::LEFT)
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
		pRigid->AddVelocity(Vec2(2000.f, pRigid->GetVelocity().y));
	}

	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		vPos.x -= 300.f * DeltaTime;
	}
	if (KEY_HOLD(KEY::RIGHT_ARROW))
	{
		vPos.x += 300.f * DeltaTime;
	}

	if (KEY_AWAY(KEY::RIGHT_ARROW) || KEY_AWAY(KEY::LEFT_ARROW))
	{
		if (pPlayer->GetDir() == DIR::LEFT)
		{
			GetStateMachine()->ChangeState(L"IDLE_LEFT");
		}
		else
		{
			GetStateMachine()->ChangeState(L"IDLE_RIGHT");
		}
	}
	GetStateMachine()->GetObj()->SetPos(vPos);
}

