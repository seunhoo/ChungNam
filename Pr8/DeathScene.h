#pragma once
class DeathScene : public Scene
{
public:
	Sprite* m_Bg;

	TextMgr* m_Ini;

	DeathScene();

	string m_Name;

	void Init();
	void Release();
	void Update(float deltatime, float time);
	void Render();
};

