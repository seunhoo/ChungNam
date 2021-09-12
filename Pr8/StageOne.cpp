#include "stdafx.h"
#include "StageOne.h"
#include "Minimap.h"
#include"Monster.h"
void StageOne::Release()
{
}

void StageOne::Init()
{
	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne.png");
	m_StageOneBackGround->SetPosition(3500, 1080 / 2);

	m_Wave = new Animation();
	m_Wave->AddContinueFrame(L"Painting/BackGround/Wave", 0, 1);
	m_Wave->Init(0.5f, 1);
	m_Wave->SetPosition(1920 / 2, 830);

	ObjMgr->AddObject(new Player(Vec2(300, 800)), "Player");
	ObjMgr->AddObject(new Monster(Vec2(2400, 600),1), "Monster");
	ObjMgr->AddObject(new Minimap(), "MiniMap");

}

void StageOne::Update(float deltatime, float time)
{
	m_StageOneBackGround->m_Position.x -= 0.05f;
	m_Wave->Update(deltatime, time);

	m_MonsterSpawnTime += dt;
	if (m_MonsterSpawnTime >= 7)
	{
		ObjMgr->AddObject(new Monster(Vec2(2000, 700), 1), "Monster");
		ObjMgr->AddObject(new Monster(Vec2(2200, 900), 1), "Monster");
		m_MonsterSpawnTime = 0;
	}

}

void StageOne::Render()
{
	m_StageOneBackGround->Render();
	m_Wave->Render();

}
