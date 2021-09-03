#pragma once
class SceneDirector : public Singleton<SceneDirector>
{
private:
	Scene* m_CurrentScene;

public:

	void ChangeScene(Scene* scene);
	void Update(float deltatime, float time);
	void Render();
};

