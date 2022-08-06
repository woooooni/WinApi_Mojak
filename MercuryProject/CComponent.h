#pragma once

class CObject;
class CComponent
{
private:

protected:
	CObject* m_pOwner;		//해당 컴포넌트를 소유하고 있는 오브젝트

public:
	virtual void init() {};
	virtual void update() {};
	virtual void finalupdate() {};
	virtual void render(HDC _dc) {};

public:
	void SetOwner(CObject* _pOwner) { m_pOwner = _pOwner; }
	CObject* GetObj() { return m_pOwner; }

public:
	CComponent();
	virtual ~CComponent();
	CComponent(const CComponent& _origin);
	
	friend class CObject;
};

