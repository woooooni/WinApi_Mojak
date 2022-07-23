#pragma once


class CGameCore
{
	SINGLETON(CGameCore);
private:
	HWND	m_hWnd;
	HDC		m_hDC;
	POINT	m_ptResolution;


private:
	void ChangeWindowSize(POINT _ptResolution, bool _bMenu);

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

};

