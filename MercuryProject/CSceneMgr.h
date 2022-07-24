#pragma once
class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	CScene*							m_pCurScene;
	map<SCENE_TYPE, CScene*>		m_mapAllScene;
public:
	const CScene*& GetCurrScene() { return m_pCurScene; }
	void SetCurrScene(CScene* _pCurScene) { m_pCurScene = _pCurScene; }
	
	CScene* GetScene(SCENE_TYPE _eType);
	void AddScene(CScene* _pScene, SCENE_TYPE _eType);

public:
	void init();
	void update();
	void render(HDC _dc);
};

