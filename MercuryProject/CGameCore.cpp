#include "pch.h"
#include "CGameCore.h"

CGameCore::CGameCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{
}

CGameCore::~CGameCore()
{
}

int CGameCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	ChangeWindowSize(_ptResolution, false);
	return S_OK;
}

void CGameCore::progress()
{
	//Loop
}

void CGameCore::ChangeWindowSize(POINT _ptResolution, bool _bMenu)
{
	RECT rt = { 0, 0, (long)_ptResolution.x, (long)_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
}


