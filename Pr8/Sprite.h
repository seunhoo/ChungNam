#pragma once
class Sprite : public Object
{
private:
	LPD3DXSPRITE m_pSp;
	RECT m_Rect;
	Texture* m_Texture;

public:
	int A, R, G, B;

	Sprite();

	bool Init(std::wstring fileName);
	static Sprite* Create(std::wstring fileName);
	void Render();

};

