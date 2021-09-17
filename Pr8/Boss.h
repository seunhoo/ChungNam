#pragma once
class Boss : public Object
{
public:

	Sprite* m_BossHead;
	Sprite* m_BossHand;
	Sprite* m_BossArm;
	Sprite* m_BossArmor;

	Sprite* m_BossHand1;
	Sprite* m_BossArm1;
	Sprite* m_BossArmor1;



	float m_RotateTime;

	float m_SpawnTime;
	
	bool m_SpawnCheck;

	int m_Type;

	Boss(int type, bool stage);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);

};

