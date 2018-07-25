#ifndef __FIGHT_HERO_HPP__
#define __FIGHT_HERO_HPP__

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "combat.hpp"
#include "buff_manager.hpp"
#include "buff_element_manager.hpp"
#include "fight_common.hpp"
#include "skill_manager.hpp"
#include "tblh/MonsterHero.tbls.h"

class script_fight_hero_t;

struct fight_hero_round_data
{
	int damage = 0;
	int injured = 0;
};

enum {
	FIGHT_HERO_TYPE_BIG_BOSS = 3,
	FIGHT_HERO_TYPE_SML_BOSS = 4,
};


struct fight_calc_result_t
{
	fight_calc_result_t(void)
	{
		reset();
	}

	~fight_calc_result_t(void) {};

	void reset()
	{
		dodge = false;
		crit = false;
		beheaded = false;
		immuno = false;
		damage = 0;
		heal = 0;
		block = 0;
		absorb = 0;
		leech = 0;
		reflect = 0;
		add_buff_id = 0;
		remove_buff_id = 0;
		over_layer_buff_id = 0;
		phase = 0;
		act_type = 0;
		skill = 0;
		accept_damage = 0;
	}

	bool		dodge;				//
	bool		crit;				//����
	bool		beheaded;			//նɱ
	bool		immuno;
	int32_t		damage;				//����˺�
	int32_t		heal;				//�յ�����
	int32_t		block;
	int32_t		absorb;				//�����˺�
	int32_t		leech;
	int32_t		reflect;
	uint32_t	add_buff_id;		// ���ӵ�buff id
	uint32_t	remove_buff_id;		// �Ƴ���buff id
	uint32_t	over_layer_buff_id;	// ���������buff id
	uint32_t    phase;				// ����
	uint32_t	act_type;			// ��������(��ͨ��׷��������������)
	uint32_t	skill;				// ��ǰʹ�õļ���ID
	int32_t		accept_damage;		// �ܵ��˺�
};

// ͳ������
struct stat_data
{
public:
	void add_heal(uint32_t value) { heal += value; }
	void add_damage(uint32_t value) { damage += value; }
	void add_accept_damage(uint32_t value) { accept_damage += value; }

	uint32_t get_heal_count() { return heal; }
	uint32_t get_damage_count() { return damage; }
	uint32_t get_accept_damage_count() { return accept_damage; }
private:
	uint32_t heal = 0;				// ����
	uint32_t damage = 0;			// �˺�
	uint32_t accept_damage = 0;		// �����˺�
};

// ��������
struct count_data
{
public:
	void resetByRound()
	{
		counter_count = 0;						// ��������
		combo_count = 0;						// ��������
		trigger_skill_count = 0;				// �������ܴ���	
		one_round_injured = 0;					// һ���غ����ܵ��������˺�
		one_round_damage = 0;					// һ���غ�����ɵ������˺�
		other_action_count = 0;					// �����佫�ж�����
		once_injured = 0;						// �����˺�
		buff_combo = 0;							// buff ׷������(������ȷ����)
		crit_combo_phase = 0;					// ÿ�غ϶�α�������
		union_attack = 0;					    // �л�����
		phase_rate_add = 0;						// �����+�Ķ���
		round_phase_num = 0;					// �ܵĶ���
		round_do_attack_num = 0;				// �غ����ͷż��ܴ���
		athanasia_heal_hp = 0;					// ������Ѫ
		is_relive_cur_round = false;			// �Ƿ񱾻غϸ����, ���ڽ�ֹ���������󸴻��Ŀ��
		be_heal_hp = 0;							// ������
		be_hurt_hp = 0;							// �˺���
		round_sub_hp = 0;						// �غ��ڵĿ�Ѫ
		round_sub_hp_attacker_uid = 0;			// ���ε�Ѫʱ�Ĺ�����uid
	}

	void reset()
	{
		trigger_skill_by_hp = 0;				// Ѫ���������ܴ���
		trigger_skill_by_critical_blow = 0;		// ����һ���������ܴ���
		trigger_skill_by_beattack_count = 0;	// �������������ܴ���
		trigger_skill_by_attack_count = 0;		// �����������ܴ���
		beattack_count = 0;						// ����������
		attack_count = 0;						// ��������
		union_attack = 0;					    // �л�����
		relive_count = 0;						// �������
		counter_count = 0;						// ��������
		combo_count = 0;						// ��������
		is_calc_combo = false;
		trigger_skill_count = 0;				// �������ܴ���
		athanasia_count = 0;					// ��������
		add_buff_after_damage_count = 0;		// ���˺�������BUFF����
		event_trigger_count = 0;				// �¼���������
		one_round_injured = 0;					// һ���غ����ܵ��������˺�
		one_round_damage = 0;					// һ���غ�����ɵ������˺�
		round_count = 0;						// �����佫�ж�����
		other_action_count = 0;					// �����佫�ж�����
		in_control_speed = 0;
		all_team_damage = 0;					// �˺��ۼ�
		can_soul_relive = 0;					// �Ƿ�������ʱ�������״̬
		soul_relive_count = 0;					// ��긴�����
		once_injured = 0;						// �����˺�
		buff_combo = 0;							// buff ׷������(������ȷ����)
		crit_combo_phase = 0;					// ����׷��Ķ�δ���
		phase_rate_add = 0;						// 
		round_phase_num = 0;
		round_do_attack_num = 0;				// �غ����ͷż��ܴ���
		athanasia_heal_hp = 0;					// ������Ѫ
		is_relive_cur_round = false;			// �Ƿ񱾻غϸ����, ���ڽ�ֹ���������󸴻��Ŀ��
		be_attack_num = 0;						// ����������,��������110Ԫ����
		equip_miss_all_atk_count = 0;			// ����ȫ�幥������
		equip_miss_single_atk_count = 0;		// ���ܵ��幥������
		equip_miss_mutilp_atk_count = 0;		// ����Ⱥ�幥������
		be_heal_hp = 0;							// ������
		be_hurt_hp = 0;							// �˺���
		is_get_new_round = false;				// �Ƿ����»غ�
		pursue_and_attack_count = 0;			// ׷������ʩ�Ŵ���
		round_sub_hp = 0;						// �غ��ڵĿ�Ѫ 
		round_sub_hp_attacker_uid = 0;			// ���ε�Ѫʱ�Ĺ�����uid
	}
	//����Ӣ�۶�һ�ε��˺�ͳ��
	void resetByOnceRound() 
	{
		once_injured = 0;						// �����˺�
		pursue_and_attack_count = 0;			// ��ι��������ֿ�ʱһ��ֻ׷��һ��
		is_relive_cur_round = false;
		is_triggered_of_be_attack_count = false;
	}

