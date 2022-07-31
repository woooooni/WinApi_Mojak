#pragma once
#include "pch.h"
enum class KEY_STATE 
{
	NONE,
	TAP,
	HOLD,
	AWAY
};

enum class KEY 
{
	LEFT_ARROW,
	RIGHT_ARROW,
	UP_ARROW,
	DOWN_ARROW,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	ALT, CTRL, SHIFT,
	SPACE, ENTER, ESC,
	LBTN, RBTN,
	END
};

struct tKeyInfo
{
	KEY_STATE	eState; // 키의 상태
	bool		bPrevPushed;
};

class CKeyMgr
{
	SINGLETON(CKeyMgr);

private:
	vector<tKeyInfo>	m_vecKey;
	Vec2				m_vCurMousePos;

public:
	void init();
	void update();

public:
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }

	Vec2 GetMousePos(){	return m_vCurMousePos; }
};

