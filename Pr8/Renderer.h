#pragma once
class Renderer : public Singleton<Renderer>
{
private:
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pDevice;
	LPD3DXSPRITE m_pSprite;

public:

	bool Init(int widht, int height, bool windowMode);
	void Release();
	LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
	LPD3DXSPRITE GetSprite() { return m_pSprite; }

	void Begin();
	void End();

};

