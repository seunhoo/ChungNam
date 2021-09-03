#include "stdafx.h"
#include "SoundMgr.h"

void SoundMgr::Play(const WCHAR* pFileName, bool loop)
{
	WCHAR szFullpath[256] = L"../Sound/";

	lstrcatW(szFullpath, pFileName);

	if (loop == false)
	{
		PlaySound(szFullpath, NULL, SND_ASYNC | SND_NOSTOP | SND_FILENAME);
	}
	else if (loop)
	{
		PlaySound(szFullpath, NULL, SND_ASYNC | SND_NOSTOP | SND_LOOP | SND_FILENAME);
	}
}

void SoundMgr::Stop()
{
	PlaySound(nullptr, NULL, SND_ASYNC);
}