	//һ�μ��ܹ�����������Ρ�Ⱥ����ֻ��һ�ι�������������һ�ι���������ǰ��������
	void resetByOneSkillAttack()
	{
		is_calc_combo = false;
		one_attack_damage = 0;
	}

public:
	uint32_t buff_combo = 0;						// buff ׷������(������ȷ����)
	uint32_t trigger_skill_by_hp			= 0;	// Ѫ���������ܴ���
	uint32_t trigger_skill_by_critical_blow	= 0;	// ����һ���������ܴ���
	uint32_t trigger_skill_by_beattack_count = 0;	// �������������ܴ���
	uint32_t trigger_skill_by_attack_count	= 0;	// �����������ܴ���
	uint32_t beattack_count					= 0;	// ����������
	uint32_t attack_count					= 0;	// ��������
	uint32_t relive_count					= 0;	// �������
	uint32_t counter_count					= 0;	// ��������
	uint32_t combo_count					= 0;	// ��������
	bool	 is_calc_combo					= false;// �ôι����Ƿ������������ʣ�һ�ι�����������Ρ�Ⱥ����ֻ��һ���������ʣ���һ�ε�������һ�ι�������Ҫ�����������
	uint32_t trigger_skill_count			= 0;	// �������ܴ���
	uint32_t athanasia_count				= 0;	// ��������
	uint32_t add_buff_after_damage_count	= 0;	// ���˺�������BUFF����
	uint32_t event_trigger_count			= 0;	// �¼���������
	uint32_t one_round_injured = 0;					// һ���غ����ܵ��������˺�
	uint32_t one_round_damage = 0;					// һ���غ�����ɵ������˺�
	uint32_t round_count					= 0;	// �غ���
	uint32_t once_injured = 0;						// ÿ�ι����ܵ����˺�����������ɵ��˺���
	uint32_t other_action_count				= 0;	// �����佫�ж�����
	uint32_t in_control_speed				= 0;	// �������ٶ�
	uint32_t all_team_damage				= 0;	// �˺��ۼ�
	uint32_t all_team_damage_turn			= 0;	// �˺�ת��
	uint32_t shield_small_type				= 0;	// ��С����ID	
	uint32_t all_hero_shield_small_type		= 0;	// ȫ���С����ID	
	uint32_t can_soul_relive				= 0;	// �Ƿ�������ʱ�������״̬
	uint32_t soul_relive_count				= 0;	// ��긴�����
	uint32_t crit_combo_phase = 0;					// ����׷��Ķ�δ���
	uint32_t union_attack = 0;						// �л�����
	uint32_t phase_rate_add = 0;					// buff���ӵĶ����
	uint32_t round_phase_num = 0;					// �غ��ڶ�ι�����
	uint32_t round_do_attack_num = 0;				// �غ����ͷż��ܴ���
	uint32_t athanasia_heal_hp = 0;					// ������Ѫ
	bool	 is_relive_cur_round = false;			// �Ƿ񱾻غϸ����, ���ڽ�ֹ���������󸴻��Ŀ��
	uint32_t be_attack_num = 0;						// ����������(110Ԫ����ʹ��)
	uint32_t equip_miss_all_atk_count = 0;			// ����ȫ�幥������
	uint32_t equip_miss_single_atk_count = 0;		// ���ܵ��幥������
	uint32_t equip_miss_mutilp_atk_count = 0;		// ����Ⱥ�幥������
	uint32_t be_heal_hp = 0;						// ������
	uint32_t be_hurt_hp = 0;						// �˺���
	bool	 is_get_new_round = false;				// ����»غ�
	uint32_t pursue_and_attack_count = 0;			// ׷������ʩ�Ŵ���
	uint32_t round_sub_hp = 0;						// �غ��ڿ�Ѫ�ļ�¼(���ڼ�¼����sub_hp�ģ��������ۼ�ֵ)
	uint64_t round_sub_hp_attacker_uid = 0;			// ���ε�Ѫʱ�Ĺ�����uid
	uint32_t one_attack_damage = 0;					// ���ι�����ɵ����˺��������Ҫ����һ��һ��������һ��attack��
	bool	 is_triggered_of_be_attack_count = false;// �ܵ�ָ������������������Ԫ�� �Ƿ��ڱ����佫����ʱ����
};

struct taunt_data
{
	std::map<uint32_t, fight_hero_wptr> taunt_target_map;
	uint32_t taunt_buff_type = 0;
};

//ÿ�غ϶�������ɵ��˺����ݣ�ֻ�ǵ��˲����Լ��Ͷ�����ɵ��˺�
struct round_hurt_data
{
	std::map<uint64_t, uint32_t> hurt_info;			// ���غ϶��Լ�����˺����佫�����˺�ֵ<�佫uid���˺�ֵ>

