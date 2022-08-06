#pragma once

class CRes;
class CTexture;
class CSound;
class CResMgr
{
	SINGLETON(CResMgr);

private:
	FMOD::System*			m_pSoundSystem;
	FMOD::ChannelGroup*		m_arrChannelGroup[(UINT)SOUND_CHANNEL_GROUP::END];

	map<wstring, CRes*>		m_mapTex;
	map<wstring, CRes*>		m_mapSound;

private:
	CTexture* FindTexture(const wstring& _strKey);
	CSound* FindSound(const wstring& _strKey);

public:

	//Texture
	CTexture* CreateTexture(const wstring& _strKey, UINT _iWidth, UINT _iHeight);
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	

	//Sound
	FMOD::System* GetSoundSystem() { return m_pSoundSystem; }

	
	CSound* LoadSound(const wstring& _strKey, const wstring& _strRelativePath);

	void SetVolume(SOUND_CHANNEL_GROUP _eGroup, float _fVolume);
	float GetVolume(SOUND_CHANNEL_GROUP _eGroup) 
	{	
		float fVolume; 
		m_arrChannelGroup[(UINT)_eGroup]->getVolume(&fVolume);
		return fVolume;
	}

	void VolumeUp(SOUND_CHANNEL_GROUP _eGroup, float _fInc);
	void VolumeDown(SOUND_CHANNEL_GROUP _eGroup, float _fDec);

	FMOD::ChannelGroup* GetSoundGroup(SOUND_CHANNEL_GROUP _eGroup) { return m_arrChannelGroup[(UINT)_eGroup]; }
	

public:
	void init();
	void update();
	
};

