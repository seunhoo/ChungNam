#pragma once
enum class KeyState
{
	PRESS,
	UP,
	DOWN,
	NONE
};
#define INPUT Input::GetInst()
class Input : public Singleton<Input>
{
private:

	int m_CurrentState[256];
	int m_PrevState[256];
	bool m_bCurrentState;
	bool m_bPrevState;
	bool m_ButtonDown;
	Vec2 m_MousePos;

public:

	Input();

	void Update();
	KeyState GetKey(int key);
	Vec2 GetMousePos() { return m_MousePos; }
	bool GetButtonDown() { return m_ButtonDown; }
	void ButtonDown(bool down) { m_ButtonDown = down; }

	void KeyBoardUpdate();
	void MouseUpdate();
};

