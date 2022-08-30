#pragma once
#include "CState.h"
class CPlayerDamaged:
	public CState
{
public:
	virtual void Enter();
	virtual void update();
	virtual void Exit();

public:
	CPlayerDamaged(wstring _strName);
	~CPlayerDamaged();
};

