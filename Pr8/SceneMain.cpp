#include "stdafx.h"
#include "SceneMain.h"
#include"Intro.h"

void SceneMain::Release()
{
}

void SceneMain::Init()
{
	m_Main = Sprite::Create(L"Painting/BackGround/Main.png");
	m_Main->SetPosition(1920 / 2, 1080 / 2);


	m_Start = Sprite::Create(L"Painting/Button/Start.png");
	m_Start->SetPosition(1500, 500);
}

void SceneMain::Update(float deltatime, float time)
{
	if (CollisionMgr::GetInst()->CollideBox(m_Start) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Intro());
		INPUT->ButtonDown(false);
	}
}

void SceneMain::Render()
{
	m_Main->Render();
	m_Start->Render();
}
