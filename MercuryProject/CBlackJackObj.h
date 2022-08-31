#pragma once
#include "CObject.h"
class CBlackJackObj :
    public CObject
{

private:
    int         m_iCount;
    float       m_fAccTime;
    float       m_fDeleteTime;
    float       m_fSpeed;
    CObject*    m_pTarget;


public:
    void SetTarget(CObject* _pObj) { m_pTarget = _pObj; }
    CObject* GetTarget() { return m_pTarget; }

public:
    virtual void init();
    virtual void update();
    virtual void render(HDC _dc);
    CLONE(CBlackJackObj);

public:
    virtual void OnCollisionEnter();
    virtual void OnCollision();
    virtual void OnCollisionExit();

public:
    CBlackJackObj(float _fDeleteTime);
    ~CBlackJackObj();
    
};

