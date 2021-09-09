#include "stdafx.h"
#include "SceneMain.h"
#include"Intro.h"

void SceneMain::Release()
{
}

void SceneMain::Init()
{

	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne.png");
	m_StageOneBackGround->SetPosition(3500, 1080 / 2);

	m_Wave = new Animation();
	m_Wave->AddContinueFrame(L"Painting/BackGround/Wave", 0, 1);
	m_Wave->Init(0.5f, 1);
	m_Wave->SetPosition(1920 / 2, 830);


	m_Main = Sprite::Create(L"Painting/BackGround/Main1.png");
	m_Main->SetPosition(1920 / 2, 1080 / 2);


	m_Start = Sprite::Create(L"Painting/Button/Start.png");
	m_Start->SetPosition(2000, 300);

	m_Option = Sprite::Create(L"Painting/Button/Option.png");
	m_Option->SetPosition(2000, 500);

	m_Ranking = Sprite::Create(L"Painting/Button/Ranking.png");
	m_Ranking->SetPosition(2000, 700);
}

void SceneMain::Update(float deltatime, float time)
{
	m_StageOneBackGround->m_Position.x -= 0.05f;
	m_Wave->Update(deltatime, time);



	if (m_Start->m_Position.x > 1500)
	{
		m_Start->m_Position.x -= 10;
	}
	if (m_Option->m_Position.x > 1500)
	{
		m_Option->m_Position.x -= 8;
	}
	if(m_Ranking->m_Position.x > 1500)
		m_Ranking->m_Position.x -= 6;
	

	if (CollisionMgr::GetInst()->CollideBox(m_Start) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Intro());

		INPUT->ButtonDown(false);
	}
	else if (CollisionMgr::GetInst()->CollideBox(m_Option) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Intro());

		INPUT->ButtonDown(false);
	}
	else if (CollisionMgr::GetInst()->CollideBox(m_Ranking) && INPUT->GetButtonDown() == true)
	{
		SceneDirector::GetInst()->ChangeScene(new Intro());

		INPUT->ButtonDown(false);
	}
}

void SceneMain::Render()
{
	m_StageOneBackGround->Render();
	m_Wave->Render();

	m_Main->Render();

	m_Start->Render();
	m_Option->Render();
	m_Ranking->Render();

}
