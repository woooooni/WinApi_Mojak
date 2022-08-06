#pragma once
#include "CCamera.h"

class CComponent;
class CCollider;
class CAnimator;
class CRigidBody;
class CStateMachine;

class CObject
{
private:
	wstring				m_strName;
	Vec2				m_vPos;
	Vec2				m_vScale;
	GROUP_TYPE			m_eType;

	bool				m_bAlive;

	CCollider*			m_pCollider;
	CAnimator*			m_pAnimator;
	CRigidBody*			m_pRigidBody;
	CStateMachine*		m_pStateMachine;

public:
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	wstring& GetName() { return m_strName; }

	void SetType(GROUP_TYPE _eType) { m_eType = _eType; }
	GROUP_TYPE GetType() { return m_eType; }

	bool IsDead() { return !m_bAlive; }

public:
	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }

	virtual void OnCollisionEnter(CCollider* _pOther) {}
	virtual void OnCollision(CCollider* _pOther) {}
	virtual void OnCollisionExit(CCollider* _pOther) {}


	void CreateAnimator();
	CAnimator* GetAnimator() { return m_pAnimator; }

	void CreateRigidBody();
	CRigidBody* GetRigidBody() { return m_pRigidBody; }

	void CreateStateMachine();
	CStateMachine* GetStateMachine() { return m_pStateMachine; }

private:
	void SetDead() { m_bAlive = false; }

public:
	virtual void init() {}
	virtual void update() = 0;
	virtual void finalupdate();
	virtual void render(HDC _dc);

	void component_render(HDC _dc);

	virtual CObject* Clone() = 0;

public:
	CObject();
	CObject(const CObject& _origin);
	virtual ~CObject();

	friend class CEventMgr;
};

