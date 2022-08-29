#include "pch.h"
#include "CPlayerJump.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CStateMachine.h"
#include "CObject.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CRigidBody.h"
#include "CPlayer.h"

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
	CPlayer* pPlayer = (CPlayer*)GetStateMachine()->GetObj();
	wstring strName;
	if (pPlayer->GetDir() == DIR::LEFT)
		strName = GetStateName() + L"_LEFT";
	else
		strName = GetStateName() + L"_RIGHT";
	GetStateMachine()->GetAnimator()->Play(strName, true);
}

void CPlayerJump::update()
{
	CPlayer* pPlayer = (CPlayer*)GetStateMachine()->GetObj();
	CRigidBody* pRigid = pPlayer->GetRigidBody();

	if (pRigid->IsGround() == true)
	{
		GetStateMachine()->ChangeState(L"IDLE");
		return;
	}
	else
	{
		Vec2 vPos = pPlayer->GetPos();
		if (pRigid->GetVelocity().y > 0)
		{
			if(pPlayer->GetDir() == DIR::LEFT)
				GetStateMachine()->GetAnimator()->Play(L"JUMP_DOWN_LEFT", true);
			else
				GetStateMachine()->GetAnimator()->Play(L"JUMP_DOWN_RIGHT", true);
		}
		else
		{
			if (pPlayer->GetDir() == DIR::LEFT)
				GetStateMachine()->GetAnimator()->Play(L"JUMP_LEFT", true);
			else
				GetStateMachine()->GetAnimator()->Play(L"JUMP_RIGHT", true);
		}

		if (KEY_HOLD(KEY::LEFT_ARROW))
		{
			pPlayer->SetDir(DIR::LEFT);
			vPos.x -= 300.f * DeltaTime;
		}
		if (KEY_HOLD(KEY::RIGHT_ARROW))
		{
			pPlayer->SetDir(DIR::RIGHT);
			vPos.x += 300.f * DeltaTime;
		}
		pPlayer->SetPos(vPos);
	}
	
}

void CPlayerJump::Exit()
{
	m_bDoubleJump = false;
}


