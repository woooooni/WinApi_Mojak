#pragma once

#define SINGLETON(type) public:\
						static type* GetInst()\
						{\
							static type manager;\
							return &manager;\
						}\
						private:\
							type();\
							~type();

#define CLONE(type) type* Clone() { return new type(*this); }
#define DeltaTime CTimeMgr::GetInst()->GetfDT()
#define PI 3.1415926535


#define KEY_SITUATION(key) CKeyMgr::GetInst()->GetKeyState(key)
#define KEY_TAP(key) KEY_SITUATION(key) == KEY_STATE::TAP
#define KEY_HOLD(key) KEY_SITUATION(key) == KEY_STATE::HOLD
#define KEY_AWAY(AWAY) KEY_SITUATION(key) == KEY_STATE::AWAY

enum class GROUP_TYPE 
{
	DEFAULT,
	TILE,
	GROUND,
	MONSTER,
	PLAYER,
	PLAYER_PROJECTILE,
	MONSTER_PROJECTILE,
	UI = 31,
	END = 32,
};

enum class SCENE_TYPE
{
	START,
	END
};

enum class EVENT_TYPE 
{
	CREATE_OBJECT,
	SCENE_CHANGE,
	DELETE_OBJECT,
	END,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	BLACK,
	END
};
enum class PEN_TYPE 
{
	RED,
	GREEN,
	BLUE,
	END
};
