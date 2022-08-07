#include "pch.h"
#include "CRole.h"
#include "CObject.h"
#include "CSkill.h"
#include "CPlayer.h"

CRole::CRole(ROLE_TYPE _eRole)
	: m_eRole(_eRole)
{

}

CRole::~CRole()
{
	Safe_Delete_Vec(m_vecSkill);
}
