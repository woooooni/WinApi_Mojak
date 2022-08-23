#include "pch.h"
#include "CEventMgr.h"
#include "CState.h"
#include "CObject.h"
#include "CStateMachine.h"
#include "CAnimation.h"
#include "CAnimator.h"


CStateMachine::CStateMachine(CAnimator* _pAnimator)
	: m_pAnimator(_pAnimator)
	, m_pPrevState(nullptr)
	, m_pCurState(nullptr)
{

}

CStateMachine::~CStateMachine()
{
	Safe_Delete_Map(m_mapStates);
}

void CStateMachine::finalupdate()
{
	if (m_pCurState == nullptr)
		return;

	m_pCurState->update();
}

void CStateMachine::render(HDC _dc)
{
	m_pAnimator->render(_dc);
}
