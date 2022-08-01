#pragma once
#include "CRes.h"
class CSound
	:public CRes
{
private:
	UINT m_uFlag;
public:
	void Play();
	void Stop();
	void Pause();

	void SetFlag(UINT _flag) { m_uFlag = _flag; }
	UINT GetFlag() { return m_uFlag; }
public:
	CSound();
	~CSound();

	friend class CResMgr;
};

