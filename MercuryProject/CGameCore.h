#pragma once
#include "pch.h"
class CTexture;
class CGameCore
{
	SINGLETON(CGameCore);
private:
	HWND		m_hWnd;
	HDC			m_hDC;
	CTexture*	m_pMemTex;				// 백버퍼 텍스쳐
	POINT		m_ptResolution;

	//자주 사용할 GDI Object
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];
private:
	void CreateBrushPen();
	void Clear();
public:
	void ChangeWindowSize(POINT _ptResolution, bool _bMenu);


public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	Vec2 GetResoultion() { return Vec2((float)m_ptResolution.x, (float)m_ptResolution.y); }
	HBRUSH GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; };

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

};

