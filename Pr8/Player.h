#pragma once
enum class GunState
{
	RIFLE,
	CANNON,
	TOR,
	MISSILE
};
class Player : public Object
{
private:
	GunState m_GunState;
public:

	Sprite* m_Player;

	int m_PlayerHp;
	int m_PlayerSpeed;

	int m_ShotDelay;



	Player(Vec2 pos);

	void Update(float deltatime, float time);
	void Attack();
	void Render();
	void OnCollision(Object* obj);
};

