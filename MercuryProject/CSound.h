#pragma once
#include "CRes.h"
#include <fmod.hpp>

class CSound
	:public CRes
{
private:
	FMOD::Sound*			m_pSound;
	FMOD::Channel*			m_pChannel;
	bool					m_bLoop;

public:
	void Play(SOUND_CHANNEL_GROUP _eGroup);
	void Stop();
	void Pause();

private:
	void Load(const wstring& _strPath, bool _bLoop=false);

public:
	CSound();
	~CSound();

	friend class CResMgr;
};

