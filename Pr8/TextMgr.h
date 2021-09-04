#pragma once
class TextMgr
{
private:
	D3DXCOLOR m_Color;
	LPD3DXFONT m_pFont;
	RECT m_FontRect;
	Matrix m_wMat;

public:
	TextMgr();

	float m_Angle;

	bool Init(int height, const std::string& fontname);
	int print(const std::string& str, int x, int y);

	void SetColor(int a, int r, int g, int b);

	void Release();
};

