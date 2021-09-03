#pragma once
class Intro : public Scene
{
private:
	Sprite* m_Intro;


public:

	bool m_Change;

	void Release();
	void Init();

	void Update(float deltatime, float time);
	void Render();
};

