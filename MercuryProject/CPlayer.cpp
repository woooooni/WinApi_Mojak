#include "pch.h"
#include "CPlayer.h"
#include "CCollider.h"
#include "CRigidBody.h"
#include "CStateMachine.h"
#include "CAnimator.h"
#include "CKeyMgr.h"
#include "CAnimation.h"
#include "CTimeMgr.h"
#include "CResMgr.h"
#include "CRole.h";
#include "CRoleAssasin.h";
#include "CState.h"
#include "CPlayerIdle.h"
#include "CPlayerMove.h"
#include "CPlayerJump.h"

CPlayer::CPlayer()
{
	
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::init()
{
	//m_pRole = new CRoleAssasin;
	//m_pRole->SetOwner(this);

	CreateRigidBody();
	GetRigidBody()->SetGravity(true);

	CreateCollider();
	Vec2 vScale = GetScale();
	GetCollider()->SetOffsetPos(Vec2(0.f, -5.f));
	GetCollider()->SetScale(Vec2(vScale.x - 50.f, vScale.y - 5.f));

	CreateAnimator();
	//Texture·Îµù
	CTexture* pTexLeftCharacter = CResMgr::GetInst()->LoadTexture(L"amelia_left", L"texture\\character\\amelia_left.bmp");
	CTexture* pTexRightCharacter = CResMgr::GetInst()->LoadTexture(L"amelia_right", L"texture\\character\\amelia_right.bmp");

	
	GetAnimator()->CreateAnimation(
		L"IDLE_LEFT"
		, pTexLeftCharacter
		, Vec2(0, 0)
		, Vec2((float)pTexLeftCharacter->Width() / 6
			, (float)pTexLeftCharacter->Height() / 6)
		, Vec2((float)pTexLeftCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"IDLE_RIGHT"
		, pTexRightCharacter
		, Vec2(0, 0)
		, Vec2((float)pTexRightCharacter->Width() / 6
			, (float)pTexRightCharacter->Height() / 6)
		, Vec2((float)pTexRightCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"MOVE_LEFT"
		, pTexLeftCharacter
		, Vec2(330, 0)
		, Vec2((float)pTexLeftCharacter->Width() / 6
			, (float)pTexLeftCharacter->Height() / 6)
		, Vec2((float)pTexLeftCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"MOVE_RIGHT"
		, pTexRightCharacter
		, Vec2(330, 0)
		, Vec2((float)pTexRightCharacter->Width() / 6
			, (float)pTexRightCharacter->Height() / 6)
		, Vec2((float)pTexRightCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"JUMP_LEFT"
		, pTexLeftCharacter
		, Vec2(0, 111)
		, Vec2((float)pTexLeftCharacter->Width() / 6
			, (float)pTexLeftCharacter->Height() / 6)
		, Vec2((float)pTexLeftCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"JUMP_RIGHT"
		, pTexRightCharacter
		, Vec2(0, 111)
		, Vec2((float)pTexRightCharacter->Width() / 6
			, (float)pTexRightCharacter->Height() / 6)
		, Vec2((float)pTexRightCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"JUMP_DOWN_LEFT"
		, pTexLeftCharacter
		, Vec2(330, 111)
		, Vec2((float)pTexLeftCharacter->Width() / 6
			, (float)pTexLeftCharacter->Height() / 6)
		, Vec2((float)pTexLeftCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	GetAnimator()->CreateAnimation(
		L"JUMP_DOWN_RIGHT"
		, pTexRightCharacter
		, Vec2(330, 111)
		, Vec2((float)pTexRightCharacter->Width() / 6
			, (float)pTexRightCharacter->Height() / 6)
		, Vec2((float)pTexRightCharacter->Width() / 6, 0.f)
		, .2f
		, 3);

	CreateStateMachine();
	GetStateMachine()->AddState(new CPlayerIdle(L"IDLE"));
	GetStateMachine()->AddState(new CPlayerMove(L"MOVE"));
	GetStateMachine()->AddState(new CPlayerJump(L"JUMP"));

	GetStateMachine()->ChangeState(L"JUMP");
}

void CPlayer::update()
{
	//CRigidBody* pRigid = GetRigidBody();
	//Vec2 vPos = GetPos();
	//if (KEY_TAP(KEY::SPACE))
	//{
	//	pRigid->SetGround(false);
	//	pRigid->SetVelocity(Vec2(pRigid->GetVelocity().x, -400.f));
	//}
	//if (KEY_TAP(KEY::SHIFT))
	//{
	//	pRigid->AddVelocity(Vec2(1001.f, pRigid->GetVelocity().y));
	//}

	////KEY_TAP
	//if (KEY_TAP(KEY::LEFT_ARROW))
	//{
	//	
	//	pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
	//}
	//if (KEY_TAP(KEY::RIGHT_ARROW))
	//{
	//	pRigid->SetVelocity(Vec2(0.f, pRigid->GetVelocity().y));
	//}

	//if (KEY_TAP(KEY::SPACE))
	//{
	//	pRigid->SetGround(false);
	//	pRigid->SetVelocity(Vec2(pRigid->GetVelocity().x, -400.f));
	//}

	//if (KEY_HOLD(KEY::LEFT_ARROW))
	//{
	//	vPos.x -= 300.f * DeltaTime;
	//}
	//if (KEY_HOLD(KEY::RIGHT_ARROW))
	//{
	//	vPos.x += 300.f * DeltaTime;
	//}
	//SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	/*Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(vPos);
	Ellipse(_dc,
		(int)(vRenderPos.x - vScale.x / 2.f),
		(int)(vRenderPos.y - vScale.y / 2.f),
		(int)(vRenderPos.x + vScale.x / 2.f),
		(int)(vRenderPos.y + vScale.y / 2.f));*/

	component_render(_dc);
}

void CPlayer::OnCollisionEnter(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		
	}
}

void CPlayer::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{

	}
}



void CPlayer::OnCollisionExit(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		CRigidBody* rigid = GetRigidBody();
		if (rigid == nullptr)
			return;
	}
}

