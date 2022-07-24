#pragma once
class CObject;
class CScene
{
private:
	vector<CObject*>	m_vecObj;
	
public:
	virtual void init();
	virtual void update();
	virtual void render(HDC _dc);

public:
	CScene();
	~CScene();
};

