#include "stdafx.h"
#include "StageOne.h"
#include "Minimap.h"
void StageOne::Release()
{
}

void StageOne::Init()
{
	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne.png");
	m_StageOneBackGround->SetPosition(1920/2, 1080 / 2);

	m_Wave = new Animation();
	m_Wave->AddContinueFrame(L"Painting/BackGround/Wave", 0, 1);
	m_Wave->Init(0.5f, 1);
	m_Wave->SetPosition(1920 / 2, 830);

	ObjMgr->AddObject(new Player(Vec2(300, 800)), "Player");
	ObjMgr->AddObject(new Minimap(), "MiniMap");

}

void StageOne::Update(float deltatime, float time)
{
	m_Wave->Update(deltatime, time);

}

void StageOne::Render()
{
	m_StageOneBackGround->Render();
	m_Wave->Render();

}
