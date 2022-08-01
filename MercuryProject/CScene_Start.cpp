#include "pch.h"
#include "CScene_Start.h"

#include "CGameCore.h"

#include "CObject.h"
#include "CPlayer.h"
//#include "CMonster.h"
//#include "CGround.h"

#include "CPathMgr.h"
#include "CTexture.h"

#include "CCollisionMgr.h"

#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CCamera.h"
#include "CTimeMgr.h"

#include "CRigidBody.h"
#include "SelectGDI.h"
#include "EventFunc.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}


void CScene_Start::update()
{
	CScene::update();
}

void CScene_Start::render(HDC _dc)
{
	CScene::render(_dc);

}

void CScene_Start::Enter()
{
	//Object 추가
	//Player
	CPlayer* pPlayer = new CPlayer;
	pPlayer->SetPos(Vec2(640.f, 384.f));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	pPlayer->SetType(GROUP_TYPE::PLAYER);
	AddObject(pPlayer, GROUP_TYPE::PLAYER);
	RegisterPlayer(pPlayer);

	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER_PROJECTILE);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PLAYER_PROJECTILE);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::GROUND, GROUP_TYPE::PLAYER);

	//CameraLook 지정
	Vec2 vResolution = CGameCore::GetInst()->GetResoultion();
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);

	//Camera효과 지정
	CCamera::GetInst()->FadeOut(1.f);
	CCamera::GetInst()->FadeIn(1.f);

	init();
}

void CScene_Start::Exit()
{
	DeleteAll();
	CCollisionMgr::GetInst()->Reset();
}


