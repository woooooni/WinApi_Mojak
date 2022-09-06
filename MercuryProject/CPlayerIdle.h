#pragma once
#include "CState.h"
class CPlayerIdle :
    public CState
{

public:
    virtual void Enter();
    virtual void update();
    virtual void Exit();

private:
    void PlayerMove();

public:
    CPlayerIdle();
    ~CPlayerIdle();

};

