#include "pch.h"
#include "CEventMgr.h"
#include "CState.h"
#include "CObject.h"
#include "CStateMachine.h"


CStateMachine::CStateMachine()
	:m_pCurState(nullptr)
{
	
}

CStateMachine::~CStateMachine()
{
	Safe_Delete_Map(m_mapStates);
}

void CStateMachine::init()
{
}

void CStateMachine::update()
{
	m_pCurState->update();
}

void CStateMachine::finalupdate()
{
	
}

void CStateMachine::render(HDC _dc)
{
	
}
