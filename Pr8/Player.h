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

	Sprite* m_Focus;

	Sprite* m_AirShot;

	Animation* m_FocusAnimation;

	TextMgr* m_BulletText;

	TextMgr* m_FocusSkillCoolTime;
	TextMgr* m_AirShotSkillCoolTime;


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

	float m_RifleDelayTime;

	float m_FocusSkillDelay;
	float m_FocusDuration;
	bool m_FocusCheck;

	float m_AirshotSkillDelay;
	bool m_AirShotCheck;


	Player(Vec2 pos);

	void Update(float deltatime, float time);
	void Attack(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

