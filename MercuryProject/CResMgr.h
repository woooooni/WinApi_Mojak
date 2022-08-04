#pragma once

class CRes;
class CTexture;
class CSound;
class CResMgr
{
	SINGLETON(CResMgr);

private:
	map<wstring, CRes*> m_mapTex;
	map<wstring, CRes*> m_mapSound;

public:
	CTexture* CreateTexture(const wstring& _strKey, UINT _iWidth, UINT _iHeight);
	CTexture* FindTexture(const wstring& _strKey);
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	
	CSound* FindSound(const wstring& _strKey);
	CSound* LoadSound(const wstring& _strKey, const wstring& _strRelativePath);

private:
	
};

