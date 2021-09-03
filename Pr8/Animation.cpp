#include "stdafx.h"
#include "Animation.h"

void Animation::AddCountinueFrmae(std::wstring fileName, int firstframe, int lastframe)
{
	if (firstframe < lastframe)
	{
		for (int i = firstframe; i < lastframe; i++)
		{
			auto sprite = Sprite::Create(fileName.c_str() + std::to_wstring(i) + L".png");
			sprite->SetParent(this);

			if (sprite)
				m_Anim.push_back(sprite);
		}
	}
}

void Animation::Init(bool play, float delay)
{
	m_Autoplay = play;
	m_Delay = delay;
}

void Animation::Update(float deltatime, float time)
{
	m_FrameCount += dt;
	if (m_Destroy == true)
	{
		m_Anim.at(m_CurrentFrame)->SetDestroy(true);
	}

	if (m_Autoplay == true)
	{
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0;
		}
	}
	if (m_CurrentFrame > m_Anim.size() - 1)
	{
		m_CurrentFrame = 0;
	}
	m_Anim.at(m_CurrentFrame)->A = A;
	m_Anim.at(m_CurrentFrame)->R = R;
	m_Anim.at(m_CurrentFrame)->G = G;
	m_Anim.at(m_CurrentFrame)->B = B;
	m_Anim.at(m_CurrentFrame)->Update(deltatime, time);
}

void Animation::Render()
{
	if (m_Parent)
	{

		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2, m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);
		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2, m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);
	}
	m_Anim.at(m_CurrentFrame)->Render();
}
