#pragma once

class CAnimator;
class CTexture;
class CSound;
typedef void(*ANIMATION_EVENT)(DWORD_PTR, DWORD_PTR);

struct tAnimFrame
{
	Vec2				vLT;
	Vec2				vSlice;
	Vec2				vOffset;
	CSound*				sound;

	ANIMATION_EVENT		animEvent;		// 애니메이션 이벤트 함수.
	DWORD_PTR			evtParam1;		// 애니메이션 이벤트 함수 매개변수.
	DWORD_PTR			evtParam2;		// 애니메이션 이벤트 함수 매개변수.

	float				fDuration;
};

class CAnimation
{
private:
	wstring					m_strName;		//	애니메이션 이름.
	CAnimator*				m_pAnimator;	//	애니메이터.
	CTexture*				m_pTex;			//	애니메이션이 사용할 텍스쳐.
	vector<tAnimFrame>		m_vecFrame;		//	애니메이션 프레임 정보.
	int						m_iCurFrm;		//	현재 프레임.
	float					m_fAccTime;		//	누적시간.


	bool					m_bFinish;		// 애니메이션이 끝났음을 알려주기위한 변수.
	bool					m_bLastFinished;// 애니메이션이 이전에 실행되었는지 알려주기 위한 변수.

private:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }
	bool IsFinished() { return m_bFinish; }
	bool IsLastFinished() { return m_bLastFinished; }
	void SetFrame(int _iFrameIdx)
	{
		m_bFinish = false;
		m_iCurFrm = _iFrameIdx;
		m_fAccTime = 0.f;
	}
	tAnimFrame& GetFrame(int _iIdx) { return m_vecFrame[_iIdx]; }
	UINT GetMaxFrame() { return (UINT)m_vecFrame.size(); }

public:
	void Create(CTexture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, Vec2 _vStep, float _fDuration, UINT _iFrameCount);
	
	void AddSound(CSound* _pSound, int _idx);
	void AddEvent(ANIMATION_EVENT _pCallBack, DWORD_PTR param1, DWORD_PTR param2, int _idx);
	//void Save(const wstring& _strRelativePath);
	//void Load(const wstring& _strRelativePath);

public:
	void update();
	void render(HDC _dc);

private:
	void Play(HDC _dc, Vec2 _vRenderPos);

public:
	CAnimation();
	~CAnimation();

	friend class CAnimator;
};

