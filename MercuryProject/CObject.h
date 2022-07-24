#pragma once
class CObject
{

private:
	Vec2		m_vPos;
	Vec2		m_vScale;

	bool		m_bDead;
	GROUP_TYPE	m_eType;

public:
	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	void SetDead() { m_bDead = true; }
	bool IsDead() { return m_bDead; }

	void SetType(GROUP_TYPE _eType) { m_eType = _eType; }
	GROUP_TYPE GetType() { return m_eType; }
public:
	virtual void init();
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

public:
	CObject();
	virtual ~CObject();
};


