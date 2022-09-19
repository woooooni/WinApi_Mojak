#pragma once
#include "CSkill.h"
class CObject;
class CSkillEffect;
class CSkill_BlackJack :
    public CSkill
{

    

public:
    virtual void Use();

private:
    void GenerateBlackJackObj();

public:
    CSkill_BlackJack();
    ~CSkill_BlackJack();
    CLONE(CSkill_BlackJack);

    

};

