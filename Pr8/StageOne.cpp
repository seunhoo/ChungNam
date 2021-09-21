#include "stdafx.h"
#include "StageOne.h"
#include "Minimap.h"
#include"Monster.h"
void StageOne::Release()
{
}

void StageOne::Init()
{
	GM->SetStage(1);
	GM->SetBossStage(2);
	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne1.png");
	m_StageOneBackGround->SetPosition(3500, 1080 / 2);

	m_Score = Sprite::Create(L"Painting/BackGround/Score.png");
	m_Score->SetPosition(1920 / 2, 1080 / 2);

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
	if (GM->GetBossStage() == BossStage::BOSS)
	{

	}
	else if(GM->GetBossStage() == BossStage::NONE)
	{
		m_StageOneBackGround->m_Position.x -= 0.01f;
		m_Wave->Update(deltatime, time);

		m_MonsterSpawnTime += dt;
		a += dt;
		if (m_MonsterSpawnTime >= 7)
		{
			int random = rand() % 4 + 1;
			if (random == 1)
			{
				ObjMgr->AddObject(new Monster(Vec2(2000, 700), 1), "Monster");
			}
			else if (random == 2)
			{
				ObjMgr->AddObject(new Monster(Vec2(2200, 900), 2), "Monster");
			}
			else if (random == 3)
			{
				ObjMgr->AddObject(new Monster(Vec2(2200, 200), 3), "Monster");
			}
			else if (random == 4)
			{
				ObjMgr->AddObject(new Monster(Vec2(2200, 400), 4), "Monster");
			}

			m_MonsterSpawnTime = 0;
		}
	}
	

}

void StageOne::Render()
{
	m_StageOneBackGround->Render();
	m_Wave->Render();
	m_Score->Render();

}
