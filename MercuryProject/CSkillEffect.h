#pragma once
#include "CObject.h"
class CSkillEffect
	:public CObject
{
protected:
	Vec2		m_vOffsetPos;
	CObject*	m_pFollowObj;
	bool		m_bFollow;


public:
	virtual void init();
	virtual void update();
	virtual void render(HDC _dc);

public:
	void SetFollowObj(CObject* _pObj) { m_pFollowObj = _pObj; }

public:
	CSkillEffect(Vec2 _vOffset, bool _bFollow);
	virtual ~CSkillEffect();
};

