#pragma once
class StageOne : public Scene
{
public:
	Sprite* m_StageOneBackGround;


	void Release();
	void Init();

	void Update(float deltatime, float time);
	void Render();

};

