#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"
#include"AirShot.h"
Player::Player(Vec2 pos)
	:m_PlayerSpeed(10)
	,m_PlayerHp(5)
	,m_GunState(GunState::RIFLE)
{
	m_Player = Sprite::Create(L"Painting/Object/Player.png");
	m_Player->SetParent(this);
	SetPosition(pos);

	m_HpBar = Sprite::Create(L"Painting/BackGround/HpBar.png");
	m_HpBar->SetPosition(180, 60);

	m_Hp = Sprite::Create(L"Painting/BackGround/Hp.png");
	m_Hp->SetPosition(180, 60);

	m_GunImage = Sprite::Create(L"Painting/Object/Rifle.png");
	m_GunImage->SetPosition(50, 170);

	m_Focus = Sprite::Create(L"Painting/Object/Focus.png");
	m_Focus->SetPosition(170, 170);

	m_AirShot = Sprite::Create(L"Painting/Object/AirShot.png");
	m_AirShot->SetPosition(290, 170);

	m_FocusAnimation = new Animation();
	m_FocusAnimation->AddContinueFrame(L"Painting/Animation/Focus", 0, 3);
	m_FocusAnimation->Init(0.1f, 1);
	m_FocusAnimation->SetPosition(m_Position.x, m_Position.y - 100);
	m_FocusAnimation->m_Scale *= 5;

	m_BulletText = new TextMgr();
	m_BulletText->Init(40, "±Ã¼­Ã¼"); 
	m_BulletText->SetColor(255, 255, 255, 255);

	m_FocusSkillCoolTime = new TextMgr();
	m_FocusSkillCoolTime->Init(40, "±Ã¼­Ã¼");
	m_FocusSkillCoolTime->SetColor(255, 255, 255,255);

	m_AirShotSkillCoolTime = new TextMgr();
	m_AirShotSkillCoolTime->Init(40, "±Ã¼­Ã¼");
	m_AirShotSkillCoolTime->SetColor(255, 255, 255, 255);



	m_RifleBullet = 30;
	m_CannonBullet = 5;
	m_TorBullet = 1;
	m_MissileBullet = 1;

	m_MaxRifleBullet = 30;
	m_MaxCannonBullet = 5;
	m_MaxTorBullet = 1;
	m_MaxMissileBullet = 1;
	m_RifleDelayTime = 0.3f;

	m_Bullet = m_RifleBullet;
	m_MaxBullet = m_MaxRifleBullet;

	m_AirshotSkillDelay = 0;
	m_FocusSkillDelay = 0;
	m_FocusCheck = false;
}
 
void Player::Update(float deltatime, float time)
{
	if (INPUT->GetKey('W') == KeyState::PRESS  && m_Position.y > 575)
	{
		m_Position.y -= m_PlayerSpeed;
	}
	if (INPUT->GetKey('S') == KeyState::PRESS && m_Position.y < 1080)
	{
		m_Position.y += m_PlayerSpeed;
	}
	if (INPUT->GetKey('A') == KeyState::PRESS && m_Position.x >10)
	{
		m_Position.x -= m_PlayerSpeed;
	}
	if (INPUT->GetKey('D') == KeyState::PRESS && m_Position.x <1910)
	{
		m_Position.x += m_PlayerSpeed;
	}
	Attack(deltatime, time);
	m_FocusAnimation->SetPosition(m_Position);


	if (INPUT->GetKey('K') == KeyState::PRESS)
	{
		m_Position.x -= 10;
		m_Position.y -= 10;
		//m_Position.x += 10;
		//m_Position.y += 10;
	}

}

void Player::Attack(float deltatime, float time)
{
	if (INPUT->GetKey(0x31) == KeyState::DOWN)
	{
		m_GunState = GunState::RIFLE;
		m_GunImage = Sprite::Create(L"Painting/Object/Rifle.png");
		m_GunImage->SetPosition(50, 170);

		
		m_MaxRifleBullet = 30;

		m_Bullet = m_RifleBullet;
		m_MaxBullet = m_MaxRifleBullet;
	}
	else if (INPUT->GetKey(0x32) == KeyState::DOWN)
	{
		m_GunState = GunState::CANNON;
		m_GunImage = Sprite::Create(L"Painting/Object/Cannon.png");
		m_GunImage->SetPosition(50, 170);

		m_Bullet = m_CannonBullet;
		m_MaxBullet = m_MaxCannonBullet;
		m_MaxCannonBullet = 5;
	}
	else if (INPUT->GetKey(0x33) == KeyState::DOWN)
	{
		m_GunState = GunState::TOR;
		m_GunImage = Sprite::Create(L"Painting/Object/Tor.png");
		m_GunImage->SetPosition(50, 170);

		m_Bullet = m_TorBullet;
		m_MaxBullet = m_MaxTorBullet;
		m_MaxTorBullet = 1;
	}
	else if (INPUT->GetKey(0x34) == KeyState::DOWN)
	{
		m_GunState = GunState::MISSILE;
		m_GunImage = Sprite::Create(L"Painting/Object/Missile.png");
		m_GunImage->SetPosition(50, 170);

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


	if (INPUT->GetKey('Q') == KeyState::DOWN && m_FocusSkillDelay <= 0 && m_FocusCheck == false)
	{
		m_FocusCheck = true;
		m_FocusSkillDelay = 20;
	}
	if (m_FocusSkillDelay >= 20)
	{
		m_Focus->G = 0;
		m_Focus->B = 0;
	}
	if (m_FocusSkillDelay <= 0)
	{
		m_FocusAnimation->A = 0; 
		m_Focus->G = 255;
		m_Focus->B = 255;
	}
	if (m_FocusCheck)
	{
		m_FocusDuration += dt;
		
		if (m_FocusDuration < 5)
		{
			m_FocusAnimation->SetPosition(m_Position.x, m_Position.y - 100);
			m_FocusAnimation->A = 255;
			m_FocusAnimation->Update(deltatime, time);
			
			m_RifleDelayTime = 0.3f /4;
		}
		else if (m_FocusDuration > 5)
		{
			m_FocusCheck = false;
			m_FocusAnimation->A = 0;
			m_RifleDelayTime = 0.3f;
			m_FocusDuration = 0;
		}
	}
	if (m_FocusCheck == false && m_FocusSkillDelay >= 0)
	{
		m_FocusAnimation->A = 0;
		m_FocusSkillDelay -= dt;
	}

	if (m_AirshotSkillDelay >= 0)
	{
		m_AirshotSkillDelay -= dt;
		m_AirShot->G = 0;
		m_AirShot->B = 0;
		
	}
	if (m_AirshotSkillDelay <= 0)
	{
		m_AirShot->G = 255;
		m_AirShot->B = 255;
	}



	if (INPUT->GetKey('E') == KeyState::DOWN && m_AirshotSkillDelay <= 0)
	{
		ObjMgr->AddObject(new AirShot(), "AirShot");
		m_AirshotSkillDelay = 30;
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
	m_AirShot->Render();

	m_HpBar->Render();
	m_Hp->Render();

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_BulletText->print(to_string(m_Bullet) + "/" + to_string(m_MaxBullet),3,230);
	m_FocusSkillCoolTime->print(to_string((int)m_FocusSkillDelay), 170, 230);
	m_AirShotSkillCoolTime->print(to_string((int)m_AirshotSkillDelay), 290, 230);
	Renderer::GetInst()->GetSprite()->End();

}

void Player::OnCollision(Object* obj)
{
}
