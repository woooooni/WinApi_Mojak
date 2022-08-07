#include "pch.h"
#include "CResMgr.h"
#include "CTexture.h"
#include "CPathMgr.h"
#include "CSound.h"

CResMgr::CResMgr()
	: m_pSoundSystem(nullptr)
	, m_arrChannelGroup{}
	, m_mapTex{}
	, m_mapSound{}
{
	
}
CResMgr::~CResMgr()
{
	Safe_Delete_Map(m_mapTex);
	Safe_Delete_Map(m_mapSound);
	for (UINT i = 0; i < (UINT)SOUND_CHANNEL_GROUP::END; i++)
	{
		m_arrChannelGroup[i]->release();
	}

	m_pSoundSystem->release();
}


CTexture* CResMgr::CreateTexture(const wstring& _strKey, UINT _iWidth, UINT _iHeight)
{
	CTexture* pTex = FindTexture(_strKey);
	if (pTex != nullptr)
	{
		return pTex;
	}

	pTex = new CTexture;
	pTex->Create(_iWidth, _iHeight);
	pTex->SetKey(_strKey);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResMgr::LoadTexture(const wstring& _strKey, const wstring& _strRelativePath)
{
	CTexture* pTex = FindTexture(_strKey);
	if (pTex != nullptr)
	{
		return pTex;
	}

	wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;

	pTex = new CTexture;
	pTex->Load(strFilePath);
	pTex->SetKey(_strKey);
	pTex->SetRelativePath(_strRelativePath);

	m_mapTex.insert(make_pair(_strKey, pTex));

	return pTex;
}

CTexture* CResMgr::FindTexture(const wstring& _strKey)
{
	map<wstring, CRes*>::iterator iter = m_mapTex.find(_strKey);
	if (iter == m_mapTex.end()) 
		return nullptr;

	return (CTexture*)iter->second;
}

CSound* CResMgr::LoadSound(const wstring& _strKey, const wstring& _strRelativePath)
{
	CSound* pSound = FindSound(_strKey);
	if (pSound != nullptr)
		return pSound;

	wstring strFilePath = CPathMgr::GetInst()->GetContentPath();
	strFilePath += _strRelativePath;


	pSound = new CSound;
	pSound->SetKey(_strKey);
	pSound->SetRelativePath(_strRelativePath);
	pSound->Load(strFilePath);
	m_mapSound.insert(make_pair(_strKey, pSound));

	return pSound;
}

void CResMgr::SetVolume(SOUND_CHANNEL_GROUP _eGroup, float _fVolume)
{
	float fVolume;
	m_arrChannelGroup[(UINT)_eGroup]->getVolume(&fVolume);
	fVolume = clamp(fVolume + _fVolume, 0.f, 1.f);
	m_arrChannelGroup[(UINT)_eGroup]->setVolume(fVolume);
}


CSound* CResMgr::FindSound(const wstring& _strKey)
{
	map<wstring, CRes*>::iterator iter = m_mapSound.find(_strKey);
	if (iter == m_mapSound.end())
		return nullptr;

	return (CSound*)iter->second;
}

void CResMgr::VolumeUp(SOUND_CHANNEL_GROUP _eGroup, float _fInc)
{
	float fVolume;
	m_arrChannelGroup[(UINT)_eGroup]->getVolume(&fVolume);
	fVolume = clamp(fVolume + _fInc, 0.f, 1.f);
	m_arrChannelGroup[(UINT)_eGroup]->setVolume(fVolume);
	
}

void CResMgr::VolumeDown(SOUND_CHANNEL_GROUP _eGroup, float _fDec)
{
	float fVolume;
	m_arrChannelGroup[(UINT)_eGroup]->getVolume(&fVolume);
	fVolume = clamp(fVolume - _fDec, 0.f, 1.f);
	m_arrChannelGroup[(UINT)_eGroup]->setVolume(fVolume);
}

void CResMgr::init()
{
	FMOD_RESULT result;

	result = FMOD::System_Create(&m_pSoundSystem);
	if (result != FMOD_OK) assert(nullptr);

	result = m_pSoundSystem->init(32, FMOD_INIT_NORMAL, nullptr);
	if (result != FMOD_OK) assert(result);

	for (UINT i = 0; i < (UINT)SOUND_CHANNEL_GROUP::END; i++)
	{
		CResMgr::GetInst()->GetSoundSystem()->createChannelGroup("Channel_Group" + i, &m_arrChannelGroup[i]);
	}
	m_arrChannelGroup[(UINT)SOUND_CHANNEL_GROUP::BGM]->setVolume(.5f);
	m_arrChannelGroup[(UINT)SOUND_CHANNEL_GROUP::SOUND_EFFECT]->setVolume(.3f);
}

void CResMgr::update()
{
	m_pSoundSystem->update();
}
