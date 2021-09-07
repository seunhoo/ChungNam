#pragma once
class AirShot : public Object
{
public:

	Animation* m_AirShot;

	AirShot();

public:

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);

};

