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
	void Stop() { m_pChannel->stop(); }
	void Pause() { m_pChannel->setPaused(true); }
	void ReSume() { m_pChannel->setPaused(false); }

private:
	void Load(const wstring& _strPath, bool _bLoop=false);

public:
	CSound();
	~CSound();

	friend class CResMgr;
};

