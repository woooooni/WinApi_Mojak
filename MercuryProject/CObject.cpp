#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CCollider.h"

CObject::CObject()
	:m_vPos{}
	, m_vScale{}
	, m_bDead(false)
	, m_eType(GROUP_TYPE::DEFAULT)
	, m_pCollider(nullptr)
{
}

CObject::~CObject()
{
}

void CObject::init()
{

}

void CObject::update()
{
	if (KEY_HOLD(KEY::LEFT_ARROW))
	{
		Vec2 vPos = GetPos();
		vPos.x -= 100.f * DeltaTime;
		SetPos(vPos);
	}
}

void CObject::finalupdate()
{

}

void CObject::render(HDC _dc)
{
	Rectangle(_dc
		, (int)m_vPos.x - m_vScale.x
		, (int)m_vPos.y - m_vScale.y
		, (int)m_vPos.x + m_vScale.x
		, (int)m_vPos.y + m_vScale.y);

	component_render(_dc);
}

void CObject::component_render(HDC _dc)
{
	if (m_pCollider != nullptr) 
	{
		m_pCollider->render(_dc);
	}
}

void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->m_pOwner = this;
}





void CObject::OnCollisionEnter(CCollider* _pOther)
{

}

void CObject::OnCollision(CCollider* _pOther)
{
}

void CObject::OnCollisionExit(CCollider* _pOther)
{
}