	//�غϽ�������˺�����
	void clear_hurt_info();
	//�����˺�ֵ
	void add_hurt(uint64_t hero_uid, uint32_t hurt);
	//��ȡ��������˺������佫tid�����Ϊ0��������غ�û�ж��Լ�����˺����佫
	uint64_t get_uid_of_hurt_most() const;
};

// ս���佫
class fight_hero_t : public boost::enable_shared_from_this<fight_hero_t>
{
public:
	fight_hero_t();
	~fight_hero_t();

	void close();

	// ��ʼ��
	bool init(combat_ptr combat, proto::common::hero_single* hs);

	void on_init();
	// ����
	void set_cur_action(const proto::common::combat_form_single& action);
	// ����ϴβ���
	void clear_cur_action();
	// ���ò���ת��ʱ������
	void reset_wave_change_data();

	// �Ƿ�����(�˴������Բ��� �ж�Ѫ�� ״̬�Ƿ������������)
	bool is_dead();
	// �Ƿ���Ը���
	bool can_relive();
	// �Ƿ�����
	bool is_immuno();
	// �Ƿ��ٻ���
	bool is_summon();
	// �Ƿ����
	bool is_monster();
	// �Ƿ����
	bool is_player();
	// �Ƿ��Զ�ս��
	bool is_auto_fight();
	// �޸��Զ�ս��
	void change_auto_fight(uint32_t auto_fight_mode);
	// ��ȡ�Զ�ս��ģʽ
	uint32_t get_auto_fight_mode();

	// ����
	void to_die();

	// 
	void change_death_with_master(uint32_t value);
	// 
	uint32_t get_death_with_master();
	// �޸�ϵͳ����
	void change_control_by_system(uint32_t control_by_system);
	// ��ȡϵͳ����
	uint32_t get_control_by_system();
	// ��ȡ�ٶ�
	uint32_t get_speed();
	// ��ȡ�ȹ�ֵ
	int32_t get_att_speed();
	// ��ȡ�����ȹ�ֵ
	int32_t get_order_att_speed();
	// ����ȹ�ֵ
	void clear_att_speed();
	// �����޸��ȹ�ֵ
	void skill_change_att_speed(int32_t change_value, fight_hero_ptr attacker, bool is_percent = false, uint32_t param1 = 0);
	// �޸��ȹ�ֵ
	void set_att_speed(int32_t att_speed);
	// ��ȡ�������ֵ
	int32_t get_att_more_speed();
	// �޸��������ֵ
	void set_att_more_speed(int32_t value);
	// �޸���������ֵ
	void set_att_order_speed(int32_t value);
	// ��ȡλ��
	uint32_t get_pos();
	// ��ȡ����
	uint64_t get_master();
	// ��ȡ��Ӫ
	uint32_t get_camp();
	// ��ȡ�ж���Ӫ
	uint32_t get_enemy_camp();
	// ��ȡ�佫����
	uint32_t get_type(){	return m_hero_data.base_attr().type();	}
	// ��ȡUID
	uint64_t get_uid();
	const std::string& get_str_uid();
	// ��ȡ�佫ΨһID
	uint64_t get_unique_id();
	// ��ȡTID
	uint32_t get_tid();
	// ��ȡ��������
	const proto::common::hero_single& get_hero_base() const { return m_hero_data; }
	// �Ƿ����
	uint32_t get_wakeup();
	// ��ȡģ��
	uint32_t get_plugin();
	// ��ȡ��ԴID(����ǹ��� ��û�������Ǹ��ӿڵ�id)
	uint32_t get_resource_id();
	// ��ȡ�ű�ID
	uint32_t get_script_id();
	// ��ȡ����ģʽ
	uint32_t get_atk_mode();
	// ��ȡϵ��
	uint32_t get_terry();
	// ��ȡ�Ա�
	uint32_t get_sex();
	// ��ȡְҵ
	uint32_t get_profession();
	bool is_weak_profession();
	// ��ȡ��ȡ���������
	int get_max_combo_count( fight_hero_ptr target );
	// ��ȡ���������(�����Լ�)
	int get_max_combo_count_by_self();
	// ��ȡ���������(���ݵ���)
	int get_max_comba_count_by_enemy();
	// ��ȡ����
	uint32_t get_wave_num();
	// �������ֶ��д��ڱ��
	void set_first_att_order_pos(int32_t pos) { m_first_order_pos = pos; }
	int32_t get_first_att_order_pos() { return m_first_order_pos; }

	stat_data& get_stat_data() { return m_stat_data; }
	count_data& get_count_data() { return m_count_data; }
	const count_data& get_count_data() const { return m_count_data; }

	void set_is_story(bool is_story) { m_is_story = is_story; }
	bool is_story() { return m_is_story; }

	void add_skill(const int skill, const int level, const int init_cd, uint32_t turn_level, uint32_t pos, uint32_t is_use_public_cd = 0);
	void add_turn_skill();
	void fill_turn_skill(const change_model_skills_vec &vec );

	void remove_skill(const int skill);
	int get_skill_level(const int skill);
	// ��ȡĬ�ϼ���
	int32_t get_default_skill();
	// ��ȡ��������
	int32_t get_counter_skill();

	// ���ʹ����������Լ�
	void send_trigger_passive_to_user(uint32_t skill_id, uint32_t buff_id, uint32_t buff_tid);

	// ���Ŀ���ǲ����Լ��ķ��̶���
	bool check_target_taunt(fight_hero_ptr target);

	// ��ȡ����Ч��
	SkillEffectTable* get_skill_effect(uint32_t skill_id);
	//����佫�Ƿ�ӵ�иü���
	bool check_skill_exist(int32_t skill_id);
	// ��鼼���Ƿ����ã�������Ƿ��иü���
	bool check_skill(int32_t skill_id);
	// ��ȡ��ǰ���ʺϵļ���
	uint32_t get_best_skill();
	// ����
	bool do_attack();
	// ai�Զ�ѡ��
	bool do_auto_fight();
	// �Ҽ���AI
	uint32_t find_skill_ai(std::vector<SkillEffectTable*>& skill_ai_list);
	// ��Ŀ��AI
	uint32_t find_target_ai(uint32_t skill_id);

