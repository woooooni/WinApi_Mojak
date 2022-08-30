#pragma once
#include "CObject.h"

typedef struct tSkillInfo
{
    int iDamage;
    float fCoolTime;
    bool bUseAble;

}SKILL_INFO;

class CSkill
    :public CObject
{

protected:
    CObject*        m_pOwner;
    SKILL_INFO      m_tSkillInfo;

    float           m_fAccTime;

public:
    void SetOwner(CObject* _pObj) { m_pOwner = _pObj; }
    CObject* GetObj() { return m_pOwner; }
    SKILL_INFO GetSkillInfo() { return m_tSkillInfo; }

public:
    virtual void update();


private:
    virtual void Use() = 0;

public:
    CSkill();
    virtual ~CSkill();

    friend class CRole;
};

