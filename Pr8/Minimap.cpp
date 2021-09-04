#include "stdafx.h"
#include "Minimap.h"

Minimap::Minimap()
{
	m_MiniMap = Sprite::Create(L"Painting/BackGround/Minimap.png");
	m_MiniMap->SetParent(this);
	SetPosition(1750,30);

	m_SmallPlayer = Sprite::Create(L"Painting/BackGround/SmallPlayer.png");
	m_SmallPlayer->SetPosition(1610, 30);

}

void Minimap::Update(float deltatime, float time)
{
	m_SmallPlayer->m_Position.x += 0.009f;
}

void Minimap::Render()
{
	m_MiniMap->Render();
	m_SmallPlayer->Render();
}

void Minimap::OnCollision(Object* obj)
{
}
