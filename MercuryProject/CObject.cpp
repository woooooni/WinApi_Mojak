#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"


CObject::CObject()
	:m_vPos{}
	, m_vScale{}
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
	if (CKeyMgr::GetInst()->GetKeyState(KEY::LEFT_ARROW) == KEY_STATE::HOLD)
	{
		Vec2 vPos = GetPos();
		vPos.x -= 100.f * DeltaTime;
		SetPos(vPos);
	}
}

void CObject::render(HDC _dc)
{
	Rectangle(_dc
		, (int)m_vPos.x - m_vScale.x
		, (int)m_vPos.y - m_vScale.y
		, (int)m_vPos.x + m_vScale.x
		, (int)m_vPos.y + m_vScale.y);
}

