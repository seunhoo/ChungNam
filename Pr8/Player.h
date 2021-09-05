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

	Sprite* m_GunImage;

	TextMgr* m_BulletText;


	int m_PlayerHp;
	int m_PlayerSpeed;

	float m_ShotDelay;

	int m_Bullet;
	int m_MaxBullet;

	int m_RifleBullet;
	int m_CannonBullet;
	int m_TorBullet;
	int m_MissileBullet;

	int m_MaxRifleBullet;
	int m_MaxCannonBullet;
	int m_MaxTorBullet;
	int m_MaxMissileBullet;

	float m_RifleReloadTime;
	float m_CannonReloadTime;



	Player(Vec2 pos);

	void Update(float deltatime, float time);
	void Attack();
	void Render();
	void OnCollision(Object* obj);
};

