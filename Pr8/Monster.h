#pragma once
class Monster  :public Object
{
public:

	Animation* m_Monster;

	Monster(Vec2 pos, int type);

	float m_MoveTime;
	float m_AtkTime;

	bool m_MoveCheck;

	int m_MonsterHp;

	int m_Type;

	int random;

	bool m_FirstSpawnCheck;

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

