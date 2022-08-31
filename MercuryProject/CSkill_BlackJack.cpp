#include "pch.h"
#include "CSkill_BlackJack.h"
#include "CObject.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "CSkillEffect.h"
#include "CBlackJackEffect.h"
#include "CBlackJackObj.h"
#include "CTimeMgr.h"
#include "CStateMachine.h"
#include "CSceneMgr.h"
#include "CScene.h"


CSkill_BlackJack::CSkill_BlackJack()
{
	m_tSkillInfo.bUseAble = true;
	m_tSkillInfo.fCoolTime = 3.f;
	m_tSkillInfo.iDamage = 500;
}

CSkill_BlackJack::~CSkill_BlackJack()
{
	
}

void CSkill_BlackJack::Use()
{
	m_tSkillInfo.bUseAble = false;
	CBlackJackEffect* effect = new CBlackJackEffect;
	effect->SetFollowObj(GetObj());
	effect->GetAnimator()->FindAnimation(L"BLACKJACK_EFFECT_LEFT")->AddEvent(this, (OBJECT_MEMFUNC)&CSkill_BlackJack::GenerateBlackJackObj, 8);
	effect->GetAnimator()->FindAnimation(L"BLACKJACK_EFFECT_RIGHT")->AddEvent(this, (OBJECT_MEMFUNC)&CSkill_BlackJack::GenerateBlackJackObj, 8);
	AddObjectEvt(effect, GROUP_TYPE::EFFECT);
}

void CSkill_BlackJack::GenerateBlackJackObj()
{
	for (int i = 0; i < 3; i++)
	{
		CBlackJackObj* obj = new CBlackJackObj(5.f);
		Vec2 vObjPos = GetObj()->GetPos();
		obj->SetPos(vObjPos + Vec2((float) - 150 + (150 * i), -200.f));
		obj->SetTarget(GetObj());
		AddObjectEvt(obj, GROUP_TYPE::PLAYER_PROJECTILE);
	}
}


