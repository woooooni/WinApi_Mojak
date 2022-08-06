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

void CGround::OnCollisionEnter(CCollider* _pOther) {}
void CGround::OnCollision(CCollider* _pOther)
{
	if (_pOther->GetObj()->GetType() == GROUP_TYPE::PLAYER)
	{
		CObject* obj = _pOther->GetObj();
		obj->GetRigidBody()->SetGround(true);
	}
}
void CGround::OnCollisionExit(CCollider* _pOther) 
{
	if (_pOther->GetObj()->GetType() == GROUP_TYPE::PLAYER)
	{
		CObject* obj = _pOther->GetObj();
		obj->GetRigidBody()->SetGround(false);
	}
}
