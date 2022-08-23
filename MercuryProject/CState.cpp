#include "pch.h"
#include "CState.h"

CState::CState(wstring _strName)
	: m_strState(_strName)
	, m_pMachine(nullptr)
{

}

CState::~CState()
{

}

