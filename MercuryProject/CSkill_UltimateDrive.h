#pragma once
#include "CSkill.h"
class CObject;
class CSkill_UltimateDrive :
    public CSkill
{

public:
    virtual void init();
    virtual void update();
    virtual void render(HDC _dc);

private:
    virtual void Use();

public:
    CSkill_UltimateDrive();
    ~CSkill_UltimateDrive();
};

