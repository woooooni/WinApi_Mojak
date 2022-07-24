#pragma once

class CObject;
//event function
void CreateObj(CObject* _pObj, GROUP_TYPE _eGroup);
void DeleteObj(CObject* _pObj);
void ChangeSceneEvt(SCENE_TYPE _eNext);
//void ChangeAIState(AI* _pAI, MONSTER_STATE _eNext);

