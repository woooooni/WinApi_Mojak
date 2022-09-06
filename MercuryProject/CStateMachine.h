#pragma once
#include "CComponent.h"
#include "CState.h"
class CAnimator;
class CStateMachine
	:public CComponent
{
private:
	CState*					m_pPrevState;
	CState*					m_pCurState;
	map<int, CState*>		m_mapStates;
	CAnimator*				m_pAnimator;

public:
	CState* GetCurrState() { return m_pCurState; }
	CState* GetState(const int _iEnum) 
	{ 
		map<int, CState*>::iterator iter = m_mapStates.find(_iEnum);
		if (iter == m_mapStates.end())
			return nullptr;

		return iter->second;
	}
	void AddState(CState* _state) 
	{ 
		CState* pState = GetState(_state->m_iEnum);
		assert(!pState);

		_state->m_pMachine = this;

		if (m_mapStates.size() == 0)
			m_pCurState = _state;

		m_mapStates.insert(make_pair(_state->m_iEnum, _state));
	}

	void ChangeState(const UINT _iStateId) 
	{ 
		CObject* pObj = GetObj();
		ChangeStateEvt(pObj, _iStateId);
	}

	CAnimator* GetAnimator() { return m_pAnimator; }

private:
	void SetState(int _iEnum) 
	{
		
		map<int, CState*>::iterator iter = m_mapStates.find(_iEnum);
		if (iter == m_mapStates.end())
			assert(nullptr);

		if (m_pPrevState == m_pCurState)
			return;

		m_pPrevState = m_pCurState;
		m_pCurState->Exit();
		m_pCurState = iter->second;
		m_pCurState->Enter();
	}

public:
	virtual void finalupdate();
	virtual void render(HDC _dc);

public:
	CStateMachine(CAnimator* _pAnimator);
	~CStateMachine();

	friend class CEventMgr;
};

