#include "pch.h"
#include "CSkillEffect.h"
#include "CAnimator.h"
#include "CAnimation.h"
#include "CResMgr.h"
#include "CTexture.h"

CSkillEffect::CSkillEffect(Vec2 _vOffset, bool _bFollow)
	: m_vOffsetPos(_vOffset)
	, m_bFollow(_bFollow)
	, m_pFollowObj(nullptr)
{
	

}

CSkillEffect::~CSkillEffect()
{
	
}

void CSkillEffect::init()
{
	
}

void CSkillEffect::update()
{
	
}

void CSkillEffect::render(HDC _dc)
{
	component_render(_dc);
}
