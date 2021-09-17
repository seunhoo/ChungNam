#include "stdafx.h"
#include "Minimap.h"
#include "Boss.h"
Minimap::Minimap()
{
	m_MiniMap = Sprite::Create(L"Painting/BackGround/Minimap.png");
	m_MiniMap->SetParent(this);
	SetPosition(550,75);

	m_SmallPlayer = Sprite::Create(L"Painting/BackGround/SmallPlayer.png");
	m_SmallPlayer->SetPosition(440, 82);

}

void Minimap::Update(float deltatime, float time)
{
	if (INPUT->GetKey('P') == KeyState::DOWN)
	{
		ObjMgr->AddObject(new Boss(1,0), "Boss");
		ObjMgr->AddObject(new Boss(2,0), "Boss");
		ObjMgr->AddObject(new Boss(3,0), "Boss");
		ObjMgr->AddObject(new Boss(4,0), "Boss");
		ObjMgr->AddObject(new Boss(5,0), "Boss");
		ObjMgr->AddObject(new Boss(6,0), "Boss");
		ObjMgr->AddObject(new Boss(7,0), "Boss");
	}
	if (INPUT->GetKey('L') == KeyState::DOWN)
	{
		ObjMgr->AddObject(new Boss(1, 1), "Boss");
		ObjMgr->AddObject(new Boss(2, 1), "Boss");
		ObjMgr->AddObject(new Boss(3, 1), "Boss");
		ObjMgr->AddObject(new Boss(4, 1), "Boss");
		ObjMgr->AddObject(new Boss(5, 1), "Boss");
		ObjMgr->AddObject(new Boss(6, 1), "Boss");
		ObjMgr->AddObject(new Boss(7, 1), "Boss");
	}
	if (m_SmallPlayer->m_Position.x >= m_Position.x + 110)
	{
		ObjMgr->AddObject(new Boss(1,0), "Boss");
		ObjMgr->AddObject(new Boss(2,0), "Boss");
		ObjMgr->AddObject(new Boss(3,0), "Boss");
		ObjMgr->AddObject(new Boss(4,0), "Boss");
	}
	else
		m_SmallPlayer->m_Position.x += 0.056f;

}

void Minimap::Render()
{
	m_MiniMap->Render();
	m_SmallPlayer->Render();
}

void Minimap::OnCollision(Object* obj)
{
}
