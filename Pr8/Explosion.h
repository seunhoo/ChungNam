#pragma once
class Explosion : public Object
{
public:

	Animation* m_Explose;

	Explosion(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

