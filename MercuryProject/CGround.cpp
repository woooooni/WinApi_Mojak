#include "pch.h"
#include "CGround.h"
#include "CCollider.h"
#include "CObject.h"
#include "CRigidBody.h"

CGround::CGround()
{
	
}

CGround::CGround(const CGround* ground)
{
}

CGround::~CGround()
{
}

void CGround::init()
{
	CreateCollider();
	Vec2 vScale = GetScale();
	GetCollider()->SetOffsetPos(Vec2(0.f, 0.f));
	GetCollider()->SetScale(Vec2(vScale.x, vScale.y));
}
void CGround::update()
{
}
void CGround::render(HDC _dc)
{
	CObject::render(_dc);
	component_render(_dc);
}

void CGround::OnCollisionEnter(CCollider* _pOther) 
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::PLAYER)
	{
		CRigidBody* pRigid = pOtherObj->GetRigidBody();

		Vec2 vObjPos = _pOther->GetFinalPos();
		Vec2 vObjScale = _pOther->GetScale();

		Vec2 vPos = GetCollider()->GetFinalPos();
		Vec2 vScale = GetCollider()->GetScale();

		if (pRigid == nullptr || pRigid->IsGround() == true)
			return;

		if (vPos.y + vScale.y / 2.f < vObjPos.y + vObjScale.y / 2.f)
			return;



		// 통과한 길이
		// 함수의 연산결과를 바로 수식으로 사용하면 디버깅시 어려움이 있으니, 지역변수로 먼저 받아놓고 사용.
		float fLen = abs(vObjPos.y - vPos.y);
		float fValue = (vObjScale.y / 2.f + vScale.y / 2.f) - fLen;

		vObjPos = pOtherObj->GetPos();
		vObjPos.y -= fValue;

		pOtherObj->SetPos(vObjPos);
		pRigid->SetGround(true);
		pRigid->SetFricCoeff(1500.f);
	}
}
void CGround::OnCollision(CCollider* _pOther)
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::PLAYER)
	{
		//CRigidBody* pRigid = pOtherObj->GetRigidBody();

		//Vec2 vObjPos = _pOther->GetFinalPos();
		//Vec2 vObjScale = _pOther->GetScale();

		//Vec2 vPos = GetCollider()->GetFinalPos();
		//Vec2 vScale = GetCollider()->GetScale();


		//// 통과한 길이
		//// 함수의 연산결과를 바로 수식으로 사용하면 디버깅시 어려움이 있으니, 지역변수로 먼저 받아놓고 사용.
		//float fLen = abs(vObjPos.y - vPos.y);
		//float fValue = (vObjScale.y / 2.f + vScale.y / 2.f) - fLen;

		//vObjPos = pOtherObj->GetPos();
		//vObjPos.y -= fValue;

		//pOtherObj->SetPos(vObjPos);
		//pRigid->SetGround(true);
		//pRigid->SetFricCoeff(1500.f);
	}
}

void CGround::OnCollisionExit(CCollider* _pOther) 
{
	CObject* pOtherObj = _pOther->GetObj();
	if (pOtherObj->GetType() == GROUP_TYPE::PLAYER)
	{
		CRigidBody* pRigid = pOtherObj->GetRigidBody();
	}
}
