#include "pch.h"
#include "CGameCore.h"
#include "CPathMgr.h"
#include "CSound.h"



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
	
}

void CSound::Load(const wstring& _strPath)
{
	const wchar_t* str = _strPath.c_str();
	size_t size = (wcslen(str) + 1) * sizeof(wchar_t);
	char* buffer = new char[size];

	size_t convertedSize;
	wcstombs_s(&convertedSize, buffer, size, str, size);
	FMOD_System_Create(&m_pSoundSystem, 0);
	delete[] buffer;
}

void CSound::Play()
{

}

void CSound::Stop()
{

}

void CSound::Pause()
{
}


