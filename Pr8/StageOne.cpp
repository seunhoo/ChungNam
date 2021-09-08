#include "stdafx.h"
#include "StageOne.h"
#include "Minimap.h"
void StageOne::Release()
{
}

void StageOne::Init()
{
	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne.png");
	m_StageOneBackGround->SetPosition(17000/2, 1080 / 2);

	m_Sun = Sprite::Create(L"Painting/BackGround/Sun.png");
	m_Sun->SetPosition(1920, 540);

	
	ObjMgr->AddObject(new Player(Vec2(300, 800)), "Player");
	ObjMgr->AddObject(new Minimap(), "MiniMap");

}

void StageOne::Update(float deltatime, float time)
{

	m_StageOneBackGround->m_Position.x -= 5;
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
}
