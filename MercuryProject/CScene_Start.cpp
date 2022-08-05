#include "pch.h"
#include "CScene_Start.h"

#include "CGameCore.h"

#include "CObject.h"
#include "CPlayer.h"
//#include "CMonster.h"
#include "CGround.h"

#include "CPathMgr.h"
#include "CTexture.h"

#include "CCollisionMgr.h"

#include "CSceneMgr.h"
#include "CSound.h"
#include "CKeyMgr.h"
#include "CCamera.h"
#include "CTimeMgr.h"
#include "CResMgr.h"

#include "CRigidBody.h"
#include "SelectGDI.h"
#include "EventFunc.h"

CScene_Start::CScene_Start()
	:m_pBgm(nullptr)
{
}

CScene_Start::~CScene_Start()
{
}


void CScene_Start::update()
{
	CScene::update();
	if (KEY_TAP(KEY::A))
	{
		CResMgr::GetInst()->VolumeUp(SOUND_CHANNEL_GROUP::BGM, 0.1);
	}
	if (KEY_TAP(KEY::S))
	{
		CResMgr::GetInst()->VolumeDown(SOUND_CHANNEL_GROUP::BGM, 0.1);
	}
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

	//Collision Detect
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER_PROJECTILE);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::MONSTER, GROUP_TYPE::PLAYER_PROJECTILE);
	CCollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::GROUND, GROUP_TYPE::PLAYER);


	//Ground 생성
	for (int i = 0; i < 30; i++)
	{
		CGround* pGround = new CGround;
		pGround->SetScale(Vec2(60.f, 1.f));
		pGround->SetPos(Vec2(i * 60.f, 700.f));
		pGround->SetType(GROUP_TYPE::GROUND);
		AddObject(pGround, GROUP_TYPE::GROUND);
	}


	//CameraLook 지정
	Vec2 vResolution = CGameCore::GetInst()->GetResoultion();
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);

	//Camera효과 지정
	CCamera::GetInst()->FadeOut(1.f);
	CCamera::GetInst()->FadeIn(1.f);

	//bgm Play
	m_pBgm = CResMgr::GetInst()->LoadSound(L"BGM_01", L"bgm\\bgm_01.mp3");
	m_pBgm->Play(SOUND_CHANNEL_GROUP::BGM);

	init();
}

void CScene_Start::Exit()
{
	DeleteAll();
	CCollisionMgr::GetInst()->Reset();
}


