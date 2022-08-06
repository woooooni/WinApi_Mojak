#pragma once
class CState
{
private:
	wstring		m_strName;

public:
	void SetName(wstring _strName) { m_strName = _strName; }

public:
	virtual void Enter()=0;
	virtual void update()=0;
	virtual void Exit()=0;

public:
	CState();
	virtual ~CState();
};


