#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"
Player::Player(Vec2 pos)
	:m_PlayerSpeed(5)
	,m_PlayerHp(5)
{
	m_Player = Sprite::Create(L"Painting/Object/Player.png");
	m_Player->SetParent(this);
	SetPosition(pos);


}
 
void Player::Update(float deltatime, float time)
{
	if (INPUT->GetKey('W') == KeyState::PRESS)
	{
		m_Position.y -= m_PlayerSpeed;
	}
	if (INPUT->GetKey('S') == KeyState::PRESS)
	{
		m_Position.y += m_PlayerSpeed;
	}
	if (INPUT->GetKey('A') == KeyState::PRESS)
	{
		m_Position.x -= m_PlayerSpeed;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS)
	{
		m_Position.x += m_PlayerSpeed;
	}
	Attack();
}

void Player::Attack()
{
	if (INPUT->GetKey(0x31) == KeyState::DOWN)
	{
		m_GunState = GunState::RIFLE;
	}
	else if (INPUT->GetKey(0x32) == KeyState::DOWN)
	{
		m_GunState = GunState::CANNON;
	}
	else if (INPUT->GetKey(0x33) == KeyState::DOWN)
	{
		m_GunState = GunState::TOR;
	}
	else if (INPUT->GetKey(0x34) == KeyState::DOWN)
	{
		m_GunState = GunState::MISSILE;
	}

	m_ShotDelay+= dt;

	if (INPUT->GetButtonDown())
	{
		if (m_GunState == GunState::RIFLE && m_ShotDelay > 0.3f)
		{
			ObjMgr->AddObject(new Bullet(m_Position,1), "Bullet");
			m_ShotDelay = 0;
		}
		else if (m_GunState == GunState::CANNON)
		{
			ObjMgr->AddObject(new Bullet(m_Position, 2), "Bullet");
			m_ShotDelay = 0;
		}
		else if(m_GunState == GunState::TOR)
		{
			ObjMgr->AddObject(new Bullet(m_Position, 3), "Bullet");
			m_ShotDelay = 0;
		}
		else if (m_GunState == GunState::MISSILE)
		{
			ObjMgr->AddObject(new Bullet(m_Position, 4), "Bullet");
			m_ShotDelay = 0;
		}
	
	}
}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj)
{
}
