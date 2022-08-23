#pragma once
class CStateMachine;
class CState
{

private:
	CStateMachine* m_pMachine;
	wstring		   m_strState;


public:
	CStateMachine* GetStateMachine() { return m_pMachine; }
	wstring		   GetStateName() { return m_strState; }

public:
	virtual void Enter() = 0;
	virtual void update() = 0;
	virtual void Exit() = 0;

public:
	CState(wstring _strName);
	virtual ~CState();

	friend class CStateMachine;
};

