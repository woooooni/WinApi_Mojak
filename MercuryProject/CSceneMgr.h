#pragma once
class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	CScene*		m_pCurScene;
	CScene*		m_arrScene[(UINT)SCENE_TYPE::END];
public:
	CScene* GetCurrScene() { return m_pCurScene; }

public:
	void init();
	void update();
	void render(HDC _dc);

private:
	void ChangeScene(SCENE_TYPE _eNext);
	friend class CEventMgr;
};

