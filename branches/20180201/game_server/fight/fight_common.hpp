#pragma once

// 战斗武将的ID起始段
static const uint64_t CAMP_SELF_UNIQUE_OFFSET = 10000;
static const uint64_t CAMP_ENEMY_UNIQUE_OFFSET = 20000;
static const uint64_t CAMP_SELF_HELP_UNIQUE_OFFSET = 30000;
static const uint64_t CAMP_ENEMY_HELP_UNIQUE_OFFSET = 40000;


// 怒气技能数量
#define SP_SKILL_NUM 2

// 战斗最大格子数
#define battle_max_grid 9
// 战斗中触发的剧情影响的时间
#define battle_story_addi_time 60000

// 技能目标类型
enum skill_target_type
{
	skill_target_alive_friend = 0,
	skill_target_alive_enemy = 1,
	skill_target_alive_teammate = 2,
	skill_target_dead_teammate = 3,
	skill_target_dead_enemy = 4,
	skill_target_friend = 5,
	skill_target_teammate = 6,
	skill_target_enemy = 7,
	skill_target_dead_friend = 8,
};

// 技能攻击目标类型
enum skill_attack_target_type
{
	skill_attack_target_type_default = 0, // 默认规则
	skill_attack_target_type_vertical = 1, // 所在列的所有目标
	skill_attack_target_type_horizon = 2, // 所在排的所有目标
	skill_attack_target_type_random = 3, // 随机目标
	skill_attack_target_type_all = 4, // 所有目标
	skill_attack_target_type_select = 5, // 手动单个目标
	skill_attack_target_type_some_min_hp = 6, // 血量最少的几个
	skill_attack_target_type_min_hp = 7, // 血量最少的一个(可能随机)
	skill_attack_target_type_spurting = 8,	// 溅射攻击
	skill_attack_target_type_self = 9,		// 自己
};

// 技能消耗类型
enum skill_consum_type
{
	skill_consum_type_hp = 1,
	skill_consum_type_sp = 2,
};

// 战斗方式
enum combat_type
{
	combat_type_single_role = 1,		// 单人战斗
	combat_type_troop = 2,				// 组队战斗
};

// 事件阶段
enum combat_event_step_type
{
	combat_event_step_type_round_start = 1,		// 回合开始
	combat_event_step_type_round_end = 2,		// 回合结束
	combat_event_step_type_combat_start = 3,	// 战斗开始
	combat_evnet_step_type_play_end = 4,		// 播放结束
};


// 事件偏移
const int MAGIC_TEAM_EVENT = 100;
const int MAGIC_ENEMY_EVENT = 200;

//战斗事件
enum FIGHT_EVENT
{
	//空战斗事件
	event_on_none = 0,
	//战斗开始
	event_on_fight_begin = 1,
	//回合开始
	event_on_round_begin = 2,
	//回合结束
	event_on_round_end = 3,


	//发生暴击
	event_on_critical_strike = 101,
	//受到暴击
	event_on_becritical_strike,
	//造成伤害前
	event_on_attack_begin,
	//造成伤害后
	event_on_attack_end,
	//造成一段伤害前
	event_on_attack_phase_begin,
	//造成一段伤害后
	event_on_attack_phase_end,
	//收到伤害
	event_on_behurt,
	//完成击杀
	event_on_killer,
	//死亡时
	event_on_death,
	//复活时
	event_on_relive,
	//添加BUFFER时
	event_on_add_buff,
	//删除BUFFER时
	event_on_remove_buff,
	//命中目标时
	event_on_hit_target,
	//受到伤害前
	event_on_behurt_begin,
	//受到伤害后
	event_on_behurt_end,
	//受到一段伤害前
	event_on_behurt_phase_begin,
	//受到一段伤害后
	event_on_behurt_phase_end,
	//拉条时
	event_on_add_att_speed,
	//被攻击吵醒时
	event_on_attack_wake_up,
	//触发不死状态时
	event_on_athanasia,
	//触发抵抗时
	event_on_resistance,
	//治疗时
	event_on_heal,
	//收到伤害未扣血
	event_on_behurt_without_sub_hp,
	//使用怒气技能时
	event_on_use_sp_skill,


	//发生暴击(队友)
	event_on_team_critical_strike = 201,
	//受到暴击(队友)
	event_on_team_becritical_strike,
	//造成伤害前(队友)
	event_on_team_attack_begin,
	//造成伤害后(队友)
	event_on_team_attack_end,
	//造成一段伤害前(队友)
	event_on_team_attack_phase_begin,
	//造成一段伤害后(队友)
	event_on_team_attack_phase_end,
	//收到伤害(队友)
	event_on_team_behurt,
	//完成击杀(队友)
	event_on_team_killer,
	//死亡时(队友)
	event_on_team_death,
	//复活时(队友)
	event_on_team_relive,
	//添加BUFFER时(队友)
	event_on_team_add_buff,
	//删除BUFFER时(队友)
	event_on_team_remove_buff,
	//命中目标时(队友)
	event_on_team_hit_target,
	//受到伤害前(队友)
	event_on_team_behurt_begin,
	//受到伤害后(队友)
	event_on_team_behurt_end,
	//受到一段伤害前(队友)
	event_on_team_behurt_phase_begin,
	//受到一段伤害后(队友)
	event_on_team_behurt_phase_end,
	//拉条时(队友)
	event_on_team_add_att_speed,
	//被攻击吵醒时(队友)
	event_on_team_attack_wake_up,
	//触发不死状态时(队友)
	event_on_team_athanasia,
	//触发抵抗时(队友)
	event_on_team_resistance,
	//治疗时(队友)
	event_on_team_heal,
	//收到伤害未扣血(队友)
	event_on_team_behurt_without_sub_hp,
	//使用怒气技能时(队友)
	event_on_team_use_sp_skill,


