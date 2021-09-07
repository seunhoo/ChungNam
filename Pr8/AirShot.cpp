#include "stdafx.h"
#include "AirShot.h"
#include "Bullet.h"
AirShot::AirShot()
{
	m_AirShot = new Animation();
	m_AirShot->AddContinueFrame(L"Painting/Animation/AirShot",0,3);
	m_AirShot->Init(1, 1);
	m_AirShot->SetParent(this);
	SetPosition(-100,150);
}

void AirShot::Update(float deltatime, float time)
{
	m_AirShot->Update(deltatime, time);

	m_Position.x += 5;

	if ((int)m_Position.x % 100 == 0)
	{
		ObjMgr->AddObject(new Bullet(m_Position,5), "Bullet");
	}
}

void AirShot::Render()
{
	m_AirShot->Render();

	if (m_Position.x > 1920)
		ObjMgr->RemoveObject(this);
}

void AirShot::OnCollision(Object* obj)
{
}
