#pragma once
class StageOne : public Scene
{
public:
	Sprite* m_StageOneBackGround;

	Animation* m_Wave;

	bool m_Check;


	void Release();
	void Init();

	void Update(float deltatime, float time);
	void Render();

};

