#pragma once
#include "CSkill.h"
class CObject;
class CRole
{
public:
	wstring					m_strName;
	ROLE_TYPE				m_eRole;
	CObject*				m_pOwner;

	//map으로 관리하는게 편할듯?
	vector<CSkill*>			m_vecSkill;

public:
	virtual void update();

public:
	void SetOwner(CObject* _owner) { m_pOwner = _owner; }
	CObject* GetOwner() { return m_pOwner; }

	ROLE_TYPE GetType() { return m_eRole; }

	void AddSkill(CSkill* _pSkill) { m_vecSkill.push_back(_pSkill); }
	void UseSkill(int _iIdx) 
	{ 
		/*CStateMachine* pMachine = m_pOwner->GetStateMachine();
		pMachine->ChangeState(L"ATTACK");*/

		CSkill* skill = m_vecSkill.at(_iIdx);
		assert(skill);

		if(skill->GetSkillInfo().bUseAble)
			skill->Use();
	}
	vector<CSkill*> ClearSkill() { m_vecSkill.clear(); }



public:
	CRole(ROLE_TYPE _eRole);
	virtual ~CRole();
};

