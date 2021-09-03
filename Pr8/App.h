#pragma once
#define dt App::GetInst()->DeltaTime
class App : public Singleton<App>
{
private:
	int m_Width;
	int m_Height;
	bool m_WindowMode;
	HWND m_Hwnd;

public:

	float DeltaTime, Time;

	bool Init(int width, int height, bool windowMode);
	void Run();
	void Relase();

	HWND GetHWnd() { return m_Hwnd; }

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	bool _CreateWindow();
	bool _CreateRender();

};

