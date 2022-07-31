#include "pch.h"
#include "CPlayer.h"
#include "CCollider.h"
#include "CStateMachine.h"
#include "CAnimator.h"
#include "CAnimation.h"

CPlayer::CPlayer()
{
	CreateCollider();
	CreateAnimator();
	CreateStateMachine();
}

CPlayer::~CPlayer()
{

}

void CPlayer::update()
{

}

void CPlayer::render(HDC _dc)
{
}

void CPlayer::OnCollisionEnter(CCollider* _pOther)
{
}

void CPlayer::OnCollision(CCollider* _pOther)
{
}



void CPlayer::OnCollisionExit(CCollider* _pOther)
{
}

