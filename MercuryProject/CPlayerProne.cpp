#include "pch.h"
#include "CPlayerProne.h"
#include "CKeyMgr.h"
#include "CStateMachine.h"
#include "CObject.h"
#include "CAnimator.h"
#include "CCollider.h"
#include "CRigidBody.h"

CPlayerProne::CPlayerProne()
	:CState((int)PLAYER_STATE::PRONE)
{

}

CPlayerProne::~CPlayerProne()
{
}


void CPlayerProne::Enter()
{
	wstring _strName;
	CObject* _pObj = GetStateMachine()->GetObj();
	CCollider* _pCollider = _pObj->GetCollider();
	CRigidBody* _pRigid = _pObj->GetRigidBody();
	


	if (_pObj->GetDir() == DIR::LEFT)
		_strName += L"PRONE_LEFT";
	else
		_strName += L"PRONE_RIGHT";
	GetStateMachine()->GetAnimator()->Play(_strName, true);

}

void CPlayerProne::update()
{
	PlayerMove();
}

void CPlayerProne::Exit()
{
	
}


void CPlayerProne::PlayerMove()
{
	if (KEY_AWAY(KEY::DOWN_ARROW))
		GetStateMachine()->ChangeState((UINT)PLAYER_STATE::IDLE);
}
