#include "stdafx.h"
#include "ResourceMgr.h"

Texture* ResourceMgr::CreateTextureFromFile(std::wstring fileName)
{
	if (!(m_TextureMap.count(fileName)))
	{
		auto texture = new (std::nothrow)Texture();
		if (texture && texture->Init(fileName))
		{
			m_TextureMap[fileName] = texture;
		}
		else
		{
			SafeDelete(texture);
			return false;
		}
	}
	return m_TextureMap[fileName];
}
