#pragma once
class CStateMachine;
class CState
{

private:
	CStateMachine*	m_pMachine;
	int				m_iEnum;

public:
	CStateMachine* GetStateMachine() { return m_pMachine; }

public:
	virtual void Enter() = 0;
	virtual void update() = 0;
	virtual void Exit() = 0;

public:
	CState(int _iEnum);
	virtual ~CState();

	friend class CStateMachine;
};

