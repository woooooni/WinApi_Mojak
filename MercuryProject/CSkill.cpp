#include "pch.h"
#include "CObject.h"
#include "CSkill.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CTimeMgr.h"

CSkill::CSkill()
{
	
}

CSkill::~CSkill()
{

}

void CSkill::update()
{
	if (m_tSkillInfo.bUseAble == false)
	{
		m_fAccTime += DeltaTime;
	}

	if (m_fAccTime >= m_tSkillInfo.fCoolTime)
	{
		m_tSkillInfo.bUseAble = true;
		m_fAccTime = 0;
	}
		
}

