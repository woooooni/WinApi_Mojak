#pragma once
#include "CState.h"
class CPlayerMove :
    public CState
{

private:
    void PlayerMove();

public:
    virtual void Enter();
    virtual void update();
    virtual void Exit();
public:
    CPlayerMove(wstring _strName);
    ~CPlayerMove();
};

