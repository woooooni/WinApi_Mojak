#pragma once
class CPathMgr
{
	SINGLETON(CPathMgr);

private:
	//윈도우 주소 경로는 255자로 제한.
	wchar_t		m_szContentPath[255];
	wchar_t		m_szRelativePath[256];

public:
	void init();
	wchar_t* GetContentPath(){ return m_szContentPath; }
	wstring	GetRelativePath(const wchar_t* _filePath);
};

