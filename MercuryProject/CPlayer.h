#pragma once
#include "CObject.h"
#include "CTexture.h"
class CPlayer :
    public CObject
{
private:
    //Private Mem


private:
    //Private Func
    CLONE(CPlayer);


public:
    virtual void init();
    virtual void update();
    virtual void render(HDC _dc);

public:
    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);
public:
    CPlayer();
    ~CPlayer();
    
};

