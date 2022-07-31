#pragma once
class CCollider;
class CObject
{

private:
	wstring		m_strName;

	Vec2		m_vPos;
	Vec2		m_vScale;

	bool		m_bDead;
	GROUP_TYPE	m_eType;
	
	CCollider*	m_pCollider;

public:
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	void SetDead() { m_bDead = true; }
	bool IsDead() { return m_bDead; }

	void SetType(GROUP_TYPE _eType) { m_eType = _eType; }
	GROUP_TYPE GetType() { return m_eType; }

	void SetName(const wstring& _strName) { m_strName = _strName; }
	wstring& GetName() { return m_strName; }

public:
	

public:
	virtual void init();
	virtual void update();
	virtual void finalupdate();

	virtual void render(HDC _dc);
	void component_render(HDC _dc);

public:
	void CreateCollider();
	CCollider* GetCollider() { return m_pCollider; }
	virtual void OnCollisionEnter(CCollider* _pOther);
	virtual void OnCollision(CCollider* _pOther);
	virtual void OnCollisionExit(CCollider* _pOther);

public:
	CObject();
	virtual ~CObject();
};


