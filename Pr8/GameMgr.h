#pragma once
enum class Stage
{
	STAGEONE,
	STAGETWO
};
enum class BossStage
{
	BOSS,
	NONE
};

#define GM GameMgr::GetInst()

class GameMgr : public Singleton<GameMgr>
{
public:

	BossStage m_BossStage;
	Stage m_Stage;

	void SetStage(int stage);
	void SetBossStage(int stage);
	Stage GetStage() { return m_Stage; }
	BossStage GetBossStage() { return m_BossStage; }

};