	// ʹ�ü���
	bool do_attack(
		SkillEffectTable* skill_conf,
		fight_hero_ptr select = NULL,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill,
		const std::vector<fight_hero_ptr>* targets = NULL,
		bool trigger_by_buff = false,
		bool can_counter = true);

	// buff����ʹ�ü���
	bool trigger_skill_by_buff(
		SkillEffectTable* skill_conf,
		fight_hero_ptr select = NULL,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill,
		bool can_counter = true);

	bool check_do_attack(
		SkillEffectTable* skill_conf,
		fight_hero_ptr select = NULL,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill,
		const std::vector<fight_hero_ptr>* targets = NULL,
		bool trigger_by_buff = false);

	void do_counter(std::vector<fight_hero_ptr>& counters, bool can_counter = true);

	size_t get_skill_phase(SkillEffectTable* skill_conf);

	size_t get_total_end_phase(SkillEffectTable* skill_conf);
	// ����Ŀ�겢����
	bool find_target_and_attack(
		SkillEffectTable* skill_effect_conf,
		std::vector<fight_hero_ptr>& counters,
		bool& trigger_combo,
		size_t& phase,
		bool trigger_by_buff,
		fight_hero_ptr select = NULL,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill,
		bool is_refind = false);

	// �������ҵ���Ŀ��
	bool do_attack_after_find_target(
		SkillEffectTable* skill_conf,
		std::vector<fight_hero_ptr>& counters,
		bool& trigger_combo,
		size_t& phase,
		bool trigger_by_buff,
		const std::vector<fight_hero_ptr>& targets,
		const std::vector<fight_hero_ptr>& spurting_targets,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill,
		bool is_refind = false);

	// ����һ��Ŀ��
	bool do_attack_target(
		fight_hero_ptr target,
		SkillEffectTable* skill_conf,
		bool& trigger_counter,
		bool& trigger_combo,
		size_t& phase,
		bool trigger_by_buff,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill);
	
	//Ⱥ���˺�,����һȺĿ��
	bool do_attack_targets(
		const std::vector<fight_hero_ptr>& targets,
		SkillEffectTable* skill_conf,
		bool& trigger_combo,
		bool trigger_by_buff,
		std::vector<fight_hero_ptr>& counters,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill);

	//ִ��һ���˺�
	bool do_phase_hurt(
		fight_hero_ptr target,
		SkillEffectTable* skill_conf,
		bool& trigger_counter,
		bool& trigger_combo,
		size_t phase,
		bool trigger_by_buff,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill);


	// ����һ��Ŀ��
	bool check_do_attack_target(
		fight_hero_ptr target,
		SkillEffectTable* skill_conf,
		size_t& phase,
		bool trigger_by_buff,
		proto::common::combat_act_type type = proto::common::combat_act_type_skill);

	void get_pvp_param(int32_t& pvp_add_param, int32_t& pvp_dec_param, fight_hero_ptr target);

	uint32_t get_hero_immuno_attr();
	int32_t get_hero_element_hurt_increase(fight_hero_ptr target);//����Ŀ���ϵ���ȡ�Լ���ϵ����������
	int32_t get_hero_element_hurt_reduce(fight_hero_ptr attacker);//���ݹ����ߵ�ϵ���ȡ�Լ���ϵ���������
	uint32_t get_hero_attr_relation_type(fight_hero_ptr p_target);

	// ����һ��Ŀ���
	bool do_after_attack_target(fight_hero_ptr target, SkillEffectTable* skill_conf, bool trigger_by_buff);
	
	// ����Ŀ��
	bool find_target(SkillEffectTable* skill_conf, std::vector<fight_hero_ptr>& targets, std::vector<fight_hero_ptr>& spurting_targets, proto::common::combat_act_type type, fight_hero_ptr select = NULL);

	// ���ܸ���buff
	bool do_skill_buff(
		size_t phase,
		FIGHT_EVENT when,
		skill_event_target_type to,
		SkillEffectTable* skill_conf, 
		fight_hero_ptr target = NULL);

	// �����˺�����
	bool do_skill_hurt(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		bool & combo);

	void do_crit(fight_hero_ptr target, int & crit_multiple, int & heal_crit_multiple);

	bool do_dodge(SkillEffectTable* skill_conf,fight_hero_ptr target);
	bool do_immuno(SkillEffectTable* skill_conf, fight_hero_ptr target);
	bool do_equip_dodge(SkillEffectTable* skill_conf, fight_hero_ptr target);

	bool do_skill_hurt_imp(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple,
		bool & combo);

	void do_attack_result_notify(proto::common::combat_act_type type, fight_hero_ptr target, SkillEffectTable *p_skill_conf );

	// ��Ѫ
	void do_leech(SkillEffectTable* skill_conf,fight_hero_ptr target);
	// ��Ѫ����
	int calc_leech(SkillEffectTable* skill_conf, fight_hero_ptr target);
	// ����
	void do_reflect(SkillEffectTable* skill_conf, fight_hero_ptr target);
	// �������
	bool check_combo(SkillEffectTable* skill_conf, fight_hero_ptr target);

	// ����ֱ��
	uint32_t calc_direct_injury(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple
		);

	// �����˺�����
	uint32_t calc_limit_injury(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple
		);

	uint32_t get_attack();

	// ���� ս������
	void update_fight_attr(proto::common::hero_single* single, uint32_t type, int32_t value);

	static bool is_buff_skill(uint32_t skill);

	// ���㹥����
	int calc_attack(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple);

