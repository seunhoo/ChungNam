#pragma once
class Animation: public Object
{
public:
	std::vector<Sprite*>m_Anim;

	float m_FrameCount;
	int A, R, G, B;
	bool m_Autoplay;
	float m_Delay;
	float m_CurrentFrame;

public:

	void AddCountinueFrmae(std::wstring fileName, int firstframe, int lastframe);

	void Init(bool play, float delay);

	void Update(float deltatime, float time);

	void Render();
};

