#pragma once
class MonsterBullet : public Object
{
public:
	Sprite* m_MonsterBullet;

	MonsterBullet(Vec2 pos, int type);

	int m_Type;

	void Update(float deltatime, float time);
	void Render();
	void OnCollsion(Object* obj);
};

