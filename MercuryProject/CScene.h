#pragma once
class CObject;
class CScene
{
private:
	vector<CObject*>	m_arrObj[(UINT)GROUP_TYPE::END];
	wstring				m_strName;


public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

public:
	void AddObject(CObject* _obj, GROUP_TYPE _eType) { m_arrObj[(UINT)_eType].push_back(_obj); }
	const vector<CObject*>& GetGroupObejct(GROUP_TYPE _eType) { return m_arrObj[(UINT)_eType]; }
	vector<CObject*>& GetUIGroup() { return m_arrObj[(UINT)GROUP_TYPE::UI]; }
	
	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();


public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	virtual void init();
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

public:
	CScene();
	virtual ~CScene();
};

