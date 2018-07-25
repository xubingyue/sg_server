#pragma once

// ս���佫��ID��ʼ��
static const uint64_t CAMP_SELF_UNIQUE_OFFSET = 10000;
static const uint64_t CAMP_ENEMY_UNIQUE_OFFSET = 20000;
static const uint64_t CAMP_SELF_HELP_UNIQUE_OFFSET = 30000;
static const uint64_t CAMP_ENEMY_HELP_UNIQUE_OFFSET = 40000;


// ŭ����������
#define SP_SKILL_NUM 2

// ս����������
#define battle_max_grid 9
// ս���д����ľ���Ӱ���ʱ��
#define battle_story_addi_time 60000

// ����Ŀ������
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

// ���ܹ���Ŀ������
enum skill_attack_target_type
{
	skill_attack_target_type_default = 0, // Ĭ�Ϲ���
	skill_attack_target_type_vertical = 1, // �����е�����Ŀ��
	skill_attack_target_type_horizon = 2, // �����ŵ�����Ŀ��
	skill_attack_target_type_random = 3, // ���Ŀ��
	skill_attack_target_type_all = 4, // ����Ŀ��
	skill_attack_target_type_select = 5, // �ֶ�����Ŀ��
	skill_attack_target_type_some_min_hp = 6, // Ѫ�����ٵļ���
	skill_attack_target_type_min_hp = 7, // Ѫ�����ٵ�һ��(�������)
	skill_attack_target_type_spurting = 8,	// ���乥��
	skill_attack_target_type_self = 9,		// �Լ�
};

// ������������
enum skill_consum_type
{
	skill_consum_type_hp = 1,
	skill_consum_type_sp = 2,
};

// ս����ʽ
enum combat_type
{
	combat_type_single_role = 1,		// ����ս��
	combat_type_troop = 2,				// ���ս��
};

// �¼��׶�
enum combat_event_step_type
{
	combat_event_step_type_round_start = 1,		// �غϿ�ʼ
	combat_event_step_type_round_end = 2,		// �غϽ���
	combat_event_step_type_combat_start = 3,	// ս����ʼ
	combat_evnet_step_type_play_end = 4,		// ���Ž���
};


// �¼�ƫ��
const int MAGIC_TEAM_EVENT = 100;
const int MAGIC_ENEMY_EVENT = 200;

//ս���¼�
enum FIGHT_EVENT
{
	//��ս���¼�
	event_on_none = 0,
	//ս����ʼ
	event_on_fight_begin = 1,
	//�غϿ�ʼ
	event_on_round_begin = 2,
	//�غϽ���
	event_on_round_end = 3,


	//��������
	event_on_critical_strike = 101,
	//�ܵ�����
	event_on_becritical_strike,
	//����˺�ǰ
	event_on_attack_begin,
	//����˺���
	event_on_attack_end,
	//���һ���˺�ǰ
	event_on_attack_phase_begin,
	//���һ���˺���
	event_on_attack_phase_end,
	//�յ��˺�
	event_on_behurt,
	//��ɻ�ɱ
	event_on_killer,
	//����ʱ
	event_on_death,
	//����ʱ
	event_on_relive,
	//����BUFFERʱ
	event_on_add_buff,
	//ɾ��BUFFERʱ
	event_on_remove_buff,
	//����Ŀ��ʱ
	event_on_hit_target,
	//�ܵ��˺�ǰ
	event_on_behurt_begin,
	//�ܵ��˺���
	event_on_behurt_end,
	//�ܵ�һ���˺�ǰ
	event_on_behurt_phase_begin,
	//�ܵ�һ���˺���
	event_on_behurt_phase_end,
	//����ʱ
	event_on_add_att_speed,
	//����������ʱ
	event_on_attack_wake_up,
	//��������״̬ʱ
	event_on_athanasia,
	//�����ֿ�ʱ
	event_on_resistance,
	//����ʱ
	event_on_heal,
	//�յ��˺�δ��Ѫ
	event_on_behurt_without_sub_hp,
	//ʹ��ŭ������ʱ
	event_on_use_sp_skill,


	//��������(����)
	event_on_team_critical_strike = 201,
	//�ܵ�����(����)
	event_on_team_becritical_strike,
	//����˺�ǰ(����)
	event_on_team_attack_begin,
	//����˺���(����)
	event_on_team_attack_end,
	//���һ���˺�ǰ(����)
	event_on_team_attack_phase_begin,
	//���һ���˺���(����)
	event_on_team_attack_phase_end,
	//�յ��˺�(����)
	event_on_team_behurt,
	//��ɻ�ɱ(����)
	event_on_team_killer,
	//����ʱ(����)
	event_on_team_death,
	//����ʱ(����)
	event_on_team_relive,
	//����BUFFERʱ(����)
	event_on_team_add_buff,
	//ɾ��BUFFERʱ(����)
	event_on_team_remove_buff,
	//����Ŀ��ʱ(����)
	event_on_team_hit_target,
	//�ܵ��˺�ǰ(����)
	event_on_team_behurt_begin,
	//�ܵ��˺���(����)
	event_on_team_behurt_end,
	//�ܵ�һ���˺�ǰ(����)
	event_on_team_behurt_phase_begin,
	//�ܵ�һ���˺���(����)
	event_on_team_behurt_phase_end,
	//����ʱ(����)
	event_on_team_add_att_speed,
	//����������ʱ(����)
	event_on_team_attack_wake_up,
	//��������״̬ʱ(����)
	event_on_team_athanasia,
	//�����ֿ�ʱ(����)
	event_on_team_resistance,
	//����ʱ(����)
	event_on_team_heal,
	//�յ��˺�δ��Ѫ(����)
	event_on_team_behurt_without_sub_hp,
	//ʹ��ŭ������ʱ(����)
	event_on_team_use_sp_skill,


