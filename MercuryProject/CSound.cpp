#include "pch.h"
#include "CGameCore.h"
#include "CResMgr.h"
#include "CPathMgr.h"
#include "CSound.h"
#include "fmod.hpp"


CSound::CSound()
	: m_pSound(nullptr)
	, m_bLoop(false)
{
	
}

CSound::~CSound()
{
	m_pSound->release();
}

void CSound::Load(const wstring& _strPath, bool _bLoop)
{
	SetRelativePath(_strPath);
	const wchar_t* str = GetRelativePath().c_str();

	size_t size = (wcslen(str) + 1) * sizeof(wchar_t);
	char* buffer = new char[size];

	size_t convertedSize;
	wcstombs_s(&convertedSize, buffer, size, str, size);
	

	FMOD_RESULT result;
	if (_bLoop)
	{
		result = CResMgr::GetInst()->GetSoundSystem()->createSound(buffer, FMOD_LOOP_NORMAL, 0, &m_pSound);
	}
	else 
	{
		result = CResMgr::GetInst()->GetSoundSystem()->createSound(buffer, FMOD_LOOP_OFF, 0, &m_pSound);
	}
	if (result != FMOD_OK) assert(result);

	delete[] buffer;
}

void CSound::Play(SOUND_CHANNEL_GROUP _eGroup)
{
	bool isPlaying = false;
	m_pChannel->isPlaying(&isPlaying);

	if (isPlaying)
		Stop();

	CResMgr::GetInst()->GetSoundSystem()->playSound(m_pSound, CResMgr::GetInst()->GetSoundGroup(_eGroup), false, &m_pChannel);
}


