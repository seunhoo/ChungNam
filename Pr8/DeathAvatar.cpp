#include "stdafx.h"
#include "DeathAvatar.h"
#include"DeathScene.h"
DeathAvatar::DeathAvatar(Vec2 pos)
{
	m_Ani = new Animation();
	m_Ani->AddContinueFrame(L"Painting/Animation/Effects_", 0, 10);
	m_Ani->Init(0.2f, 1);
	m_Ani->SetParent(this);
	m_Scale *= 3;
	SetPosition(pos);

	m_GO = Sprite::Create(L"Painting/UI/GameOver.png");
	m_GO->SetPosition(1920 / 2, -50);
	m_GO->m_Scale *= 3;
}

void DeathAvatar::Update(float deltatime, float time)
{
	if (m_GO->m_Position.y <= 1080 / 2)
	{
		m_GO->m_Position.y += 10;
	}
	else
		m_GO->m_Position.y -= 15;
	m_Ani->Update(deltatime, time);

	deletetime += dt;
	if (deletetime >= 5)
	{
		ObjMgr->RemoveObject(this);
		ObjMgr->Release();
		SceneDirector::GetInst()->ChangeScene(new DeathScene());
	}
}

void DeathAvatar::Render()
{
	m_Ani->Render();
	m_GO->Render();
}

void DeathAvatar::OnCollision(Object* obj)
{
}
