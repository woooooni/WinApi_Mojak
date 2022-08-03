#pragma once
#include "CObject.h"
class CGround :
    public CObject
{

public:
    virtual void init();
    virtual void update();
    virtual void render(HDC _dc);

    virtual void OnCollisionEnter(CCollider* _pOther);
    virtual void OnCollision(CCollider* _pOther);
    virtual void OnCollisionExit(CCollider* _pOther);

public:
    CGround();
    CGround(const CGround* ground);
    ~CGround();

    CLONE(CGround);
};

