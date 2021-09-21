#pragma once
class DeathAvatar : public Object
{
public:

	Animation* m_Ani;

	Sprite* m_GO;

	DeathAvatar(Vec2 pos);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);

	float deletetime;

};

