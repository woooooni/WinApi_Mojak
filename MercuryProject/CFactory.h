#pragma once

class CObject;
class CMonster;
class CPlayer;
class CFactory
{
	static CPlayer* CreatePlayer();
	static CMonster* CreateMonster();
};

