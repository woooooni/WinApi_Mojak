#pragma once

class CObject;
//event function
void AddObjectEvt(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObjectEvt(CObject* _pObj);
void ChangeSceneEvt(SCENE_TYPE _eNext);
void ChangeStateEvt(CObject* _obj, const UINT _iStateId);
//void ChangeAIState(AI* _pAI, MONSTER_STATE _eNext);

