#pragma once
#include "CComponent.h"
#include "CState.h"

class CStateMachine
	:public CComponent
{
private:
	CState*					m_pCurState;
	map<wstring, CState*>	m_mapStates;
	

public:
	CState* GetCurrState() { return m_pCurState; }
	CState* GetState(const wstring _strName) { return m_mapStates.find(_strName)->second; }
	void AddState(const wstring _strName, CState* _state) 
	{ 
		_state->SetName(_strName);
		m_mapStates.insert(make_pair(_strName, _state));
	}

	void ChangeState(const wstring _strName) 
	{ 
		CObject* pObj = GetObj();
		ChangeStateEvt(pObj, _strName);
	}

private:
	void	SetState(wstring _strName) { m_pCurState->Exit();  m_pCurState = m_mapStates.find(_strName)->second; m_pCurState->Enter(); }

public:
	virtual void init();
	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

public:
	CStateMachine();
	~CStateMachine();

	friend class CEventMgr;
};

