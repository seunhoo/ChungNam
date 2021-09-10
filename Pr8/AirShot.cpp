#include "stdafx.h"
#include "AirShot.h"
#include "Bullet.h"
AirShot::AirShot()
{
	m_Plane = Sprite::Create(L"Painting/Object/Plane.png");
	m_Plane->SetParent(this);
	SetPosition(-100, 170);
}

void AirShot::Update(float deltatime, float time)
{
	m_Position.x += 20;

	if ((int)m_Position.x % 100 == 0)
	{
		ObjMgr->AddObject(new Bullet(m_Position, 5), "Bullet");
	}
}

void AirShot::Render()
{
	m_Plane->Render();

	if (m_Position.x > 1920)
		ObjMgr->RemoveObject(this);
}

void AirShot::OnCollision(Object* obj)
{
}
