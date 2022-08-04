#pragma once
#include "CRes.h"
class CSound
	:public CRes
{
private:
	FMOD_SYSTEM*			m_pSoundSystem;

	FMOD_SOUND*				m_pSound;
	FMOD_CHANNEL*			m_pChannel;

	float					m_fVolume;
	FMOD_BOOL				m_bLoop;


public:
	void Play();
	void Stop();
	void Pause();

private:
	void Load(const wstring& _strPath);
public:
	CSound();
	~CSound();

	friend class CResMgr;
};

