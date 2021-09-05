#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Vec2 pos, int type)
{
	if (type == 1)
	{
		m_Bullet = Sprite::Create(L"Painting/Object/Bullet.png");
		
		m_GunState = BulletState::RIFLE;
	}
	else if (type == 2)
	{
		m_Bullet = Sprite::Create(L"Painting/Object/CannonBullet.png");
		m_GunState = BulletState::CANNON;
	}
	else if (type == 3)
	{
		m_Bullet = Sprite::Create(L"Painting/Object/Bullet.png");
		m_GunState = BulletState::TOR;
	}
	else if (type == 4)
	{
		m_Bullet = Sprite::Create(L"Painting/Object/Bullet.png"); 
		m_GunState = BulletState::MISSILE;
	}
	m_Bullet->SetParent(this);
	SetPosition(pos);
}

void Bullet::Update(float deltatime, float time)
{
	cout << 123 << endl;
	m_Position.x += 10;

	if (m_Position.x > 1920)
		ObjMgr->RemoveObject(this);
}

void Bullet::Render()
{
	m_Bullet->Render();
}

void Bullet::OnCollision(Object* obj)
{
}
