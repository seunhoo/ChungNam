#pragma once
enum class BulletState
{
	RIFLE,
	CANNON,
	TOR,
	MISSILE
};
class Bullet : public Object
{
private:

	Sprite* m_Bullet;

	BulletState m_GunState;

	int m_Type;

public:

	Bullet(Vec2 pos, int type);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

