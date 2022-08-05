#include "pch.h"
#include "CGameCore.h"
#include "CTexture.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CPathMgr.h"
#include "CObject.h"
#include "CResMgr.h"
#include "CSceneMgr.h"
#include "CEventMgr.h"
#include "CCollisionMgr.h"
#include "SelectGDI.h"

CGameCore::CGameCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
{
}

CGameCore::~CGameCore()
{
	ReleaseDC(m_hWnd, m_hDC);
	for (int i = 0; i < (UINT)PEN_TYPE::END; i++) 
	{
		DeleteObject(m_arrPen[i]);
	}
}

int CGameCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	ChangeWindowSize(_ptResolution, false);

	m_hDC = GetDC(m_hWnd);

	//이중 버퍼링 용도의 비트맵과 DC를 만듦.
	m_pMemTex = CResMgr::GetInst()->CreateTexture(L"BackBuffer",
		(UINT)m_ptResolution.x,
		(UINT)m_ptResolution.y);

	CreateBrushPen();

	// MANAGER INIT
	CPathMgr::GetInst()->init();
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CResMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();
	CCamera::GetInst()->init();

	return S_OK;
}

void CGameCore::progress()
{
	// Loop
	// MANAGER UPDATE
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CCamera::GetInst()->update();

	//SCENE UPDATE
	CSceneMgr::GetInst()->update();
	CResMgr::GetInst()->update();

	//충돌체크
	CCollisionMgr::GetInst()->update();

	//TODO::UI이벤트

	


	//RENDER
	Clear();
	CSceneMgr::GetInst()->render(m_pMemTex->GetDC());
	CCamera::GetInst()->render(m_pMemTex->GetDC());

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
		m_pMemTex->GetDC(), 0, 0, SRCCOPY);

	CTimeMgr::GetInst()->render();

	//===========
	//Event Update
	//===========
	CEventMgr::GetInst()->update();
	
}

void CGameCore::ChangeWindowSize(POINT _ptResolution, bool _bMenu)
{
	RECT rt = { 0, 0, (long)_ptResolution.x, (long)_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, _bMenu);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);
}

void CGameCore::CreateBrushPen()
{
	// hollow brush
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::BLACK] = (HBRUSH)GetStockObject(BLACK_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::WHITE] = (HBRUSH)GetStockObject(WHITE_BRUSH);

	//red pen
	//green pen
	//blue pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));;
}

void CGameCore::Clear()
{
	SelectGDI gdi(m_pMemTex->GetDC(), BRUSH_TYPE::WHITE);
	Rectangle(m_pMemTex->GetDC(), -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
}


