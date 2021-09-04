#include "stdafx.h"
#include "Intro.h"
#include"StageOne.h"
void Intro::Release()
{
}

void Intro::Init()
{
	m_Intro = Sprite::Create(L"Painting/BackGround/Intro1.png");
	m_Intro->SetPosition(1920 / 2, 1080 / 2);

	m_Change = true;

}

void Intro::Update(float deltatime, float time)
{

      

	m_Intro->A--;
	if (m_Intro->A < 10 && m_Change == true)
	{
		m_Intro = Sprite::Create(L"Painting/BackGround/Intro2.png");
		m_Intro->SetPosition(1920 / 2, 1080 / 2);
		m_Intro->A = 255;
		m_Change = false;
	}
	else if(m_Intro->A < 10 && m_Change == false)
	{
		m_Intro = Sprite::Create(L"Painting/BackGround/Intro1.png");
		m_Intro->SetPosition(1920 / 2, 1080 / 2);
		m_Intro->A = 255;
		m_Change = true;
	}

	if (INPUT->GetKey(VK_SPACE) == KeyState::DOWN)
	{
		SceneDirector::GetInst()->ChangeScene(new StageOne());
	}
}

void Intro::Render()
{
	m_Intro->Render();
}
