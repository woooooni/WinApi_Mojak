#pragma once
#include "CSkillEffect.h"
class CBlackJackEffect :
    public CSkillEffect
{


public:
    virtual void init();
    virtual void update();
    virtual void render(HDC _dc);

public:
    CBlackJackEffect();
    ~CBlackJackEffect();

    CLONE(CBlackJackEffect);
};

