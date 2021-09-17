#include "stdafx.h"
#include "Explosion.h"

Explosion::Explosion(float posx, float posy)
{
	m_Explose = new Animation();
	m_Explose->AddContinueFrame(L"Painting/Animation/Effects_30", 1, 9);
	m_Explose->Init(0.1f, 1);
	m_Explose->SetParent(this);
	m_Scale *= 2;
	SetPosition(posx,posy);
}

void Explosion::Update(float deltatime, float time)
{
	m_Explose->Update(deltatime, time);

	if (m_Explose->m_CurrentFrame >= 8)
	{
		ObjMgr->RemoveObject(this);
	}
}

void Explosion::Render()
{
	m_Explose->Render();
}

void Explosion::OnCollision(Object* obj)
{
}
