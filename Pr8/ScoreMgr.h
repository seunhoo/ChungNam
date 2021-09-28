#pragma once
class ScoreMgr : public Singleton<ScoreMgr>
{
public:


	int m_Score;

	void SetScore();
	void AddScore(int score);

};

