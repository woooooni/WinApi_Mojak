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
	CRigidBody* pRigid = pPlayer->GetRigidBody();
	m_eEnterDir = pPlayer->GetDir();

	wstring strName;
	if (pPlayer->GetDir() == DIR::LEFT)
		strName = GetStateName() + L"_LEFT";
	else
		strName = GetStateName() + L"_RIGHT";
	GetStateMachine()->GetAnimator()->Play(strName, true);

	pRigid->SetGround(false);
	
	pRigid->AddVelocity(Vec2(0.f, -400.f));
}

void CPlayerJump::update()
{
	CPlayer* pPlayer = (CPlayer*)GetStateMachine()->GetObj();
	CRigidBody* pRigid = pPlayer->GetRigidBody();

	if (pRigid->IsGround() == true)
	{
		GetStateMachine()->ChangeState(L"IDLE");
		pRigid->SetVelocity(Vec2(0.f, 0.f));
		return;
	}
	else
	{
		Vec2 vPos = pPlayer->GetPos();

		if (KEY_HOLD(KEY::LEFT_ARROW))
		{
			pPlayer->SetDir(DIR::LEFT);
		}
		if (KEY_HOLD(KEY::RIGHT_ARROW))
		{
			pPlayer->SetDir(DIR::RIGHT);
		}
		pPlayer->SetPos(vPos);

		if (KEY_TAP(KEY::SPACE) && !m_bDoubleJump)
		{
			if(pPlayer->GetDir() == DIR::LEFT)
				pRigid->AddVelocity(Vec2(-500.f, -50.f));          
			else
				pRigid->AddVelocity(Vec2(500.f, -50.f));

			m_eEnterDir = pPlayer->GetDir();
			m_bDoubleJump = true;
		}
	}

	if (pPlayer->GetDir() == DIR::LEFT)
	{
		GetStateMachine()->GetAnimator()->Play(L"JUMP_LEFT", true);
	}
	else
	{
		GetStateMachine()->GetAnimator()->Play(L"JUMP_RIGHT", true);
	}
	
}

void CPlayerJump::Exit()
{
	m_bDoubleJump = false;
}


