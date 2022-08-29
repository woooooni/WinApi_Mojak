#include "pch.h"
#include "CObject.h"
#include "CSkill.h"
#include "CAnimator.h"
#include "CAnimation.h"


CSkill::CSkill(bool _bFollow)
	: m_fDuration(0.f)
	, m_bFollow(_bFollow)
	, m_pOwner(nullptr)
{
	
}

CSkill::~CSkill()
{

}

