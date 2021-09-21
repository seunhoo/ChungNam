#include "stdafx.h"
#include "DeathScene.h"

DeathScene::DeathScene()
{
	m_Bg = Sprite::Create(L"Painting/BackGround/Ini.png");
	m_Bg->SetPosition(1920 / 2, 1080 / 2);

	m_Ini = new TextMgr();
	m_Ini->Init(80, "±Ã¼­Ã¼");
	m_Ini->SetColor(255, 255, 255, 255);
}

void DeathScene::Init()
{
}

void DeathScene::Release()
{
}

void DeathScene::Update(float deltatime, float time)
{
	if (INPUT->GetKey('A') == KeyState::UP)
	{
		m_Name += 'A';
	}
	if (INPUT->GetKey('B') == KeyState::UP)
	{
		m_Name += 'B';
	}
	if (INPUT->GetKey('C') == KeyState::UP)
	{
		m_Name += 'C';
	}
	if (INPUT->GetKey('D') == KeyState::UP)
	{
		m_Name += 'D';
	}
	if (INPUT->GetKey('E') == KeyState::UP)
	{
		m_Name += 'E';
	}
	if (INPUT->GetKey('F') == KeyState::UP)
	{
		m_Name += 'F';
	}
	if (INPUT->GetKey('G') == KeyState::UP)
	{
		m_Name += 'G';
	}
	if (INPUT->GetKey('H') == KeyState::UP)
	{
		m_Name += 'H';
	}
	if (INPUT->GetKey('I') == KeyState::UP)
	{
		m_Name += 'I';
	}
	if (INPUT->GetKey('J') == KeyState::UP)
	{
		m_Name += 'J';
	}
	if (INPUT->GetKey('K') == KeyState::UP)
	{
		m_Name += 'K';
	}
	if (INPUT->GetKey('L') == KeyState::UP)
	{
		m_Name += 'L';
	}
	if (INPUT->GetKey('M') == KeyState::UP)
	{
		m_Name += 'M';
	}
	if (INPUT->GetKey('O') == KeyState::UP)
	{
		m_Name += 'O';
	}
	if (INPUT->GetKey('P') == KeyState::UP)
	{
		m_Name += 'P';
	}
	if (INPUT->GetKey('Q') == KeyState::UP)
	{
		m_Name += 'Q';
	}
	if (INPUT->GetKey('R') == KeyState::UP)
	{
		m_Name += 'R';
	}
	if (INPUT->GetKey('S') == KeyState::UP)
	{
		m_Name += 'S';
	}
	if (INPUT->GetKey('T') == KeyState::UP)
	{
		m_Name += 'T';
	}
	if (INPUT->GetKey('U') == KeyState::UP)
	{
		m_Name += 'V';
	}
	if (INPUT->GetKey('W') == KeyState::UP)
	{
		m_Name += 'W';
	}
	if (INPUT->GetKey('X') == KeyState::UP)
	{
		m_Name += 'X';
	}
	if (INPUT->GetKey('Y') == KeyState::UP)
	{
		m_Name += 'Y';
	}
	if (INPUT->GetKey('Z') == KeyState::UP)
	{
		m_Name += 'Z';
	}

	if (m_Name.size() != 0 &&INPUT->GetKey(VK_BACK) == KeyState::PRESS)
	{
		m_Name.pop_back();
	}

	
}

void DeathScene::Render()
{
	m_Bg->Render();
	
	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Ini->print(m_Name,900,270);
	Renderer::GetInst()->GetSprite()->End();

}