	//��������(����)
	event_on_enemy_critical_strike = 301,
	//�ܵ�����(����)
	event_on_enemy_becritical_strike,
	//����˺�ǰ(����)
	event_on_enemy_attack_begin,
	//����˺���(����)
	event_on_enemy_attack_end,
	//���һ���˺�ǰ(����)
	event_on_enemy_attack_phase_begin,
	//���һ���˺���(����)
	event_on_enemy_attack_phase_end,
	//�յ��˺�(����)
	event_on_enemy_behurt,
	//��ɻ�ɱ(����)
	event_on_enemy_killer,
	//����ʱ(����)
	event_on_enemy_death,
	//����ʱ(����)
	event_on_enemy_relive,
	//����BUFFERʱ(����)
	event_on_enemy_add_buff,
	//ɾ��BUFFERʱ(����)
	event_on_enemy_remove_buff,
	//����Ŀ��ʱ(����)
	event_on_enemy_hit_target,
	//�ܵ��˺�ǰ(����)
	event_on_enemy_behurt_begin,
	//�ܵ��˺���(����)
	event_on_enemy_behurt_end,
	//�ܵ�һ���˺�ǰ(����)
	event_on_enemy_behurt_phase_begin,
	//�ܵ�һ���˺���(����)
	event_on_enemy_behurt_phase_end,
	//����ʱ(����)
	event_on_enemy_add_att_speed,
	//����������ʱ(����)
	event_on_enemy_attack_wake_up,
	//��������״̬ʱ(����)
	event_on_enemy_athanasia,
	//�����ֿ�ʱ(����)
	event_on_enemy_resistance,
	//����ʱ(����)
	event_on_enemy_heal,
	//�յ��˺�δ��Ѫ(����)
	event_on_enemy_behurt_without_sub_hp,
	//ʹ��ŭ������ʱ(����)
	event_on_enemy_use_sp_skill,
};

// ����AI
enum skill_release_ai
{
	skill_release_ai_none = 0,		// ��(Ĭ���˺�)
	skill_release_ai_heal = 1,		// ��Ѫ
};

// ��������buff��Ŀ������
enum skill_buff_target_type
{
	skill_buff_target_type_target = 1,	// ָ��Ŀ��
	skill_buff_target_type_self = 2,	// �Լ�
	skill_buff_target_type_friend = 3,	// �ѷ�
	skill_buff_target_type_enemy = 4,	// �з�
	skill_buff_target_type_friend_rand = 5,	// �ѷ����
	skill_buff_target_type_enemy_rand = 6,	// �з����
	skill_buff_target_type_friend_min_hp = 7,	// �ѷ�Ѫ������
	skill_buff_target_type_enemy_min_hp = 8,	// �з�Ѫ������
	skill_buff_target_type_attack_me = 9,	// �����ҵ�Ŀ��
};

// ���ܴ����¼���ѡ��Ŀ������
enum skill_event_target_type
{
	skill_event_target_type_all = 0,				// ȫ��
	skill_event_target_type_target = 1,				// ָ��Ŀ��
	skill_event_target_type_except_target = 2,		// ��Ŀ���������Ŀ�괦��
};

// �佫��ʾ��������
enum show_cond_type
{
	show_cond_type_round_start = 1,		// �غϿ�ʼ
	show_cond_type_hero_die = 2,		// ָ���佫����
	show_cond_type_hero_hp = 3,			// ָ���佫Ѫ��С��һ����ֵ
	show_cond_type_round_end = 4,		// �غϽ���
	show_cond_type_combat_start = 5,	// ս����ʼ
	show_cond_type_play_end = 6,		// ���Ž���
};

// buff���ӹ�ϵ
enum buff_add_type
{
	buff_add_type_add_layer = 1,		// ����
	buff_add_type_replace = 2,			// �滻
	buff_add_type_add = 3,				// ����
};

// buff��ʽ����
enum buff_formula_type
{
	buff_formula_type_debuff = 0,		// debuff
	buff_formula_type_normal = 1,		// ����buff
};

// buffЧ������
enum buff_effect_type
{
	buff_effect_type_normal = 0,		// ��ͨ
	buff_effect_type_gain = 1,			// ����
	buff_effect_type_debuff = 2,		// ����
};

// buff�׶�
enum buff_step
{
	buff_step_load = 1,
	buff_step_unload = 2,
	buff_step_layer_change = 3,
	buff_step_trigger = 4,
	buff_step_detonate = 5,
};

// buff��������
enum overlay_type
{
	overlay_type_none = 0,
	overlay_type_layer = 1,
	overlay_type_replace = 2,
	overlay_type_count = 3,
};

// buff֪ͨ����
enum buff_notify_type
{
	// û�з����κ�Ч��
	buff_notify_none		= 0,
	// �����Ըı�
	buff_notify_attr_change = 1,
	// ��Ч
	buff_notify_valid		= 2,	
};

// buff�Ƴ�����
enum buff_remove_type
{
	buff_remove_type_normal = 0,				// �����Ƴ�
	buff_remove_type_cur_round = 1,				// ��ǰ�غ��Ƴ�
	buff_remove_type_dead_not_remove = 2,		// �������Ƴ�
};

// ���Կ��ƹ�ϵ
enum terry_relation_type
{
	terry_relation_type_none = 0,
	terry_relation_type_restraint,
	terry_relation_type_be_restraint,
};