#include "stdafx.h"
#include "Boss.h"

Boss::Boss(int type)
{
	m_Type = type;
	if (type == 1)
	{
		m_BossHead = Sprite::Create(L"Painting/Boss/BossHead.png");
		m_BossHead->SetParent(this);


		SetPosition(2300, 1080 / 2);
	}
	else if (type == 2)
	{
		m_BossHand = Sprite::Create(L"Painting/Boss/BossHand.png");
		m_BossHand->SetParent(this);


		m_Rotation = D3DXToRadian(-30);

		SetPosition(2300, 300);
	}
	else if (type == 3)
	{
		m_BossArm = Sprite::Create(L"Painting/Boss/BossArm.png");
		m_BossArm->SetParent(this);

		SetPosition(2300, 250);
	}
	else if (type == 4)
	{
		m_BossArmor = Sprite::Create(L"Painting/Boss/BossArmor.png");
		m_BossArmor->SetParent(this);

		m_Rotation += D3DXToRadian(30);

		SetPosition(2300, 300);
	}
	else if (type == 5)
	{
		m_BossHand1 = Sprite::Create(L"Painting/Boss/BossHand.png");
		m_BossHand1->SetParent(this);
		 
		m_Rotation = D3DXToRadian(20);

		SetPosition(2300, 920);
	}
	else if (type == 6)
	{
		m_BossArm1 = Sprite::Create(L"Painting/Boss/BossArm.png");
		m_BossArm1->SetParent(this);

		SetPosition(2300, 920);
	}
	else if (type == 7)
	{
		m_BossArmor1 = Sprite::Create(L"Painting/Boss/BossArmor.png");
		m_BossArmor1->SetParent(this);

		m_Rotation = D3DXToRadian(-30);

		SetPosition(2300, 820);
	}
	
}

void Boss::Update(float deltatime, float time)
{
	m_SpawnTime += dt;
	m_RotateTime += dt;
	if (m_SpawnCheck == false)
	{
		if (m_Type == 1 && m_Position.x >= 1800)
		{
			m_Position.x -= 2;
		}
		else if ((m_Type == 5 || m_Type == 2) && m_Position.x >= 1250)
		{
			m_Position.x -= 10;
		}
		else if ((m_Type == 6 || m_Type == 3) && m_Position.x >= 1500)
		{
			m_Position.x -= 6;
		}
		else if ((m_Type == 7 || m_Type == 4) && m_Position.x >= 1720)
		{
			m_Position.x -= 3;
		}
	}

	if ((m_Type == 2) && m_RotateTime <= 0.3f)
	{
		m_Position.y += 1;
	}
	if ((m_Type == 2) && m_RotateTime >= 0.4f)
	{
		m_Position.y -= 1;
	}

	if (m_RotateTime >= 0.7f)
	{
		m_RotateTime = 0;
	}


	


}

void Boss::Render()
{
	if (m_Type == 1)
	{
		m_BossHead->Render();
	}
	else if (m_Type == 2)
	{
		m_BossHand->Render();
	}
	else if (m_Type == 3)
	{
		m_BossArm->Render();
	}
	else if (m_Type == 4)
	{
		m_BossArmor->Render();
	}
	else if (m_Type == 5)
	{
		m_BossHand1->Render();
	}
	else if (m_Type == 6)
	{
		m_BossArm1->Render();
	}
	else if (m_Type == 7)
	{
		m_BossArmor1->Render();
	}

}

void Boss::OnCollision(Object* obj)
{
}
