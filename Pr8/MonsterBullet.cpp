#include "stdafx.h"
#include "MonsterBullet.h"

MonsterBullet::MonsterBullet(Vec2 pos, int type)
{
	m_MonsterBullet = Sprite::Create(L"Painting/Monster/MonsterBullet.png");
	m_MonsterBullet->SetParent(this);
	SetPosition(pos);
}

void MonsterBullet::Update(float deltatime, float time)
{
	ObjMgr->CollisionCheak(this, "Player");
	m_Position.x -= 10;

	if (m_Position.x < 0)
		ObjMgr->RemoveObject(this);
}

void MonsterBullet::Render()
{
	m_MonsterBullet->Render();
}

void MonsterBullet::OnCollsion(Object* obj)
{
	if (obj->m_Tag == "Player")
		ObjMgr->RemoveObject(this);
}
