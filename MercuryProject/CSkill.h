#pragma once
#include "CObject.h"
class CSkill :
    public CObject
{

protected:
    float       m_fDuration;
    CTexture*   m_texSkillIcon;

public:
    CTexture* GetSkillIcon() { return m_texSkillIcon; }

public:
    virtual void init();
    virtual void update();

private:
    virtual void Use();

public:
    CSkill();
    virtual ~CSkill();
    CLONE(CSkill);

    friend class CRole;
};