	// ���������
	int calc_defend(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple);

	// �����˺����Ӱٷֱ�
	float calc_injury_addition_percent(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple);

	// ͨ��BUFFĿ�����ͻ�ȡĿ��
	void get_target_by_buff_select_target(fight_hero_ptr select, int type, int rand_count, std::vector<fight_hero_ptr>& out, uint32_t param1 = 0);

	// �����˺�
	int calc_injury(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple);

	// ���㷴��
	int calc_reflect(
		size_t phase,
		SkillEffectTable* skill_conf,
		fight_hero_ptr target,
		proto::common::combat_act_type type,
		int crit_multiple); 

	// ����
	bool do_skill_heal(size_t phase, SkillEffectTable* skill_conf, fight_hero_ptr target, int heal_crit_multiple);

	// ��buff
	static void do_add_skill_buff(fight_hero_ptr p_hero, fight_hero_ptr p_attacker, uint32_t skill_id, bool b_use_rate, uint32_t buff_add_rate, const buff_info_vec& buffs);

	// ����Ч�����н��
	static bool do_effect_hit_result(fight_hero_ptr p_attacker, fight_hero_ptr p_target);

	// ��ɢbuff
	bool do_dispel_skill_buff(fight_hero_ptr p_hero, fight_hero_ptr p_attacker, uint32_t skill_id, uint32_t buff_dispel_rate, uint32_t buff_dispel_num, const buff_dispel_info_vec& buffs);

	// ����ս��
	bool update_fight(const proto::common::hero_state& state);

	void do_update_fight();

	//����ս���е�Ѫ��(bossѪ��ͬ��)
	void sync_hp(uint32_t value);

	//���ó����ҵ�Ӣ��
	void set_taunt_me_hero(uint64_t uid) { m_taunt_me_hero_id = uid; }
	//��������ҵ�Ӣ��
	void clear_taunt_me_hero() { m_taunt_me_hero_id = 0;  }

	uint64_t get_taunt_me_hero() { return m_taunt_me_hero_id; }
public:
	void add_skill_cd_notify();
	
	bool is_relive_cur_round() { return m_count_data.is_relive_cur_round == true; }
public:
	// �غϿ�ʼ
	bool on_round_start_imp();
	// �غϽ���
	void on_round_end_imp();
	// �غϿ�ʼ
	void on_round_start();
	// �غϽ���
	void on_round_end();
	// ����ǰ
	void before_attack(SkillEffectTable* skill_conf, bool trigger_by_buff);
	// ������
	void after_attack(SkillEffectTable* skill_conf, bool trigger_by_buff);
	// �ű�ʹ�ü��ܺ�
//	void after_script_use_skill(SkillEffectTable* skill_conf);
	// ������������
	void do_skill_consum(SkillEffectTable* skill_conf);
	//��⼼������
	bool check_skill_consum(SkillEffectTable* skill_conf);
	// ����
	void on_dead(fight_hero_ptr attaker, SkillEffectTable* skill_conf);
	// ����
	void on_relive(
		fight_hero_ptr attaker, 
		uint32_t buffid, 
		uint32_t bufftid,  
		uint32_t skill, 
		int relive_hp, 
		int relive_speed = -1);

	void on_soul_relive(
		fight_hero_ptr attaker,
		uint32_t buffid,
		uint32_t bufftid,
		uint32_t skill,
		int relive_hp,
		int relive_speed,
		int relive_round,
		int control_by_system);
	// �ٻ�
	bool summon(
		// �ٻ���ID
		uint32_t summonid,
		// �ٻ���HP������ ���Ϊ0 ��ʹ��
		uint32_t master_hp_ratio,
		// �ٻ��߹��������� ���Ϊ0 ��ʹ��
		uint32_t master_attack_ratio,
		// �ٻ��߷��������� ���Ϊ0 ��ʹ��
		uint32_t master_defend_ratio,
		// �����������
		uint32_t max_count,
		// �Ƿ������ٻ�������
		uint32_t death_with_master,
		uint32_t buffid,
		uint32_t bufftid, 
		uint32_t skill);

	uint32_t get_relive_count();
	uint32_t get_soul_relive_count();

	bool is_single_attack(SkillEffectTable* skill_conf);
	bool is_mutilp_attack(SkillEffectTable* skill_conf);
public:

	// ��ȡ�غ���
	uint32_t get_round();
	// ��ȡս��ָ��
	combat_ptr get_combat();
	// ��ȡս��id
	uint64_t get_fight_uid();

	// ��ȡ����cd
	uint32_t get_skill_cd(uint32_t skill);
	// ������cd
	void sub_skill_cd(uint32_t cd = 1);

	void sub_skill_cd(uint32_t skill, uint32_t cd);
	// �Ӽ���cd
	void add_skill_cd(uint32_t skill);
	// �Ӽ���cd
	void add_skill_cd_ex(uint32_t skill, uint32_t cd);
	//���ü���CD
	void set_skill_cd(uint32_t skill, uint32_t level );


// 	// У�鿪������cd
// 	bool check_start_skill_cd(SkillEffectTable* conf);
//	// ����Ŀ��
//	void add_cur_target(fight_hero_ptr target);
	// ���ñ�������Ϣ
	void set_be_taunt_info(fight_hero_ptr target, bool is_add, uint32_t taunt_buff_type = 0, uint32_t buff_tid = 0);
	// ���ó���buff_id
	void set_taunt_buff_info(uint32_t buff_type) { m_taunt_data.taunt_buff_type = buff_type; }
	// ���ӳ���Ŀ��
	void add_taunt_target(fight_hero_ptr p_target);
	// �Ƴ�����Ŀ��
	void remove_taunt_target(fight_hero_ptr p_target);
	// ���������Ϣ
	void clear_taunt_info();
	// ���ò���ѡ��(ע�������Ҫ������ã��ᵼ��ѡ��buffʩ��Ŀ��ö��skill_buff_target_type 17 ��Ŀ�����
	void set_cur_select(const std::string& select);

