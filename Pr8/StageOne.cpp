#include "stdafx.h"
#include "StageOne.h"
#include "Minimap.h"
void StageOne::Release()
{
}

void StageOne::Init()
{
	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne.png");
	m_StageOneBackGround->SetPosition(1920 / 2, 1080 / 2);

	m_Sun = Sprite::Create(L"Painting/BackGround/Sun.png");
	m_Sun->SetPosition(1920, 540);

	m_Wave = new Animation();
	m_Wave->AddContinueFrame(L"Painting/BackGround/Wave", 0, 5);
	m_Wave->Init(0.1,1);
	m_Wave->SetPosition(1920/2, 1080 / 2);
	
	ObjMgr->AddObject(new Player(Vec2(300, 800)), "Player");
	ObjMgr->AddObject(new Minimap(), "MiniMap");

}

void StageOne::Update(float deltatime, float time)
{
	m_Wave->Update(deltatime, time);


	m_Sun->m_Position.x -= 0.7;


	if (m_Sun->m_Position.x <= 1920 / 2)
		m_Sun->m_Position.y += 0.5;
	else
		m_Sun->m_Position.y -= 0.5;

	if(m_Sun->m_Position.y >570)
		m_Sun->SetPosition(1920, 540);
	

}

void StageOne::Render()
{
	m_StageOneBackGround->Render();
	m_Sun->Render();
	m_Wave->Render();
}
