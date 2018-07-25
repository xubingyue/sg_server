#ifndef __COMMON_MAIL_CODE__
#define __COMMON_MAIL_CODE__
#include "macros.hpp"
NS_COMMON_BEGIN
namespace mailcode_enum
{
    enum mail_code : uint32_t
    {
        sys_mail_1 = 1, // 系统发送1 
        sys_mail_2 = 2, // 系统发送2 
        sys_mail_3 = 3, // 系统发送3 
        sys_mail_4 = 4, // 系统发送4 
        sys_mail_5 = 5, // 系统发送5 
        sys_mail_6 = 6, // 系统发送6 
        sys_mail_7 = 7, // 系统发送7 
        sys_mail_collect = 8, // 获得物品 
        sys_mail_family = 9, // 加入家族 
        sys_mail_country = 10, // 加入国家 
        sys_mail_hero = 11, // 武将信物 
        sys_mail_8 = 12, // 精力测试邮件 
        sys_mail_cdkey = 100, // 礼包兑换系统 
        sys_mail_date_war = 1200, // 约战奖励邮件 
        sys_mail_arena_daily_1 = 2001, // 天梯每周段位奖励 
        sys_mail_arena_daily_2 = 2002, // 天梯每周段位奖励 
        sys_mail_arena_daily_3 = 2003, // 天梯每周段位奖励 
        sys_mail_arena_daily_4 = 2004, // 天梯每周段位奖励 
        sys_mail_arena_daily_5 = 2005, // 天梯每周段位奖励 
        sys_mail_arena_daily_6 = 2006, // 天梯每周段位奖励 
        sys_mail_arena_season_1 = 2020, // 学徒 
        sys_mail_arena_season_2 = 2021, // 新星 
        sys_mail_arena_season_3 = 2022, // 精英 
        sys_mail_arena_season_4 = 2023, // 专家 
        sys_mail_arena_season_5 = 2024, // 大师 
        sys_mail_arena_season_6 = 2025, // 王者 
        sys_mail_arena_season_7 = 2026, // 传说 
        sys_mail_arena_season_8 = 2027, // 神话 
        sys_mail_arena_season_9 = 2028, // 神话前20 
        sys_mail_arena_season_10 = 2029, // 神话第3 
        sys_mail_arena_season_11 = 2030, // 神话第2 
        sys_mail_arena_season_12 = 2031, // 神话第1 
        sys_mail_ranking = 2100, // 个人冲榜 
        sys_mail_boss_1 = 3001, // 魔王入侵伤害奖励 
        sys_mail_boss_2 = 3002, // 魔王入侵伤害奖励 
        sys_mail_boss_3 = 3003, // 魔王入侵伤害奖励 
        sys_mail_boss_4 = 3004, // 魔王入侵伤害奖励 
        sys_mail_boss_5 = 3005, // 魔王入侵家族奖励 
        sys_mail_boss_6 = 3006, // 魔王入侵家族奖励 
        sys_mail_boss_7 = 3007, // 魔王入侵家族奖励 
        sys_mail_boss_8 = 3008, // 魔王入侵家族奖励 
        sys_mail_boss_9 = 3009, // 魔王入侵击杀奖励 
        sys_mail_treasure_3 = 3101, // 藏宝图放弃任务邮件 
        sys_mail_family_pray_1 = 3201, // 家族祈愿每周奖励 
        sys_mail_family_pray_2 = 3202, // 家族祈愿 
        sys_mail_family_demise_leader = 3203, // 家族 
        sys_offline_arena_daily = 3301, // 竞技场每日结算奖励 
        sys_tower_sweep = 3401, // 凌烟阁爬塔扫荡完成提示 
        sys_mail_king_victory_reward = 3501, // 立国战奖励 
        sys_mail_king_defeat_reward = 3502, // 立国战奖励 
        sys_mail_king_merit_level = 3503, // 立国战奖励 
        sys_mail_king_merit_rank = 3504, // 立国战奖励 
        sys_mail_king_signup_success = 3505, // 立国战 
        sys_mail_assist_to_main = 3506, // 立国战助战邀请 
        sys_mail_assist_to_friend = 3507, // 立国战助战邀请 
        sys_mail_main_cancel_assist = 3508, // 立国战取消助战 
        sys_mail_cancel_assist_to_main = 3509, // 立国战取消助战 
        sys_mail_cancel_assist_to_friend = 3510, // 立国战取消助战 
        sys_mail_family_war_victory_reward = 3601, // 家族战奖励 
        sys_mail_family_war_defeat_reward = 3602, // 家族战奖励 
        sys_mail_family_war_merit_level = 3603, // 家族战奖励 
        sys_mail_family_war_merit_rank = 3604, // 家族战奖励 
        sys_mail_family_war_announce = 3605, // 家族战通知 
        sys_mail_plot_1 = 1001, // 逆转命管理员 
        sys_mail_plot_2 = 1002, // 国家管理员 
        sys_mail_plot_3 = 1003, // 远征管理员 
        sys_mail_level_5 = 1010, // 等级奖励 
        sys_mail_level_10 = 1011, // 等级奖励 
        sys_mail_level_15 = 1012, // 等级奖励 
        sys_mail_level_20 = 1013, // 等级奖励 
        sys_mail_level_25 = 1014, // 等级奖励 
        sys_mail_level_30 = 1015, // 等级奖励 
        sys_mail_level_35 = 1016, // 等级奖励 
        sys_mail_level_40 = 1017, // 等级奖励 
        sys_mail_red_envelope_1 = 4001, // 家族红包 
        sys_country_alliance = 5000, // 国家同盟 
        sys_mail_draw = 6000, // 国王抽卡奖金 
        sys_mail_cash_gift_1 = 180001, // 礼包兑换 
        sys_mail_cash_gift_2 = 180002, // 礼包兑换 
        sys_mail_cash_gift_3 = 180003, // 礼包兑换 
        sys_mail_cash_gift_4 = 180004, // 下载奖励礼包 
        sys_mail_cash_gift_5 = 180005, // 兑换码 
        sys_mail_cash_gift_6 = 180006, // 礼包兑换 
        sys_mail_cash_gift_7 = 180007, // 礼包兑换 
        sys_mail_cash_gift_8 = 180008, // 礼包兑换 
        partol_mail = 200000, // 巡逻提醒 
		
    };
}
NS_COMMON_END
#endif
