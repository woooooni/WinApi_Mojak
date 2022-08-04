#include "pch.h"
#include "EventFunc.h"
#include "CEventMgr.h"
#include "CObject.h"

void CreateObj(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent event = {};
	event.eEven = EVENT_TYPE::CREATE_OBJECT;
	_pObj->SetType(_eGroup);
	event.lParam = (DWORD_PTR)_pObj;
	event.wParam = (DWORD_PTR)_eGroup;

	CEventMgr::GetInst()->AddEvent(event);
}

void DeleteObj(CObject* _pObj)
{
	tEvent event = {};
	event.eEven = EVENT_TYPE::DELETE_OBJECT;
	event.lParam = (DWORD_PTR)_pObj;

	CEventMgr::GetInst()->AddEvent(event);
}

void ChangeSceneEvt(SCENE_TYPE _eNext)
{
	tEvent event = {};
	event.eEven = EVENT_TYPE::SCENE_CHANGE;
	event.lParam = (DWORD_PTR)_eNext;

	CEventMgr::GetInst()->AddEvent(event);
}

void ChangeStateEvt(CObject* _obj, const wstring _strNextState)
{
	tEvent event = {};
	event.eEven = EVENT_TYPE::STATE_CHANGE;
	event.wParam = (DWORD_PTR)_obj;
	event.lParam = (DWORD_PTR)_strNextState.c_str();

	CEventMgr::GetInst()->AddEvent(event);
}
