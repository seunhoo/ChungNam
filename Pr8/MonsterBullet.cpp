#include "stdafx.h"
#include "MonsterBullet.h"

MonsterBullet::MonsterBullet(Vec2 pos, int type)
{
	if (type == 1)
	{
		m_MonsterBullet = Sprite::Create(L"Painting/Monster/MonsterBullet.png");
		m_MonsterBullet->SetParent(this);
	}
	if (type == 2)
	{
		m_MonsterBullet = Sprite::Create(L"Painting/Monster/MonsterBullet.png");
		m_MonsterBullet->SetParent(this);
	}
	if (type == 3)
	{
		m_MonsterBullet = Sprite::Create(L"Painting/Monster/MonsterBullet.png");
		m_MonsterBullet->SetParent(this);
	}
	if (type == 4)
	{
		m_MonsterBullet = Sprite::Create(L"Painting/Monster/MonsterBullet.png");
		m_MonsterBullet->SetParent(this);
	}
	
	SetPosition(pos);
}

void MonsterBullet::Update(float deltatime, float time)
{
	ObjMgr->CollisionCheak(this, "Player");
	m_Position.x -= 10;

	if (m_Position.x < 0 || m_Position.y > 1080 || m_Position.y < 0 ||  m_Position.x >1920)
		ObjMgr->RemoveObject(this);
}

void MonsterBullet::Render()
{
	m_MonsterBullet->Render();
}

void MonsterBullet::OnCollision(Object* obj)
{
	if (obj->m_Tag == "Player")
		ObjMgr->RemoveObject(this);
}
