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

    float           m_fAccTime;     // 지난 시간 Temp

public:
    void SetOwner(CObject* _pObj) { m_pOwner = _pObj; }
    CObject* GetOwner() { return m_pOwner; }
    
    SKILL_INFO GetSkillInfo() { return m_tSkillInfo; }

public:
    virtual void init() {};
    virtual void update();


private:
    virtual void Use() = 0;

public:
    CSkill();
    virtual ~CSkill();

    friend class CRole;
};

