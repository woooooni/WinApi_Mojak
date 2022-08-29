#include "pch.h"
#include "eventfunc.h"
#include "CEventMgr.h"
#include "CObject.h"

void AddObjectEvt(CObject* _pObj, GROUP_TYPE _eGroup)
{
	tEvent event = {};
	event.eEven = EVENT_TYPE::ADD_OBJECT;
	_pObj->SetType(_eGroup);
	event.lParam = (DWORD_PTR)_pObj;
	event.wParam = (DWORD_PTR)_eGroup;

	CEventMgr::GetInst()->AddEvent(event);
}

void DeleteObjectEvt(CObject* _pObj)
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
	event.strParam = _strNextState;

	CEventMgr::GetInst()->AddEvent(event);
}
