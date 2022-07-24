#pragma once

struct tEvent
{
	EVENT_TYPE		eEven;
	DWORD_PTR		lParam;
	DWORD_PTR		wParam;
};

class CObject;
class CEventMgr
{
	SINGLETON(CEventMgr);

private:
	vector<tEvent>		m_vecEvent;
	vector<CObject*>	m_vecDead;
public:
	void update();

private:
	void Excute(const tEvent& _event);

public:
	void AddEvent(const tEvent& _event) { m_vecEvent.push_back(_event); }
};

