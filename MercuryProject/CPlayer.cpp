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
#include "CProjectile.h"
#include "CSkillEffect.h"
#include "CBlackJackEffect.h"
#include "CSkill_BlackJack.h"
#include "CPlayerDamaged.h"
#include "CPlayerProne.h"

CPlayer::CPlayer()
	: m_bMoveAble(true)
{
	
}

CPlayer::~CPlayer()
{
	if (m_pRole != nullptr)
		delete m_pRole;
}

void CPlayer::init()
{
	//m_pRole = new CRoleAssasin;
	//m_pRole->SetOwner(this);
	SetScale(Vec2(100.f, 100.f));

	CreateRigidBody();
	GetRigidBody()->SetGravity(true);

	CreateCollider();
	Vec2 vScale = GetScale();
	GetCollider()->SetOffsetPos(Vec2(0.f, -7.f));
	GetCollider()->SetScale(Vec2(vScale.x - 50.f, vScale.y - 20.f));

	CreateAnimator();
	//Texture·Îµù
	CTexture* pTexCharacterIdle = CResMgr::GetInst()->LoadTexture(L"phantom_idle", L"texture\\character\\idle\\spritesheet.bmp");
	CTexture* pTexCharacterMove = CResMgr::GetInst()->LoadTexture(L"phantom_move", L"texture\\character\\move\\spritesheet.bmp");
	CTexture* pTexCharacterJump = CResMgr::GetInst()->LoadTexture(L"phantom_jump", L"texture\\character\\jump\\spritesheet.bmp");
	CTexture* pTexCharacterProne = CResMgr::GetInst()->LoadTexture(L"phantom_prone", L"texture\\character\\prone\\spritesheet.bmp");
	CTexture* pTexCharacterAlert = CResMgr::GetInst()->LoadTexture(L"phantom_alert", L"texture\\character\\alert\\spritesheet.bmp");
	CTexture* pTexCharacterDead = CResMgr::GetInst()->LoadTexture(L"phantom_dead", L"texture\\character\\dead\\spritesheet.bmp");
	CTexture* pTexCharacterBlackJack = CResMgr::GetInst()->LoadTexture(L"phantom_blackjack", L"texture\\character\\blackjack\\spritesheet.bmp");
	CTexture* pTexCharacterHeal = CResMgr::GetInst()->LoadTexture(L"phantom_heal", L"texture\\character\\heal\\spritesheet.bmp");
	CTexture* pTexCharacterBomb = CResMgr::GetInst()->LoadTexture(L"phantom_bomb", L"texture\\character\\bomb\\spritesheet.bmp");
	CTexture* pTexCharacterRope = CResMgr::GetInst()->LoadTexture(L"phantom_rope", L"texture\\character\\rope\\spritesheet.bmp");
	CTexture* pTexCharacterLadder = CResMgr::GetInst()->LoadTexture(L"phantom_ladder", L"texture\\character\\ladder\\spritesheet.bmp");

	
	GetAnimator()->CreateAnimation(
		L"IDLE_LEFT"
		, pTexCharacterIdle
		, Vec2(0, 0)
		, Vec2((float)pTexCharacterIdle->Width() / 3
			, (float)pTexCharacterIdle->Height() / 2)
		, Vec2((float)pTexCharacterIdle->Width() / 3, 0.f)
		, .5f
		, 3);

	GetAnimator()->CreateAnimation(
		L"IDLE_RIGHT"
		, pTexCharacterIdle
		, Vec2(0.f, (float)pTexCharacterIdle->Height()/2)
		, Vec2((float)pTexCharacterIdle->Width() / 3
			, (float)pTexCharacterIdle->Height() / 2)
		, Vec2((float)pTexCharacterIdle->Width() / 3, 0.f)
		, .5f
		, 3);

	GetAnimator()->CreateAnimation(
		L"MOVE_LEFT"
		, pTexCharacterMove
		, Vec2(0, 0)
		, Vec2((float)pTexCharacterMove->Width() / 4
			, (float)pTexCharacterMove->Height() / 2)
		, Vec2((float)pTexCharacterMove->Width() / 4, 0.f)
		, .1f
		, 4);

	GetAnimator()->CreateAnimation(
		L"MOVE_RIGHT"
		, pTexCharacterMove
		, Vec2(0.f, (float)pTexCharacterMove->Height() / 2)
		, Vec2((float)pTexCharacterMove->Width() / 4
			, (float)pTexCharacterMove->Height() / 2)
		, Vec2((float)pTexCharacterMove->Width() / 4, 0.f)
		, .1f
		, 4);

	GetAnimator()->CreateAnimation(
		L"JUMP_LEFT"
		, pTexCharacterJump
		, Vec2(0, 0)
		, Vec2((float)pTexCharacterJump->Width()
			, (float)pTexCharacterJump->Height() / 2)
		, Vec2(0.f, 0.f)
		, .2f
		, 1);

	GetAnimator()->CreateAnimation(
		L"JUMP_RIGHT"
		, pTexCharacterJump
		, Vec2(0.f, (float)pTexCharacterJump->Height() / 2)
		, Vec2((float)pTexCharacterJump->Width()
			, (float)pTexCharacterJump->Height() / 2)
		, Vec2(0.f, 0.f)
		, .2f
		, 1);

	GetAnimator()->CreateAnimation(
		L"PRONE_LEFT"
		, pTexCharacterProne
		, Vec2(0.f, 0.f)
		, Vec2((float)pTexCharacterProne->Width()
			, (float)pTexCharacterProne->Height() / 2)
		, Vec2(0.f, 0.f)
		, .2f
		, 1);

	GetAnimator()->CreateAnimation(
		L"PRONE_RIGHT"
		, pTexCharacterProne
		, Vec2(0.f, (float)pTexCharacterProne->Height() / 2)
		, Vec2((float)pTexCharacterProne->Width()
			, (float)pTexCharacterProne->Height() / 2)
		, Vec2(0.f, 0.f)
		, .2f
		, 1);

	GetAnimator()->CreateAnimation(
		L"BLACKJACK_LEFT"
		, pTexCharacterBlackJack
		, Vec2(0.f, 0.f)
		, Vec2((float)pTexCharacterBlackJack->Width() / 10
			, (float)pTexCharacterBlackJack->Height() / 2)
		, Vec2((float)pTexCharacterBlackJack->Width() / 10, 0.f)
		, .1f
		, 10
	);

	GetAnimator()->CreateAnimation(
		L"BLACKJACK_RIGHT"
		, pTexCharacterBlackJack
		, Vec2(0.f, (float)pTexCharacterBlackJack->Height() / 2)
		, Vec2((float)pTexCharacterBlackJack->Width() / 10
			, (float)pTexCharacterBlackJack->Height() / 2)
		, Vec2((float)pTexCharacterBlackJack->Width() / 10, 0.f)
		, .1f
		, 10
	);

	GetAnimator()->FindAnimation(L"PRONE_LEFT")->SetOffset(Vec2(-10, 15));
	GetAnimator()->FindAnimation(L"PRONE_RIGHT")->SetOffset(Vec2(10, 15));

	//GetAnimator()->FindAnimation(L"IDLE_RIGHT")->AddEvent(this, (OBJECT_MEMFUNC)&CPlayer::CreateProjectile, 1);

	CreateStateMachine();
	GetStateMachine()->AddState(new CPlayerIdle(L"IDLE"));
	GetStateMachine()->AddState(new CPlayerMove(L"MOVE"));
	GetStateMachine()->AddState(new CPlayerJump(L"JUMP"));
	GetStateMachine()->AddState(new CPlayerProne(L"PRONE"));
	GetStateMachine()->AddState(new CPlayerDamaged(L"DAMAGED"));

	GetStateMachine()->ChangeState(L"JUMP");

	m_pRole = new CRole(ROLE_TYPE::PHANTOM);
	m_pRole->SetOwner(this);

	CSkill_BlackJack* blackjack = new CSkill_BlackJack;
	blackjack->SetOwner(this);
	m_pRole->AddSkill(blackjack);
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

	if (KEY_TAP(KEY::Q))
	{
		m_pRole->UseSkill(0);
	}
	m_pRole->update();
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
	/*CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		
	}*/
}

void CPlayer::OnCollision(CCollider* _pOther)
{
	/*CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{

	}*/
}



void CPlayer::OnCollisionExit(CCollider* _pOther)
{
	/*CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::GROUND)
	{
		CRigidBody* rigid = GetRigidBody();
		if (rigid == nullptr)
			return;
	}*/
}



