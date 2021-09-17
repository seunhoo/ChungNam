#include "stdafx.h"
#include "Monster.h"
#include "MonsterBullet.h"
Monster::Monster(Vec2 pos, int type)
{
	if (type == 1)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Sonic", 0, 2);
		m_Monster->Init(0.3f, 1);
		m_Monster->SetParent(this);
		
		m_MonsterHp = 10;
	}
	if (type == 2)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Knuckle", 0, 3);
		m_Monster->Init(0.3f, 1);
		m_Monster->SetParent(this);

		m_MonsterHp = 10;
	}
	if (type == 3)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Bat", 0, 4);
		m_Monster->Init(0.1f, 1);
		m_Monster->SetParent(this);

		m_MonsterHp = 10;
	}
	if (type == 4)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Fly", 0, 3);
		m_Monster->Init(0.3f, 1);
		m_Monster->SetParent(this);

		m_MonsterHp = 10;
	}

	SetPosition(pos);

	m_Type = type;
}

void Monster::Update(float deltatime, float time)
{
	ObjMgr->CollisionCheak(this, "Player");
	m_Monster->Update(deltatime, time);

	if(!m_FirstSpawnCheck)
		m_Position.x -= 10;
	if (m_Position.x < 1700)
		m_FirstSpawnCheck = true;


	if (m_Type == 1)
	{
		m_MoveTime += dt;
		m_AtkTime += dt;
		if (m_MoveTime > 2 && m_MoveCheck == false)
		{
			m_MoveCheck = true;
			 random = rand() % 4 + 1;
		}

		if (m_MoveCheck == true)
		{

			if (random == 1  && m_Position.x >1200  && m_Position.y < 1060)
			{
				m_Position.x -= 5;
				m_Position.y += 2;
			}
			if (random == 2 && m_Position.x < 1880   && m_Position.y >580)
			{
				m_Position.x += 5;
				m_Position.y -= 3;
			}
			if (random == 3 && m_Position.x >1200 && m_Position.y >580)
			{
				m_Position.x -= 6;
				m_Position.y -= 3;
			}
			if (random == 4 && m_Position.x < 1880  && m_Position.y < 1060)
			{
				m_Position.x += 4;
				m_Position.y += 5;
			}
			if (m_MoveTime > 2.7f)
			{
				m_MoveTime = 0;
				m_MoveCheck = false;
			}
		}

		if (m_AtkTime > 0.7f)
		{
			int rd = rand() % 3 + 1;
			if (rd == 1)
			{
				ObjMgr->AddObject(new MonsterBullet(m_Position,1), "MonsterBullet");
			}
		}
		if (m_AtkTime > 0.71f)
		{
			m_AtkTime = 0;
		}

	}
	if (m_Type == 2)
	{
		m_MoveTime += dt;
		m_AtkTime += dt;
		if (m_MoveTime > 2 && m_MoveCheck == false)
		{
			m_MoveCheck = true;
			random = rand() % 4 + 1;
		}

		if (m_MoveCheck == true)
		{

			if (random == 1 && m_Position.x > 1200 && m_Position.y < 1060)
			{
				m_Position.x -= 5;
				m_Position.y += 2;
			}
			if (random == 2 && m_Position.x < 1880 && m_Position.y >580)
			{
				m_Position.x += 5;
				m_Position.y -= 3;
			}
			if (random == 3 && m_Position.x > 1200 && m_Position.y > 580)
			{
				m_Position.x -= 6;
				m_Position.y -= 3;
			}
			if (random == 4 && m_Position.x < 1880 && m_Position.y < 1060)
			{
				m_Position.x += 4;
				m_Position.y += 5;
			}
			if (m_MoveTime > 2.7f)
			{
				m_MoveTime = 0;
				m_MoveCheck = false;
			}
		}
		if (m_AtkTime > 0.7f)
		{
			int rd = rand() % 3 + 1;
			if (rd == 1)
			{
				ObjMgr->AddObject(new MonsterBullet(m_Position, 1), "MonsterBullet");
			}
		}
		if (m_AtkTime > 0.71f)
		{
			m_AtkTime = 0;
		}
	}
	if (m_Type == 3)
	{
		m_MoveTime += dt;
		m_AtkTime += dt;
		if (m_MoveTime > 2 && m_MoveCheck == false)
		{
			m_MoveCheck = true;
			random = rand() % 4 + 1;
		}

		if (m_MoveCheck == true)
		{

			if (random == 1 && m_Position.x > 1200 && m_Position.y < 1060)
			{
				m_Position.x -= 5;
				m_Position.y += 2;
			}
			if (random == 2 && m_Position.x < 1880 && m_Position.y >580)
			{
				m_Position.x += 5;
				m_Position.y -= 3;
			}
			if (random == 3 && m_Position.x > 1200 && m_Position.y > 580)
			{
				m_Position.x -= 6;
				m_Position.y -= 3;
			}
			if (random == 4 && m_Position.x < 1880 && m_Position.y < 1060)
			{
				m_Position.x += 4;
				m_Position.y += 5;
			}
			if (m_MoveTime > 2.7f)
			{
				m_MoveTime = 0;
				m_MoveCheck = false;
			}
		}
		if (m_AtkTime > 0.7f)
		{
			int rd = rand() % 3 + 1;
			if (rd == 1)
			{
				ObjMgr->AddObject(new MonsterBullet(m_Position, 1), "MonsterBullet");
			}
		}
		if (m_AtkTime > 0.71f)
		{
			m_AtkTime = 0;
		}
	}

	if (m_Type == 4)
	{
		m_MoveTime += dt;
		m_AtkTime += dt;
		if (m_MoveTime > 2 && m_MoveCheck == false)
		{
			m_MoveCheck = true;
			random = rand() % 4 + 1;
		}

		if (m_MoveCheck == true)
		{

			if (random == 1 && m_Position.x > 1200 && m_Position.y < 1060)
			{
				m_Position.x -= 5;
				m_Position.y += 2;
			}
			if (random == 2 && m_Position.x < 1880 && m_Position.y >580)
			{
				m_Position.x += 5;
				m_Position.y -= 3;
			}
			if (random == 3 && m_Position.x > 1200 && m_Position.y > 580)
			{
				m_Position.x -= 6;
				m_Position.y -= 3;
			}
			if (random == 4 && m_Position.x < 1880 && m_Position.y < 1060)
			{
				m_Position.x += 4;
				m_Position.y += 5;
			}
			if (m_MoveTime > 2.7f)
			{
				m_MoveTime = 0;
				m_MoveCheck = false;
			}
		}
	}


}

void Monster::Render()
{
	m_Monster->Render();
}

void Monster::OnCollision(Object* obj)
{
}
