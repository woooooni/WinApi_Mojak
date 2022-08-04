#pragma once
#include "CRes.h"
#include <fmod.hpp>

class CSound
	:public CRes
{
private:
	FMOD::System*			m_pSoundSystem;

	FMOD::Sound*			m_pSound;
	FMOD::Channel*			m_pChannel;

	float					m_fVolume;
	bool					m_bLoop;


public:
	void Play();
	void Stop();
	void Pause();

private:
	void update();
	void Load(const wstring& _strPath);

public:
	CSound();
	~CSound();

	friend class CResMgr;
};

