#pragma once
#include "CState.h"
class CPlayerJump :
    public CState
{

private:
    bool m_bDoubleJump;

public:
    virtual void Enter();
    virtual void update();
    virtual void Exit();

public:
    CPlayerJump(wstring _strName);
    ~CPlayerJump();
};

