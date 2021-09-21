#pragma once
class StageOne : public Scene
{
public:
	Sprite* m_StageOneBackGround;

	Sprite* m_Score;

	Animation* m_Wave;

	bool m_Check;


	float a;

	float m_MonsterSpawnTime;

	void Release();
	void Init();

	void Update(float deltatime, float time);
	void Render();

};

