#include "pch.h"
#include "CGameCore.h"
#include "CPathMgr.h"
#include "CSound.h"
#include "fmod.hpp"


CSound::CSound()
	: m_pSoundSystem(nullptr)
	, m_pSound(nullptr)
	, m_pChannel(nullptr)
	, m_fVolume(50.f)
	, m_bLoop(false)
{
	

}

CSound::~CSound()
{
	m_pSoundSystem->release();
}

void CSound::Load(const wstring& _strPath)
{
	const wchar_t* str = _strPath.c_str();

	size_t size = (wcslen(str) + 1) * sizeof(wchar_t);
	char* buffer = new char[size];

	size_t convertedSize;
	wcstombs_s(&convertedSize, buffer, size, str, size);
	


	FMOD_RESULT result;
	result = FMOD::System_Create(&m_pSoundSystem);
	if (result != FMOD_OK) assert(nullptr);

	result = m_pSoundSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	if (result != FMOD_OK) assert(nullptr);

	result = m_pSoundSystem->createSound(buffer, FMOD_LOOP_OFF, 0, &m_pSound);
	if (result != FMOD_OK) assert(nullptr);


	delete[] buffer;
}

void CSound::Play()
{
	m_pSoundSystem->playSound(m_pSound, 0, false, &m_pChannel);
}

void CSound::update()
{
	m_pSoundSystem->update();
}

void CSound::Stop()
{

}

void CSound::Pause()
{
}


