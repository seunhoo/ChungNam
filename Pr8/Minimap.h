#pragma once
class Minimap : public Object
{
public:

	Sprite* m_MiniMap;
	Sprite* m_SmallPlayer;

	Minimap();

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj);
};

