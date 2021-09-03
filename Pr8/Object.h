#pragma once
class Object
{
public:
	std::string m_Tag;
	RECT m_Collision;
	Matrix m_wMat;
	Object* m_Parent;
	Vec2 m_Position, m_Scale, m_Size;
	float m_Rotation;
	bool m_Visible, m_Destroy;
	int m_Layer;


public:

	Object();

	Matrix GetMatrix();

	virtual void Update(float deltatime, float time);
	virtual void Render();
	virtual void OnCollision(Object* obj);



	void SetParent(Object* parent) { m_Parent = parent; }
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	bool GetDestroy() { return m_Destroy; }
	void SetPosition(Vec2 pos) { m_Position = pos; }
	void SetTag(std::string tag) { m_Tag = tag; }

};

