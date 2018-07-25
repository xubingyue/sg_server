#pragma once
#include "common/DataManager.h"
#include "common/Entry.h"
#include "common/macros.hpp"

/// @brief    表格结构:FamilyWarRankBase
/// @remark   记录大小:16 X32
///           记录大小:20 X64
///           字段数量:4
///           数据文件:j家族战.xlsx 家族战战功排名奖励
///           排序主键:id
#pragma pack(1)
struct FamilyWarRankBase
{
#ifdef _PLATFORM_X64
	static const int          FormatCheckCode = 0x00510DE6; ///< I|IIV
#else
	static const int          FormatCheckCode = 0x00510E06; ///< I|IIv
#endif

	//------------------------
	uint32_t getUniqueID() const { return id; }; // TODO: 请用 id 生成唯一键

	uint32_t                  id;                           ///< id

	uint32_t                  level;                        ///< 战功等级
	uint32_t                  rank;                         ///< 战功排名
	const char*               reward;                       ///< 奖励
};
#pragma pack()

struct FamilyWarRank : public Entry
{
	uint32_t                  id()                          { return t_id; }

	uint32_t                  level()                       { return t_level; }
	uint32_t                  rank()                        { return t_rank; }
	const std::map<uint32_t, uint32_t>& reward()			{ return t_reward; }

private:
	uint32_t                  t_id;                         ///< id

	uint32_t                  t_level;                      ///< 战功等级
	uint32_t                  t_rank;                       ///< 战功排名
	std::map<uint32_t, uint32_t> t_reward;					///< 奖励

public:
	void reset();
	void fill( const FamilyWarRankBase& base );
	const char* getClassName() const { return "j家族战"; }

	static const std::string getBinaryName();
};

typedef DataTableManager< FamilyWarRank, FamilyWarRankBase > FamilyWarRankManager;

inline void FamilyWarRank::reset()
{
	this->t_id = 0;
	this->t_level = 0;
	this->t_rank = 0;
	this->t_reward.clear();
};

inline void FamilyWarRank::fill( const FamilyWarRankBase& base )
{
	this->reset();
	this->m_id = base.getUniqueID();

	this->t_id = base.id;
	this->t_level = base.level;
	this->t_rank = base.rank;
	
	if (base.reward != NULL) {
		common::Misc::Parse2SeperatorDataInfo(std::string(base.reward), this->t_reward, "$");
	}
};

inline const std::string FamilyWarRank::getBinaryName()
{
#ifdef _PLATFORM_X64
	return "FamilyWarRank.tbls64";
#else
	return "FamilyWarRank.tbls32";
#endif
};
