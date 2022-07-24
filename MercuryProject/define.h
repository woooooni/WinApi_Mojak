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
#define DeltaTime CTimeMgr::GetInst()->GetfDT()
#define PI 3.1415926535

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
	TOOL,
	START,

	STAGE_01,
	STAGE_02,

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
