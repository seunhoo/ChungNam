#include "stdafx.h"
#include "Object.h"

Object::Object()
	:m_Tag("UN")
	,m_Parent(nullptr)
	,m_Rotation(0.f)
	,m_Scale(1.f,1.f)
	
{
	D3DXMatrixIdentity(&m_wMat);
}

Matrix Object::GetMatrix()
{
	D3DXMatrixTransformation2D(&m_wMat, 0, 0, &m_Scale, 0, m_Rotation, &m_Position);
	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::Update(float deltatime, float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* obj)
{
}
