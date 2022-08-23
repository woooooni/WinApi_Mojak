#include "pch.h"
#include "CPlayerJump.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CStateMachine.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CRigidBody.h"

CPlayerJump::CPlayerJump(wstring _strName)
	: CState(_strName)
	, m_bDoubleJump(false)
{
}

CPlayerJump::~CPlayerJump()
{
}

void CPlayerJump::Enter()
{
	wstring strName = GetStateName();
	GetStateMachine()->GetAnimator()->Play(strName, true);
}

void CPlayerJump::update()
{
	CObject* pObj = GetStateMachine()->GetObj();
	CRigidBody* pRigid = pObj->GetRigidBody();

	if (pRigid->IsGround() == true)
	{
		if (pObj->GetDir() == DIR::LEFT)
		{
			GetStateMachine()->ChangeState(L"IDLE_LEFT");
		}
		else
		{
			GetStateMachine()->ChangeState(L"IDLE_RIGHT");
		}
	}
	else
	{
		Vec2 vPos = pObj->GetPos();
		if (KEY_HOLD(KEY::LEFT_ARROW))
		{
			vPos.x -= 300.f * DeltaTime;
		}
		if (KEY_HOLD(KEY::RIGHT_ARROW))
		{
			vPos.x += 300.f * DeltaTime;
		}
		pObj->SetPos(vPos);

		if (GetStateName() == L"JUMP_DOWN_LEFT" || GetStateName() == L"JUMP_DOWN_RIGHT")
			return;

		if (pRigid->GetVelocity().y > 0)
		{
			if (pObj->GetDir() == DIR::LEFT)
			{
				GetStateMachine()->ChangeState(L"JUMP_DOWN_LEFT");
			}
			else
			{
				GetStateMachine()->ChangeState(L"JUMP_DOWN_RIGHT");
			}
		}
	}
	
}

void CPlayerJump::Exit()
{
	m_bDoubleJump = false;
}


