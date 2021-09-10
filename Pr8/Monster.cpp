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
	}
	if (type == 2)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Knuckle", 0, 3);
		m_Monster->Init(0.3f, 1);
		m_Monster->SetParent(this);
	}
	if (type == 3)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Bat", 0, 4);
		m_Monster->Init(0.3f, 1);
		m_Monster->SetParent(this);
	}
	if (type == 4)
	{
		m_Monster = new Animation();
		m_Monster->AddContinueFrame(L"Painting/Monster/Fly", 0, 3);
		m_Monster->Init(0.3f, 1);
		m_Monster->SetParent(this);
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
