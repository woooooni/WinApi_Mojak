#include "pch.h"
#include "CFactory.h"
#include "CPlayer.h"
//#include "CMonster.h"

CPlayer* CFactory::CreatePlayer()
{
	CPlayer* player = new CPlayer;
	player->SetType(GROUP_TYPE::PLAYER);
	return player;
}

CMonster* CFactory::CreateMonster()
{
	return nullptr;
}
