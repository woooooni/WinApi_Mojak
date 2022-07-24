#include "pch.h"
#include "CGameCore.h"
#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CPathMgr.h"
#include "CObject.h"

CGameCore::CGameCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, obj{}
{
}

CGameCore::~CGameCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}

int CGameCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	ChangeWindowSize(_ptResolution, false);

	m_hDC = GetDC(m_hWnd);


	// MANAGER INIT
	CPathMgr::GetInst()->init();
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();

	obj = new CObject;
	obj->SetPos(Vec2(600, 400));
	obj->SetScale(Vec2(100, 100));
	return S_OK;
}

void CGameCore::progress()
{
	// Loop
	// MANAGER UPDATE
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	
	//SCENE UPDATE
	obj->update();

	//RENDER
	CTimeMgr::GetInst()->render();
	obj->render(m_hDC);
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


	//red pen
	//green pen
	//blue pen
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));;
}

void CGameCore::Clear()
{
}


