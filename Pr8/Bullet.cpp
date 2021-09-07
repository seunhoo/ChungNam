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
	else if (type == 5)
	{
		m_Bullet = Sprite::Create(L"Painting/Object/CannonBullet.png");
		m_GunState = BulletState::RIFLE;
	}
	m_Bullet->SetParent(this);
	SetPosition(pos);

	m_Type = type;
}

void Bullet::Update(float deltatime, float time)
{
	if (m_Position.x > 1920 || m_Position.y >1080)
		ObjMgr->RemoveObject(this);

	if (m_Type == 1)
	{
		m_Position.x += 10;
	}
	if (m_Type == 2)
	{
		m_Position.x += 10;
	}
	if (m_Type == 3)
	{
		m_Position.x += 10;
	}
	if (m_Type == 4)
	{
		m_Position.x += 10;
	}
	if (m_Type == 5)
	{
		m_Position.y += 5;
		m_Position.x += 1;
		m_Rotation = 80;
	}
}

void Bullet::Render()
{
	m_Bullet->Render();
}

void Bullet::OnCollision(Object* obj)
{
}
