#pragma once
class AirShot : public Object
{
public:

	Sprite* m_Plane;

	AirShot();

public:

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);

};

