#pragma once

typedef struct tSkillInfo
{
    int iDamage;
    int iDuation;
    int iPrevDelay;
    int iAfterDelay;

}SKILL_INFO;

class CSkill :
    public CObject
{

protected:
    CObject*    m_pOwner;
    float       m_fDuration;
    bool        m_bFollow;
    SKILL_INFO  m_tSkillInfo;


public:
    void SetOwner(CObject* _pObj) { m_pOwner = _pObj; }
    CObject* GetObj() { return m_pOwner; }

    SKILL_INFO GetSkillInfo() { return m_tSkillInfo; }

public:
    virtual void init() {};
    virtual void update() {};
    virtual void render(HDC _dc) {};
    CLONE(CSkill);

private:
    virtual void Use() {};

public:
    CSkill(bool _bFollow);
    virtual ~CSkill();

    friend class CRole;
};

