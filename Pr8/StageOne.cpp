#include "stdafx.h"
#include "StageOne.h"

void StageOne::Release()
{
}

void StageOne::Init()
{
	m_StageOneBackGround = Sprite::Create(L"Painting/BackGround/StageOne.png");
	m_StageOneBackGround->SetPosition(1920 / 2, 1080 / 2);
}

void StageOne::Update(float deltatime, float time)
{
}

void StageOne::Render()
{
	m_StageOneBackGround->Render();
}
