#include "stdafx.h"
#include "GameMgr.h"

void GameMgr::SetStage(int stage)
{
	if (stage == 1)
	{
		m_Stage = Stage::STAGEONE;
	}
	else
	{
		m_Stage = Stage::STAGETWO;
	}
}

void GameMgr::SetBossStage(int stage)
{
	if (stage == 1)
	{
		m_BossStage = BossStage::BOSS;
	}
	else
	{
		m_BossStage = BossStage::NONE;
	}
}
