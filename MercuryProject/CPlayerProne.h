#pragma once
#include "CState.h"
class CPlayerProne :
    public CState
{

private:
    Vec2 m_vColPrevScale;

private:
    void PlayerMove();

public:
    virtual void Enter();
    virtual void update();
    virtual void Exit();

public:
    CPlayerProne();
    ~CPlayerProne();
};

