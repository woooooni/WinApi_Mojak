#pragma once
#include "CScene.h"
class CScene_Start :
    public CScene
{
private:
	CSound*		m_pBgm;
public:
	virtual void update();
	virtual void render(HDC _dc);

public:
	virtual void Enter();
	virtual void Exit();

public:
	CScene_Start();
	~CScene_Start();
};

