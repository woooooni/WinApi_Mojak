#include "pch.h"
#include "CGameCore.h"
#include "CPathMgr.h"
#include "CSound.h"

CSound::CSound()
	:m_uFlag(SND_ASYNC)
{
}

CSound::~CSound()
{
}

void CSound::Play()
{
	wstring _strFilePath = CPathMgr::GetInst()->GetContentPath();
	_strFilePath += GetRelativePath();
	sndPlaySound(_strFilePath.c_str(), m_uFlag);
}

void CSound::Stop()
{
	sndPlaySound(NULL, SND_ASYNC);
}

void CSound::Pause()
{
}


