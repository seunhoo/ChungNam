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
		m_Monster->Init(0.3f, 1);
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
	m_Monster->Update(deltatime, time);

	if(!m_FirstSpawnCheck)
		m_Position.x -= 10;
	if (m_Position.x < 1700)
		m_FirstSpawnCheck = true;


	if (m_Type == 1)
	{
		m_MoveTime += dt;
		m_AtkTime += dt;
		if (m_MoveTime > 1)
		{
			int random = rand() % 4 + 1;
			if (random == 1)
			{
				m_Position.x -= 7;
				m_Position.y += 2;
			}
			if (random == 2)
			{
				m_Position.x += 5;
				m_Position.y -= 3;
			}
			if (random == 3)
			{
				m_Position.x -= 6;
				m_Position.y -= 3;
			}
			if (random == 4)
			{
				m_Position.x += 7;
				m_Position.y += 5;
			}
			if(m_MoveTime > 1.6f)
				m_MoveTime = 0;
		}

		if (m_AtkTime > 0.3f)
		{
			int random = rand() % 3 + 1;
			if (random == 1)
			{
				ObjMgr->AddObject(new MonsterBullet(m_Position,1), "Bullet");
			}
		}
		if (m_AtkTime > 0.8f)
		{
			m_AtkTime = 0;
		}

	}
	if (m_Type == 2)
	{

	}
	if (m_Type == 3)
	{

	}


}

void Monster::Render()
{
	m_Monster->Render();
}

void Monster::OnCollision(Object* obj)
{
}