	// �ַ��⻷BUFF
	void distribute_special_buff();

	// ���չ⻷BUFF
	void recovery_special_buff();

	// �����BUFF
	void activation_passive_buff();

	// �������BUFF
	void clear_passive_buff();
public:
	// ����˳������
	static bool hero_speed_sort(const fight_hero_ptr& h1, const fight_hero_ptr& h2);
	// ���ֶ����������ֵ����
	static bool hero_att_more_speed_sort(const fight_hero_ptr& h1, const fight_hero_ptr& h2);

	static bool hero_max_speed_sort(const fight_hero_ptr& h1, const fight_hero_ptr& h2);

	void set_full_speed(uint32_t full_speed) { m_full_speed = full_speed; }
	uint32_t get_full_speed() { return m_full_speed; }
public:

	// ��ȡbuff���������
	int get_attr_without_buff(uint32_t type);
	// ��ȡ����
	int get_attr(uint32_t type);
	//��ȡ���԰ٷֱ�
	int get_attr_percent(uint32_t type);
	// ��������
	void set_attr(uint32_t type, int value);
	// ������
	void sub_attr(uint32_t type, int value);
	//����غ�����
	void clear_round_attr();

	int get_real_sub_hp_value( int value );

	void soul_condition_on_round_end();
	uint32_t get_hp() { return get_attr(attrtype_enum::hp); }
	uint32_t get_max_hp() { return get_attr(attrtype_enum::max_hp); }
	uint32_t get_max_hp_without_buff() { return get_attr_without_buff(attrtype_enum::max_hp); }//��ȡ��ʼ�������ֵ
	uint32_t get_hp_percent();
	// ��hp
	void add_hp(int value);
	// ����HP
	uint32_t heal_hp(fight_hero_ptr attacker, int value);
	// ����HP������������Ч��������
	uint32_t heal_hp_regardless_of_attr(int value);
	// ��hp
	void sub_hp(int value, fight_hero_ptr attacker, uint32_t skill = 0, bool is_use_event = true );
	// ������
	void on_be_attack(int damage, fight_hero_ptr attacker, uint32_t skill = 0, bool is_buff = false);
	// ��̯�˺�
	int do_share_damage(int damage, fight_hero_ptr attacker, uint32_t skill, bool is_buff);
	// ָ��Ӣ�۷�̯�˺�
	int do_share_hurt(int damage, fight_hero_ptr attacker, uint32_t skill);
	// ����е��˺�
	int do_target_bear_damage(int damage, fight_hero_ptr attacker, uint32_t skill, bool is_buff);
	// �е��˺�
	void notify_bear_damage();
	// ת���˺�
	int do_transfer_damage(int damage, fight_hero_ptr attacker, uint32_t skill, bool is_buff);
	// ��ȡŭ��
	uint32_t get_sp();
	// ��ŭ��
	void sub_sp(uint32_t value);
	// ��ŭ��
	void add_sp(uint32_t value);
	// ������ŭ��
	void sub_disposition_sp(uint32_t value);
	// ��ȡ����ŭ��
	uint32_t get_disposition_sp();
	// �޸ı��
	void set_mark_id(uint32_t mark_id) { m_mark_id = mark_id; }
	// ��ȡ���
	uint32_t get_mark_id() { return m_mark_id; }
	// �Ƿ񱻿�
	bool is_in_control();
	// �Ƿ��ڻþ�״̬
	bool is_in_mirage();
	// �������м���CD 
	void inc_all_skill_cd(fight_hero_ptr attacker, uint32_t cd);
	// �������м���CD
	void dec_all_skill_cd(fight_hero_ptr attacker, uint32_t cd);

	// ������Ӽ���CD 
	void inc_random_skill_cd(fight_hero_ptr attacker, uint32_t cd);
	// ������ټ���CD
	void dec_random_skill_cd(fight_hero_ptr attacker, uint32_t cd);

	// ����
	void change_model(uint32_t change_type, uint32_t change_phase, uint32_t change_skill_level, uint32_t resource_id);
	void restore_model();

	uint32_t athanasia_count() const;
	void athanasia_count(uint32_t value);
public:
	// �����յ����˺�
	void deal_be_attack(int32_t damage, fight_hero_ptr attacker, uint32_t skill);
// 	// ��¼�˺�
// 	void add_damage(int damage);
// 	// ��¼�ܵ����˺�
// 	void add_injured(int injured);
// 	// ��ȡ��ɵ��˺�
// 	uint32_t get_round_damage(uint32_t round);
// 	// ��ȡ�ܵ����˺�
// 	uint32_t get_round_injured(uint32_t round);
	// ��ȡ���һ���˺�������
	const fight_calc_result_t& get_fight_calc_result() { return m_calc_result; }
	// ���÷�̯�˺�
	void set_bear_damage(uint32_t ratio, fight_hero_ptr target);
public:

	// ��ȡ�ű�����
	inline script_fight_hero_t* get_script_proxy() const { return m_script_proxy; }
	// ��ȡ��ǰս������
	proto::common::combat_action_data* get_cur_process();
	// ��ȡbuff������
	buff_manager_t& get_buff_manager() { return m_buff_mgr; }

	// ����ս����Ϊ
	//void add_combat_act(proto::common::combat_act_type type, uint32_t value, uint64_t target, uint32_t remain_value = 0);
	void add_combat_act(proto::common::combat_act_type type, uint32_t value, fight_hero_ptr target, fight_hero_ptr attacker,
						uint32_t remain_value = 0, uint32_t remain_value2 = 0, uint32_t param = 0, uint32_t param1 = 0);
	// ����һЩս����Ϊ
	bool pass_combat_act_type(proto::common::combat_act_type type);


