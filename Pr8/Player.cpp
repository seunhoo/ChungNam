#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"
Player::Player(Vec2 pos)
	:m_PlayerSpeed(5)
	,m_PlayerHp(5)
	,m_GunState(GunState::RIFLE)
{
	m_Player = Sprite::Create(L"Painting/Object/Player.png");
	m_Player->SetParent(this);
	SetPosition(pos);

	m_GunImage = Sprite::Create(L"Painting/Object/Rifle.png");
	m_GunImage->SetPosition(150, 50);

	m_Focus = Sprite::Create(L"Painting/Object/Focus.png");
	m_Focus->SetPosition(350, 50);

	m_FocusAnimation = new Animation();
	m_FocusAnimation->AddContinueFrame(L"Painting/Animation/Focus", 0, 3);
	m_FocusAnimation->Init(5, 1);
	m_FocusAnimation->SetPosition(m_Position);

	m_BulletText = new TextMgr();
	m_BulletText->Init(60, "±Ã¼­Ã¼");
	m_BulletText->SetColor(255, 0, 0, 0);


	m_RifleBullet = 30;
	m_CannonBullet = 5;
	m_TorBullet = 1;
	m_MissileBullet = 1;

	m_MaxRifleBullet = 30;
	m_MaxCannonBullet = 5;
	m_MaxTorBullet = 1;
	m_MaxMissileBullet = 1;
	m_RifleDelayTime = 0.1f;

	m_Bullet = m_RifleBullet;
	m_MaxBullet = m_MaxRifleBullet;

	m_FocusSkillDelay = 21;
	m_FocusCheck = false;
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
	Attack(deltatime, time);
	m_FocusAnimation->SetPosition(m_Position);
}

void Player::Attack(float deltatime, float time)
{
	if (INPUT->GetKey(0x31) == KeyState::DOWN)
	{
		m_GunState = GunState::RIFLE;
		m_GunImage = Sprite::Create(L"Painting/Object/Rifle.png");
		m_GunImage->SetPosition(150, 50);

		
		m_MaxRifleBullet = 30;

		m_Bullet = m_RifleBullet;
		m_MaxBullet = m_MaxRifleBullet;
	}
	else if (INPUT->GetKey(0x32) == KeyState::DOWN)
	{
		m_GunState = GunState::CANNON;
		m_GunImage = Sprite::Create(L"Painting/Object/Cannon.png");
		m_GunImage->SetPosition(150, 50);

		m_Bullet = m_CannonBullet;
		m_MaxBullet = m_MaxCannonBullet;
		m_MaxCannonBullet = 5;
	}
	else if (INPUT->GetKey(0x33) == KeyState::DOWN)
	{
		m_GunState = GunState::TOR;
		m_GunImage = Sprite::Create(L"Painting/Object/Tor.png");
		m_GunImage->SetPosition(150, 50);

		m_Bullet = m_TorBullet;
		m_MaxBullet = m_MaxTorBullet;
		m_MaxTorBullet = 1;
	}
	else if (INPUT->GetKey(0x34) == KeyState::DOWN)
	{
		m_GunState = GunState::MISSILE;
		m_GunImage = Sprite::Create(L"Painting/Object/Missile.png");
		m_GunImage->SetPosition(150, 50);

		m_Bullet = m_MissileBullet;
		m_MaxBullet = m_MaxMissileBullet;
		m_MaxMissileBullet = 1;
	}

	m_ShotDelay += dt;
	if (INPUT->GetButtonDown())
	{
		if (m_GunState == GunState::RIFLE && m_ShotDelay > m_RifleDelayTime && m_RifleBullet >0)
		{

			if(!m_FocusCheck)
				m_RifleBullet--;

			m_Bullet = m_RifleBullet;
			ObjMgr->AddObject(new Bullet(m_Position,1), "Bullet");
			m_ShotDelay = 0;
		}
		else if (m_GunState == GunState::CANNON && m_ShotDelay > 0.5f && m_CannonBullet >0)
		{
			m_CannonBullet--;
			m_Bullet = m_CannonBullet;
			ObjMgr->AddObject(new Bullet(Vec2(m_Position.x ,m_Position.y - 50), 2), "Bullet");
			m_ShotDelay = 0;
			INPUT->ButtonDown(false);
		}
		else if(m_GunState == GunState::TOR && m_TorBullet >0)
		{
			m_TorBullet--;
			m_Bullet = m_TorBullet;
			ObjMgr->AddObject(new Bullet(m_Position, 3), "Bullet");
			m_ShotDelay = 0;
		}
		else if (m_GunState == GunState::MISSILE && m_MissileBullet >0)
		{
			m_MissileBullet--;
			m_Bullet = m_MissileBullet;
			ObjMgr->AddObject(new Bullet(m_Position, 4), "Bullet");
			m_ShotDelay = 0;
		}
	
	}


	if (INPUT->GetKey('Q') == KeyState::DOWN && m_FocusSkillDelay > 20 && m_FocusCheck == false)
	{
		m_FocusCheck = true;
		m_FocusSkillDelay = 0;
	}
	if (m_FocusSkillDelay < 20)
	{
		m_Focus->G = 0;
		m_Focus->B = 0;
	}
	else if (m_FocusSkillDelay > 20)
	{
		m_Focus->G = 255;
		m_Focus->B = 255;
	}
	if (m_FocusCheck)
	{
		m_FocusDuration += dt;
		
		if (m_FocusDuration < 5)
		{
			m_FocusAnimation->A = 255;
			m_FocusAnimation->Update(deltatime, time);
			
			m_RifleDelayTime /= 4;
		}
		else if (m_FocusDuration > 5)
		{
			m_FocusAnimation->A = 0;

			m_RifleDelayTime *= 4;
		}
	}
	if (m_FocusCheck == false)
	{
		m_FocusAnimation->A = 0;
		m_FocusSkillDelay += dt;
	}


	if (m_GunState == GunState::RIFLE && m_RifleBullet <= 0)
	{
		if (m_RifleReloadTime <= 5)
		{
			m_RifleReloadTime += dt;

			m_GunImage->R = 100;
			m_GunImage->G = 0;
			m_GunImage->B = 0;
		}
		else if (m_RifleReloadTime > 5)
		{
			m_GunImage->R = 255;	
			m_GunImage->B = 255;	
			m_GunImage->G = 255;	
			m_RifleBullet = 30;
			m_RifleReloadTime = 0;
			m_Bullet = m_RifleBullet;
		}

	}

	
	if (m_CannonBullet < 5)
	{
		m_CannonReloadTime += dt;

		if (m_CannonReloadTime > 1)
		{
			m_CannonBullet++;
			m_Bullet = m_CannonBullet;
			m_CannonReloadTime = 0;
		}

	}
	
}

void Player::Render()
{
	m_Player->Render();
	m_GunImage->Render();
	m_Focus->Render();
	m_FocusAnimation->Render();


	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_BulletText->print(to_string(m_Bullet) + "/" + to_string(m_MaxBullet),100,100);
	Renderer::GetInst()->GetSprite()->End();

}

void Player::OnCollision(Object* obj)
{
}
