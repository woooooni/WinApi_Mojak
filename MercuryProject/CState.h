#pragma once
class CState
{
public:
	virtual void update() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;

public:
	CState();
	virtual ~CState();

};

