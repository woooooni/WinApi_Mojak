#include "pch.h"
#include "CRole.h"
#include "CObject.h"
#include "CSkill.h"
#include "CPlayer.h"



CRole::CRole(ROLE_TYPE _eRole)
	: m_pOwner(nullptr)
	, m_eRole(_eRole)
{
	
}

CRole::~CRole()
{
	Safe_Delete_Vec(m_vecSkill);
}

void CRole::update()
{
	for (UINT i = 0; i < m_vecSkill.size(); i++)
	{
		m_vecSkill[i]->update();
	}
}
