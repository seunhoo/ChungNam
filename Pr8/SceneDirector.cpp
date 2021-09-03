#include "stdafx.h"
#include "SceneDirector.h"

void SceneDirector::ChangeScene(Scene* scene)
{
	if (m_CurrentScene)
	{
		m_CurrentScene->Release();
		SafeDelete(m_CurrentScene);
	}
	m_CurrentScene = scene;
	m_CurrentScene->Init();
}

void SceneDirector::Update(float deltatime, float time)
{
	INPUT->Update();
	ObjMgr->Update(deltatime, time);
	if (m_CurrentScene)
	{
		m_CurrentScene->Update(deltatime, time);
	}
}

void SceneDirector::Render()
{
	ObjMgr->Render();

	if (m_CurrentScene)
		m_CurrentScene->Render();
}