	//发生暴击(敌人)
	event_on_enemy_critical_strike = 301,
	//受到暴击(敌人)
	event_on_enemy_becritical_strike,
	//造成伤害前(敌人)
	event_on_enemy_attack_begin,
	//造成伤害后(敌人)
	event_on_enemy_attack_end,
	//造成一段伤害前(敌人)
	event_on_enemy_attack_phase_begin,
	//造成一段伤害后(敌人)
	event_on_enemy_attack_phase_end,
	//收到伤害(敌人)
	event_on_enemy_behurt,
	//完成击杀(敌人)
	event_on_enemy_killer,
	//死亡时(敌人)
	event_on_enemy_death,
	//复活时(敌人)
	event_on_enemy_relive,
	//添加BUFFER时(敌人)
	event_on_enemy_add_buff,
	//删除BUFFER时(敌人)
	event_on_enemy_remove_buff,
	//命中目标时(敌人)
	event_on_enemy_hit_target,
	//受到伤害前(敌人)
	event_on_enemy_behurt_begin,
	//受到伤害后(敌人)
	event_on_enemy_behurt_end,
	//受到一段伤害前(敌人)
	event_on_enemy_behurt_phase_begin,
	//受到一段伤害后(敌人)
	event_on_enemy_behurt_phase_end,
	//拉条时(敌人)
	event_on_enemy_add_att_speed,
	//被攻击吵醒时(敌人)
	event_on_enemy_attack_wake_up,
	//触发不死状态时(敌人)
	event_on_enemy_athanasia,
	//触发抵抗时(敌人)
	event_on_enemy_resistance,
	//治疗时(敌人)
	event_on_enemy_heal,
	//收到伤害未扣血(敌人)
	event_on_enemy_behurt_without_sub_hp,
	//使用怒气技能时(队友)
	event_on_enemy_use_sp_skill,
};

// 技能AI
enum skill_release_ai
{
	skill_release_ai_none = 0,		// 无(默认伤害)
	skill_release_ai_heal = 1,		// 加血
};

// 技能添加buff的目标类型
enum skill_buff_target_type
{
	skill_buff_target_type_target = 1,	// 指定目标
	skill_buff_target_type_self = 2,	// 自己
	skill_buff_target_type_friend = 3,	// 友方
	skill_buff_target_type_enemy = 4,	// 敌方
	skill_buff_target_type_friend_rand = 5,	// 友方随机
	skill_buff_target_type_enemy_rand = 6,	// 敌方随机
	skill_buff_target_type_friend_min_hp = 7,	// 友方血量最少
	skill_buff_target_type_enemy_min_hp = 8,	// 敌方血量最少
	skill_buff_target_type_attack_me = 9,	// 攻击我的目标
};

// 技能触发事件的选择目标类型
enum skill_event_target_type
{
	skill_event_target_type_all = 0,				// 全部
	skill_event_target_type_target = 1,				// 指定目标
	skill_event_target_type_except_target = 2,		// 除目标外的所有目标处理
};

// 武将显示条件类型
enum show_cond_type
{
	show_cond_type_round_start = 1,		// 回合开始
	show_cond_type_hero_die = 2,		// 指定武将死亡
	show_cond_type_hero_hp = 3,			// 指定武将血量小于一定数值
	show_cond_type_round_end = 4,		// 回合结束
	show_cond_type_combat_start = 5,	// 战斗开始
	show_cond_type_play_end = 6,		// 播放结束
};

// buff添加关系
enum buff_add_type
{
	buff_add_type_add_layer = 1,		// 叠加
	buff_add_type_replace = 2,			// 替换
	buff_add_type_add = 3,				// 共存
};

// buff公式类型
enum buff_formula_type
{
	buff_formula_type_debuff = 0,		// debuff
	buff_formula_type_normal = 1,		// 正常buff
};

// buff效果类型
enum buff_effect_type
{
	buff_effect_type_normal = 0,		// 普通
	buff_effect_type_gain = 1,			// 增益
	buff_effect_type_debuff = 2,		// 减益
};

// buff阶段
enum buff_step
{
	buff_step_load = 1,
	buff_step_unload = 2,
	buff_step_layer_change = 3,
	buff_step_trigger = 4,
	buff_step_detonate = 5,
};

// buff覆盖类型
enum overlay_type
{
	overlay_type_none = 0,
	overlay_type_layer = 1,
	overlay_type_replace = 2,
	overlay_type_count = 3,
};

// buff通知类型
enum buff_notify_type
{
	// 没有发生任何效果
	buff_notify_none		= 0,
	// 有属性改变
	buff_notify_attr_change = 1,
	// 生效
	buff_notify_valid		= 2,	
};

// buff移除类型
enum buff_remove_type
{
	buff_remove_type_normal = 0,				// 正常移除
	buff_remove_type_cur_round = 1,				// 当前回合移除
	buff_remove_type_dead_not_remove = 2,		// 死亡不移除
};

// 属性克制关系
enum terry_relation_type
{
	terry_relation_type_none = 0,
	terry_relation_type_restraint,
	terry_relation_type_be_restraint,
};