	// ��̯�˺�
	void share_damage_to(fight_hero_ptr teammate, fight_hero_ptr attacker, uint32_t skill, uint32_t damage);
	// ����ս��������Ϊ
	void add_combat_skill_act(proto::common::combat_act_type type, uint32_t value, uint64_t attacker, std::vector<uint64_t>& targets);

	// buff�Ƴ�ʱ
	void on_remove_buff(uint32_t id, uint32_t tid, uint32_t layer, uint32_t round, uint32_t event, uint64_t attacker_id = 0, const bool dispel = false);
	// buff����ʱ
	void on_add_buff(uint32_t id, uint32_t tid, uint32_t layer, uint32_t round, uint32_t event,  uint64_t attacker_id = 0);
	// ��������buff
	void on_buff_immuno();
	// ����buff��Ϊ
	void add_combat_buff_act(proto::common::combat_act_type type, uint32_t id, uint32_t tid, uint32_t layer, uint32_t round, uint64_t attacker_id = 0);
	
	// ���ýű�����
	void set_script_var(const std::string& var, int value);
	// ��ȡ�ű�����
	int get_script_var(const std::string& var);

	// ��ȡ��������
	proto::common::combat_act_step get_attack_step();
	// ���ù�������
	void set_attack_step(proto::common::combat_act_step step);

	void pack_attack_targets(std::string &targets);
	void peek_recovery_data(proto::common::fight_recovery_hero_single_data *hero_data);
	void peek_attr_list(proto::common::fight_recovery_hero_single_data* hero_data);
	void peek_fight_skill_data(proto::common::fight_hero_skill_data *skill_data);
	void peek_save_data(proto::common::hero_save_data *hero_data);

	// �¼� p_event_owner ���¼�������
	void do_team_script_event(FIGHT_EVENT event, const fight_hero_ptr p_event_owner );

	// �¼�
	bool on_event(FIGHT_EVENT event, const fight_hero_ptr p_event_owner );


	// ��������BUFF��������
	void add_special_buff_to_all(int buff, int target_type, int skill );
	// ɾ��������BUFF
	void remove_special_buff_from_all(int buff, int target_type, int skill);


	fight_hero_ptr get_first_target();
	fight_hero_ptr get_cur_target();
	fight_hero_ptr get_special_target();
	fight_hero_ptr get_bear_damage_target();
	
	SkillEffectTable* get_cur_skill();
	fight_hero_ptr get_cur_attacker();
	void set_cur_attacker(fight_hero_ptr attacker);

	uint32_t counter_count() const;
	void counter_count(uint32_t value);

	uint32_t add_buff_after_damage_count() const;
	void add_buff_after_damage_count(uint32_t value);

	uint32_t trigger_skill_count() const;
	void trigger_skill_count(uint32_t value);

	uint32_t combo_count() const;
	void set_combo_count(uint32_t value);

	//���ż��ܶ�����Ч
	bool do_skill_attack_target(SkillEffectTable* skill_conf, const std::vector<fight_hero_ptr>& targets, proto::common::combat_act_type type);

	// Ŀ�껤��ֻ
	static void do_target_shield_points(fight_hero_ptr target, int32_t &damage, int32_t &absorb );

	static void deal_with_shield(fight_hero_ptr taret, int32_t &damage, int32_t &absorb, attrtype_enum::attr_type type, uint32_t buff_small_type);

	void activation_skill(uint32_t skill, uint32_t level);


	bool is_boss() {
		return ( m_hero_data.base_attr().monster_type() == FIGHT_HERO_TYPE_BIG_BOSS || m_hero_data.base_attr().monster_type() == FIGHT_HERO_TYPE_SML_BOSS );
	 }
	
	int get_max_attr(uint32_t attr_id);
	
public:
	//�Ƴ����б�������buffЧ��
	void clear_all_specail_buff();

	uint32_t add_special_buff_skill_id( uint32_t skill_id );

	uint32_t del_special_buff_skill_id( uint32_t skill_id );

	uint32_t get_special_buff_skill_size(uint32_t skill_id);

	uint32_t on_forget();											//������ʱ

	uint32_t on_de_forget();										//������ʱ

	uint32_t on_release_special_buff(uint64_t hero_uid, uint32_t buff_id);

	std::map<uint32_t, uint32_t>	m_special_buff_skill_id;			// �Լ����ͷ�������⻷��skill_id + ����(��ͬbuff�ȼ�������skil_id��ͬ),�������Ϊ0���Ƴ���ֵ��

	std::map<uint64_t, std::set<uint32_t>>	m_be_special_buff_hero_list;// �����ͷ��˹⻷��Ӣ��id+��Ӧ�Ĺ⻷�б�,����������֮���ջ�buff
public:
	void add_transfer_hero(uint64_t hero_uid, uint32_t hurt) { m_transfer_hero_list[hero_uid] = hurt; }

	void clear_transfer_hero() { m_transfer_hero_list.clear(); }

	std::map<uint64_t, uint32_t> m_transfer_hero_list;					// ת���˺�Ӣ���б�
public:
	//����һ���˺�������
	void clear_phase_fight_info();
public:
	proto::common::hero_single m_hero_data;			// �佫��ʼ����

	buff_manager_t m_buff_mgr;						// buff������
	buff_element_manager_t m_buff_element_mgr;		// buffԪ�ع�����
	buff_element_manager_t m_buff_element_moment_mgr;// ˲��BUFFԪ�ع�����
	combat_wptr m_combat;							// ս��ָ��
	proto::common::combat_form_single m_cur_form;	// ����
	attr_map m_cur_attr;							// ����


	fight_calc_result_t m_calc_result;				// ս��������

