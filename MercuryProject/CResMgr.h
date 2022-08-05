#pragma once

class CRes;
class CTexture;
class CSound;
class CResMgr
{
	SINGLETON(CResMgr);

private:
	FMOD::System*			m_pSoundSystem;
	FMOD::ChannelGroup*		m_ChannelGroup[(UINT)SOUND_CHANNEL_GROUP::END];

	map<wstring, CRes*>		m_mapTex;
	map<wstring, CRes*>		m_mapSound;

	float					m_fGroupVolume[(UINT)SOUND_CHANNEL_GROUP::END];

public:
	CTexture* CreateTexture(const wstring& _strKey, UINT _iWidth, UINT _iHeight);
	CTexture* FindTexture(const wstring& _strKey);
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	
	FMOD::System* GetSoundSystem() { return m_pSoundSystem; }

	CSound* FindSound(const wstring& _strKey);
	CSound* LoadSound(const wstring& _strKey, const wstring& _strRelativePath);

	void SetVolume(SOUND_CHANNEL_GROUP _eGroup, float _fVolume)
	{
		//Volume = 0.f ~ 1.f
		if (_fVolume >= 0 && _fVolume <= 1.f)
			m_fGroupVolume[(UINT)_eGroup] = _fVolume;
	}

	float GetVolume(SOUND_CHANNEL_GROUP _eGroup){ return m_fGroupVolume[(UINT)_eGroup]; }
	void RegisterSoundGroup(SOUND_CHANNEL_GROUP _eGroup, FMOD::Channel* _channel){ _channel->setChannelGroup(m_ChannelGroup[(UINT)_eGroup]); }
	

public:
	void init();
	void update();
	
};

