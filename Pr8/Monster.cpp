#include "stdafx.h"
#include "Monster.h"

Monster::Monster(Vec2 pos, int type)
{
	m_Monster = new Animation();
	m_Monster->AddContinueFrame(L"Painting/Monster/Sonic", 0, 2);
	m_Monster->Init(0.3f, 1);
	m_Monster->SetParent(this);
	SetPosition(pos);

	m_Type = type;
}

void Monster::Update(float deltatime, float time)
{
	m_Monster->Update(deltatime, time);

	if(!m_FirstSpawnCheck)
		m_Position.x -= 10;
	if (m_Position.x < 1800)
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
