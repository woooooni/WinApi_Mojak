#include "pch.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CRigidBody.h"
#include "CStateMachine.h"


CObject::CObject()
	:m_vPos{}
	, m_vScale{}
	, m_bAlive(true)
	, m_eType(GROUP_TYPE::DEFAULT)
	, m_pAnimator(nullptr)
	, m_pCollider(nullptr)
	, m_pRigidBody(nullptr)
{
	
}

CObject::CObject(const CObject& _origin)
	: m_strName(_origin.m_strName)
	, m_vPos(_origin.m_vPos)
	, m_vScale(_origin.m_vScale)
	, m_bAlive(true)
	, m_eType(_origin.m_eType)
	, m_pAnimator(_origin.m_pAnimator)
	, m_pCollider(_origin.m_pCollider)
	, m_pRigidBody(_origin.m_pRigidBody)
{

	//for (UINT i = 0; i < (UINT)COMPONENT_TYPE::END; i++)
	//{
	//	if (nullptr != _origin.m_arrComponent[i])
	//		m_arrComponent[i] = _origin.m_arrComponent[i];
	//}
}

CObject::~CObject()
{
	if (nullptr != m_pAnimator)
		delete m_pAnimator;

	if (nullptr != m_pRigidBody)
		delete m_pRigidBody;

	if (nullptr != m_pCollider)
		delete m_pCollider;

	if (nullptr != m_pStateMachine)
		delete m_pStateMachine;
}


void CObject::CreateCollider()
{
	m_pCollider = new CCollider;
	m_pCollider->SetOwner(this);
}

void CObject::CreateAnimator()
{
	m_pAnimator = new CAnimator;
	m_pAnimator->SetOwner(this);
}

void CObject::CreateRigidBody()
{
	m_pRigidBody = new CRigidBody;
	m_pRigidBody->SetOwner(this);
}

void CObject::CreateStateMachine()
{
	m_pStateMachine = new CStateMachine;
	m_pStateMachine->SetOwner(this);
}

void CObject::update()
{

}

void CObject::finalupdate()
{
	if (nullptr != m_pAnimator)
		m_pAnimator->finalupdate();

	if (nullptr != m_pRigidBody)
		m_pRigidBody->finalupdate();

	if (nullptr != m_pCollider)
		m_pCollider->finalupdate();

	if (nullptr != m_pStateMachine)
		m_pStateMachine->finalupdate();
}

void CObject::render(HDC _dc)
{
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(m_vPos);
	Rectangle(_dc,
		(int)(vRenderPos.x - m_vScale.x / 2.f),
		(int)(vRenderPos.y - m_vScale.y / 2.f),
		(int)(vRenderPos.x + m_vScale.x / 2.f),
		(int)(vRenderPos.y + m_vScale.y / 2.f));

	component_render(_dc);
}

void CObject::component_render(HDC _dc)
{
	if (nullptr != m_pAnimator)
		m_pAnimator->render(_dc);

	if (nullptr != m_pRigidBody)
		m_pRigidBody->render(_dc);

	if (nullptr != m_pCollider)
		m_pCollider->render(_dc);

	if (nullptr != m_pStateMachine)
		m_pStateMachine->render(_dc);
}

