#pragma once
class CState
{
private:
	wstring		m_strName;

public:
	void SetName(wstring _strName) { m_strName = _strName; }
public:
	CState();
	virtual ~CState();
};

