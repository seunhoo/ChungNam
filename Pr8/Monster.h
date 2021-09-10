#pragma once
class Monster  :public Object
{
public:

	Animation* m_Monster;

	Monster(Vec2 pos, int type);

	int m_Type;

	bool m_FirstSpawnCheck;

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

