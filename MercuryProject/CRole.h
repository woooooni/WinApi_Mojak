#pragma once
#include "CSkill.h"
class CObject;
class CRole
{
public:
	wstring					m_strName;
	ROLE_TYPE				m_eRole;
	CObject*				m_pOwner;
	vector<CSkill*>			m_vecSkill;


public:
	void SetOwner(CObject* _owner) { m_pOwner = _owner; }
	CObject* GetOwner() { return m_pOwner; }

	ROLE_TYPE GetType() { return m_eRole; }

	void AddSkill(CSkill* _pSkill) { m_vecSkill.push_back(_pSkill); }
	void UseSkill(int _iIdx) 
	{ 
		CSkill* skill = m_vecSkill.at(_iIdx);
		assert(skill);
		skill->Use();
	}
	vector<CSkill*> ClearSkill() { m_vecSkill.clear(); }



public:
	CRole(ROLE_TYPE _eRole);
	virtual ~CRole();
};

