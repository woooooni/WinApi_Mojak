#pragma once

class CTimeMgr
{
	SINGLETON(CTimeMgr);

private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llFrequency;
	LARGE_INTEGER	m_llPrevCount;

	double			m_dDT;			// 프레임 간의 시간값.
	double			m_Acc;			// 1초 체크를 위한 누적 시간
	UINT			m_iCallCount;	// 함수 호출 횟수 체크
	UINT			m_iFPS;

public:
	void init();
	void update();
	void render();

public:
	float GetfDT() { return (float)m_dDT; }
};