	uint32_t get_do_attack_num() { return m_count_data.round_do_attack_num > 0 ? m_count_data.round_do_attack_num : 1; }

	//��ʼ��������,�����в��κ�
	void init_att_speed() { m_att_speed = get_speed();	}

	//�ܷ�׷��
	bool can_be_follow_attack(fight_hero_ptr p_attack);

	uint32_t get_activation_skill() { return m_activation_skill; }

	fight_hero_ptr get_self_ptr() { return shared_from_this(); }

	//���ӱ��غ϶��Լ�����˺���ֵ
	void add_round_enemy_hurt();
	//��ȡ���غ϶��Լ��˺���ߵĴ����ˣ��˺���ͬȡ���һ�����ˣ��Ҳ���������з������佫������з�û�д���佫����NULL
	fight_hero_ptr get_hurt_most_alive_enemy(fight_hero_ptr attacker = NULL, SkillEffectTable* skill_conf = NULL);
	//��ȡ�ͻ��˲���ʱѡ�е�Ŀ��
	fight_hero_ptr get_form_selected_hero();

	void send_total_damage(SkillEffectTable* skill_conf, fight_hero_ptr target, fight_hero_ptr attacker);
public:

// 	typedef std::map<uint32_t, fight_hero_round_data> round_data;
// 	round_data m_round_data;						// �佫�غ�����
public:
	script_fight_hero_t*			m_script_proxy = NULL;		// �ű�����
	std::map<std::string, int>		m_script_var;				// �ű�����
	std::map<uint64_t, fight_hero_wptr> m_attack_targets;		// ÿ�ι���������Ŀ��
public:
	// �������ߵ�buff����
	void add_immuno_big_buff_type(uint32_t type);
	void add_immuno_small_buff_type(uint32_t type);

	bool is_immuno_big_buff_type(uint32_t type);
	bool is_immuno_small_buff_type(uint32_t type);

	// ������ߵ�buff����
	void clear_immuno_buff_type() { m_immuno_big_buff_types.clear(); m_immuno_small_buff_types.clear(); }

	const std::set<uint32_t>& get_immuno_big_buff_types() { return m_immuno_big_buff_types; }
	const std::set<uint32_t>& get_immuno_small_buff_types() { return m_immuno_small_buff_types; }

public:
	std::set<uint32_t>			m_immuno_big_buff_types;	// ���ߵ�����buff������
	std::set<uint32_t>			m_immuno_small_buff_types;	// ���ߵ�����buffС����
	uint32_t get_turn_level() { return m_change_model_phase; }
	uint32_t m_bear_damage = 0;								// ��̯���˺�

	void add_immuno_buff(uint32_t buff_small_type) { m_immuno_special_buff.insert(buff_small_type); }
	bool is_immuno_buff(uint32_t buff_small_type) { return m_immuno_special_buff.find(buff_small_type) != m_immuno_special_buff.end(); }					//�Ƿ������ߵ�buff
	std::set<uint32_t>			m_immuno_special_buff;		//���ߵĹ⻷buff
private:
	stat_data m_stat_data;								// ͳ������
	count_data m_count_data;							// ��������
	round_hurt_data m_round_hurt_data;					// �غ��˺�����
	SkillEffectTable* m_cur_skill_conf = NULL;			// ��ǰʹ�õļ���
	fight_hero_wptr m_cur_target;						// ���ι����ĵ�ǰĿ��
	fight_hero_wptr m_bear_damage_target;				// ��̯�˺�Ŀ��
	fight_hero_wptr m_special_target;					// ���⹥����Ŀ��
	fight_hero_wptr m_cur_attacker;						// ��ǰ������
	uint32_t m_mark_id = 0;								// ���ID
	uint32_t m_round = 1;								// ��ǰ�غ�(ÿ���佫���������Լ��Ļغ�)
	uint32_t m_att_speed = 0;							// �ȹ�ֵ(���ᳬ����ֵ)
	uint32_t m_order_att_speed = 0;						// �����ȹ�ֵ(�ᳬ����ֵ �ޱ�Ҫ��Ӧ�����޸Ľӿ�)
	uint32_t m_att_more_speed = 0;						// �������ֵ
	uint32_t m_auto_fight_mode = 0;						// �Զ�ս��ģʽ
	uint32_t m_change_model_phase = 0;					// �����׶�
	uint32_t m_control_by_system = 0;					// ϵͳ���Ƽ����ͷ�
	uint32_t m_death_with_master = 0;					// ��������ʱ��������
	uint32_t m_full_speed = 0;							// ���������ֵ

//	int		m_last_hp = 0;								// �ϴ�hp		//wys ע�� ��Ʋ����� �ж��ظ�����Ӧ���ñ�� 2017.6.16
	int32_t m_first_order_pos = -1;						// �����ֶ��е�λ��

	uint32_t m_activation_skill = 0;					// ����� 
	uint32_t m_activation_skill_level = 0;				// ����ܵȼ�

	uint32_t m_target_count = 0;						// ����Ŀ������
	taunt_data m_taunt_data;							// ��������

	bool	m_is_story = false;							// �Ƿ��Ǿ����佫
	bool	m_dead_flag = false;						// �������

	uint32_t m_bear_damage_ratio = 0;					// ��̯�˺�����
	uint64_t m_taunt_me_hero_id = 0;					// �����ҵ��佫id;
public:
	skill_manager_t m_skill_manager;

public:
	uint32_t get_suck_value(uint32_t type) { return m_suck_value[type]; }
	void add_suck_value(uint32_t type, uint32_t value) { m_suck_value[type] += value; }
	void clear_suck_value() { m_suck_value.clear(); }
	std::map<uint32_t, uint32_t> m_suck_value;			//�����Ե�buff����ʱ�Եġ�����ֻ�ܴ������
};

#endif//__FIGHT_HERO_HPP__