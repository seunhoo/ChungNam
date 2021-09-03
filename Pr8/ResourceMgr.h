#pragma once
class ResourceMgr : public Singleton<ResourceMgr>
{
public:
	std::map<std::wstring, Texture*>m_TextureMap;
public:
	Texture* CreateTextureFromFile(std::wstring fileName);
};

