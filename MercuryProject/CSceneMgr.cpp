#include "pch.h"
#include "CSceneMgr.h"
#include "CScene.h"

CSceneMgr::CSceneMgr()
	:m_arrScene{}
	,m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	//씬 전부 삭제
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}




void CSceneMgr::init()
{
	
}

void CSceneMgr::update()
{
	m_pCurScene->update();
	m_pCurScene->finalupdate();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}


void CSceneMgr::ChangeScene(SCENE_TYPE _eNext)
{
	m_pCurScene->Exit();
	m_pCurScene = m_arrScene[(UINT)_eNext];
	m_pCurScene->Enter();
}
