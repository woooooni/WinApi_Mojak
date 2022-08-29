#pragma once
#include "CObject.h"
class CProjectile :
    public CObject
{
private:
    float m_fAcc;
    float m_fDuration;


public:
    void SetDuration(float _f) { m_fDuration = _f; }

public:
    virtual void init();
    virtual void update();
    virtual void render(HDC _dc);

public:
    CProjectile();
    ~CProjectile();

private:
    CLONE(CProjectile);
};

