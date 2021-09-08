#pragma once
class SceneMain : public Scene
{
public:

	Sprite* m_Main;
	Sprite* m_Start;
	Sprite* m_Option;
	Sprite* m_Ranking;



	void Release();
	void Init();
	void Update(float deltatime, float time);
	void Render();


};

