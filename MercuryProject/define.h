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

#define CLONE(type) type* Clone() { return new type(*this); }
#define PI 3.1415926535


#define KEY_CHECK(key, state) CKeyMgr::GetInst()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)

#define MOUSE_POS CKeyMgr::GetInst()->GetMousePos()

enum class GROUP_TYPE
{
	DEFAULT,
	TILE,
	GROUND,
	MONSTER,
	PLAYER,
	PLAYER_PROJECTILE,
	MONSTER_PROJECTILE,
	PLAYER_SKILL,
	MONSTER_SKILL,
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
	WHITE,
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END
};

enum class EVENT_TYPE
{
	ADD_OBJECT,
	DELETE_OBJECT,
	SCENE_CHANGE,
	STATE_CHANGE,
	CHANGE_STATE,


	END,
};

enum class COMPONENT_TYPE
{
	RIGIDBODY,
	COLLIDER,
	STATE_MACHINE,
	ANIMATOR,
	END
};
enum class PLAYER_STATE
{
	IDLE,
	MOVE,
	ATTACK,
	JUMP,
	JUMP_DOWN,
	END
};

enum class MONSTER_STATE
{
	IDLE,
	PATROL,
	TRACE,
	ATTACK,
	RUN_AWAY,
	DEAD,
	END
};

enum class SOUND_CHANNEL_GROUP
{
	BGM,
	SOUND_EFFECT,
	END
};

enum class ROLE_TYPE
{
	BIGGINER,
	SWORD_MASTER,
	Magician,
	ASSASIN,
	END
};


enum class DIR
{
	LEFT,
	RIGHT
};
