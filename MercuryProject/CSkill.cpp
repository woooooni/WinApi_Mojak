#include "pch.h"
#include "CObject.h"
#include "CSkill.h"
#include "CAnimator.h"
#include "CAnimation.h"


CSkill::CSkill()
	:m_fDuration(0.f)
{

}

CSkill::~CSkill()
{

}

void CSkill::Use()
{

}

void CSkill::init()
{
	CreateCollider();
	CreateAnimator();
}

void CSkill::update()
{
	if (!GetAnimator()->IsPlaying())
	{
		delete this;
	}
}

