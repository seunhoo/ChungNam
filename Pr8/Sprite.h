#pragma once
class Sprite : public Object
{
private:
	LPD3DXSPRITE m_pSp;
	Texture* m_Texture;

public:
	int A, R, G, B;

	RECT m_Rect;
	Sprite();

	bool Init(std::wstring fileName);
	static Sprite* Create(std::wstring fileName);
	void Render();

};

