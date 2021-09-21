#include "stdafx.h"
#include "ScoreMgr.h"

void ScoreMgr::SetScore()
{
	m_Score = 0;
}

void ScoreMgr::AddScore(int score)
{
	m_Score += score;
}
