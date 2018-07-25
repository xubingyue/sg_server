#include "cultivate_manager.hpp"
#include "hero_manager.hpp"
#include "tblh/HeroGrade.tbls.h"
#include "tblh/HeroStar.tbls.h"
#include "tblh/Hero.tbls.h"
#include "tblh/HeroTalentAdd.tbls.h"
#include "tblh/HeroGet.tbls.h"
#include "tblh/LevelDemad.tbls.h"
#include "tblh/HeroTalentPos.tbls.h"
#include "tblh/HeroTalentPlan.tbls.h"
#include "tblh/HeroTalentLevel.tbls.h"
#include "tblh/HeroFate.tbls.h"
#include "tblh/HeroFateLv.tbls.h"
#include "tblh/Comprehensive.tbls.h"
#include "tblh/SkillTable.tbls.h"
#include "tblh/SkillEffectTable.tbls.h"
#include <stdlib.h>
#include "utility.hpp"
#include "item/item_manager.hpp"
#include "log_enum.hpp"
#include "tblh/errcode_enum.hpp"
#include "log/log_wrapper.hpp"
#include "task/task_manager.hpp"
#include "role/money_manager.hpp"
#include "achieve/achieve_common.hpp"
#include "common/ContainerParse.h"
#include "sys_notice/sys_notice_manager.hpp"
#include "general_event/general_info_manager.hpp"
#include "mail/mail_manager.hpp"
#include "tblh/mailcode_enum.hpp"
#include "tblh/HeroFamous.tbls.h"

USING_NS_COMMON;
USING_NS_CONFIG;

std::map<uint32_t, uint32_t> cultivate_manager_t::levelup_item;
std::map<uint32_t, uint32_t> cultivate_manager_t::grade_level;
std::vector<uint32_t> cultivate_manager_t::star_skill_level;
std::map<uint32_t, uint32_t> cultivate_manager_t::starup_item;
bool cultivate_manager_t::init()
{
	auto p_levelup_item = GET_CONF(Comprehensive, comprehensive_common::level_up_mat);
	if (NULL == p_levelup_item)
	{
		log_error("star_prob_str null error");
		return false;
	}
	Dawn::parseMapContainer(levelup_item, p_levelup_item->parameter1().c_str(), ":$");
	if (levelup_item.empty())
	{
		log_error("levelup_item_str null error");
		return false;
	}
	
	auto p_grade_level = GET_CONF(Comprehensive, comprehensive_common::quality_levelunlock);
	if (NULL == p_grade_level)
	{
		log_error("grade_level_str null error");
		return false;
	}
	Dawn::parseMapContainer(grade_level, p_grade_level->parameter1().c_str(), ":$");
	if (levelup_item.empty())
	{
		log_error("levelup_item_str null error");
		return false;
	}

	auto p_skill_level = GET_CONF(Comprehensive, comprehensive_common::hero_skill_uplevel_limit);
	if (NULL == p_skill_level)
	{
		log_error("skill_level_str null error");
		return false;
	}
	Dawn::parseContainer<uint32_t>(star_skill_level, p_skill_level->parameter1().c_str(), ":");
	if (star_skill_level.empty())
	{
		log_error("skill_level_str null error");
		return false;
	}

	auto p_starup_item = GET_CONF(Comprehensive, comprehensive_common::wannengpiece);
	if (NULL == p_starup_item)
	{
		log_error("starup_item_str null error");
		return false;
	}
	Dawn::parseMapContainer(starup_item, p_starup_item->parameter1().c_str(), ":$");
	if (starup_item.empty())
	{
		log_error("starup_item_str null error");
		return false;
	}
	return true;
}

uint32_t cultivate_manager_t::get_star_item()
{
	auto star_item = GET_CONF(Comprehensive, comprehensive_common::Star_item);
	uint32_t val = GET_COMPREHENSIVE_VALUE_1(star_item);
	return val;
}

uint32_t cultivate_manager_t::get_talent_stone()
{
	auto talent_stone = GET_CONF(Comprehensive, comprehensive_common::Talent_stone);
	uint32_t val = GET_COMPREHENSIVE_VALUE_1(talent_stone);
	return val;
}

uint32_t cultivate_manager_t::get_init_talent_count()
{
	auto talent_count = GET_CONF(Comprehensive, comprehensive_common::hero_talent_init);
	uint32_t val = GET_COMPREHENSIVE_VALUE_1(talent_count);
	return val;
}

uint32_t cultivate_manager_t::get_plugin_star()
{
	auto awake_star_num = GET_CONF(Comprehensive, comprehensive_common::awake_star_num);
	uint32_t val = GET_COMPREHENSIVE_VALUE_1(awake_star_num);
	return val;
}

uint32_t cultivate_manager_t::cultivate_hero(role_ptr p_role, const proto::client::cg_hero_cultivate_request& msg, uint32_t& out, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] cultivate_hero begin", p_role->get_uid());
	hero_ptr p_hero = hero_manager_t::get_hero(p_role, msg.hero_id());
	if (NULL == p_hero)
	{
		log_error("hero_manager_t::get_hero[%d]  NULL!!", msg.hero_id());
		return errcode_enum::notice_hero_null;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return false;
	}

	std::vector<uint32_t> va_list;
	for (int32_t i = 0; i < msg.value_size(); ++i)
	{
		va_list.push_back(msg.value(i));
	}
	uint32_t value1 = 0;
	uint32_t value2 = 0;
	if (va_list.size() >= 1)
	{
		value1 = va_list[0];
	}
	if (va_list.size() >= 2)
	{
		value2 = va_list[1];
	}
	uint32_t ret;
	switch (msg.type())
	{
	case proto::common::EMCUTYPE_LEVEL:
		ret = levelup_hero(p_role, p_hero, value1, value2, p_data);
		break;
	case proto::common::EMCUTYPE_STARUP:
		ret = starup_hero(p_role, p_hero, value1, p_data);
		break;
	case proto::common::EMCUTYPE_ADVANCED:
		ret = advance_hero(p_role, p_hero, p_data);
		break;
	case proto::common::EMCUTYPE_SKILLUP:
	case proto::common::EMCUTYPE_SKILL_UNLOCK:
		{
			ret = levelup_skill(p_role, p_hero, value1, p_data);
			out = value1;
		}
		break;
	case proto::common::EMCUTYPE_WAKEUP:
		ret = wakeup_hero(p_role, p_hero, p_data);
		break;
	case proto::common::EMCUTYPE_SKILL_REPLACE:
		ret = replace_skill(p_role, p_hero, value1, value2, p_data);
		break;
	case proto::common::EMCUTYPE_TALENTACTIVE:
		ret = active_talent(p_role, p_hero, value1, p_data);
		break;
	case proto::common::EMCUTYPE_TALENTUP:
		ret = levelup_talent(p_role, p_hero, value1, p_data);
		break;
	case proto::common::EMCUTYPE_TALENTRESET:
		ret = reset_talent(p_role, p_hero, p_data);
		break;
	case proto::common::EMCUTYPE_TALENTADD:
		ret = aware_talent(p_role, p_hero, p_data);
		break;
	case proto::common::EMCUTYPE_SMELT:
		ret = smelt_hero(p_role, p_hero, p_data);
		break;
	case proto::common::EMCUTYPE_FAMOUS:
		ret = famous_hero(p_role, p_hero, value1, p_data);
		break;
	default:
		ret = errcode_enum::notice_unknown;
		break;
	}
	p_hero->calc_fighting();
	CULTI_LOG("role[%lu] cultivate_hero end", p_role->get_uid());
	proto::common::hero_data* p_hero_data = p_data->mutable_hero();
	proto::common::hero_single* p_hero_single = p_hero_data->add_hero_list();
	p_hero->peek_data(p_hero_single);
	//离线竞技场防守阵容同步
	p_role->m_formation_mgr.update_offline_arena_form(p_hero->get_unique_id());
	return ret;
}

uint32_t cultivate_manager_t::levelup_hero(role_ptr p_role, hero_ptr p_hero, uint32_t item_id, uint32_t item_num, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] levelup_hero[%d] begin", p_role->get_uid(), p_hero->get_tid());
	//if (p_hero->get_unique_id() == p_role->get_main_hero_uid())
	//{
	//	log_error("main_hero can't levelup");
	//	return errcode_enum::notice_unknown;
	//}
	uint32_t add_exp = 0;
	if (levelup_item.find(item_id) == levelup_item.end())
	{
		log_error("levelup_item[%d] invalid", item_id);
		return errcode_enum::notice_item_type_not_match;
	}
	add_exp = levelup_item[item_id];
	
	if (!item_manager_t::has_item(p_role, item_id, item_num))
	{
		log_error("role[%lu] levelup_item[%d:%d] not enough", p_role->get_uid(), item_id, item_num);
		return errcode_enum::notice_item_not_enough;
	}
	// 等级判断
	uint32_t cur_level = p_hero->get_current_level();
	uint32_t old_level = cur_level;
	uint32_t old_exp = p_hero->get_current_exp();
	if (cur_level >= p_role->get_level())
	{
		log_error("role[%lu] hero[%d] level[%d] must less than role_level[%d]", p_role->get_uid(), p_hero->get_tid(), cur_level, p_role->get_level());
		return errcode_enum::notice_role_levle_not_enough;
	}
	if (cur_level >= hero_manager_t::get_hero_level_limit())
	{
		log_error("role[%lu] hero[%d] level[%d] must less than hero_level_limit[%d]", p_role->get_uid(), p_hero->get_tid(), cur_level, hero_manager_t::get_hero_level_limit());
		return errcode_enum::notice_role_levle_not_enough;
	}
	auto p_hero_config = GET_CONF(Hero, p_hero->get_tid());
	if (NULL == p_hero_config)
	{
		log_error("p_hero_config[%d] not found!!", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	for (uint32_t i = 0; i < item_num; ++i)
	{
		uint32_t reply_code = item_manager_t::remove_item(p_role, item_id, 1, log_enum::source_type_hero_levelup, p_hero->get_tid(), p_data);
		if (reply_code != errcode_enum::error_ok)
		{
			break;
		}
		hero_manager_t::add_exp(p_role, p_hero->get_unique_id(), add_exp, log_enum::source_type_hero_levelup, true);
		CULTI_LOG("role[%lu] hero[%lu] addexp[%d]", p_role->get_uid(), p_hero->get_unique_id(), add_exp);
		if (p_hero->get_current_level() >= p_role->get_level())
		{
			break;
		}
		if (cur_level >= hero_manager_t::get_hero_level_limit())
		{
			break;
		}
	}
	
	p_hero->save_self(p_role->get_uid());
	//hero_manager_t::save_all_datas(p_role);
	CULTI_LOG("role[%lu] levelup_hero[%d] success, level_exp from [%d:%d] to [%d:%d]", p_role->get_uid(), p_hero->get_tid(), old_level, old_exp, p_hero->get_current_level(), p_hero->get_current_exp());
	log_wrapper_t::send_hero_log( p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set,
								  log_enum::source_type_hero_levelup, old_level, p_hero->get_current_level() - old_level, p_hero->get_current_level() );
	proto::common::personal_info* p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	achieve_common_t::notify_progress_state(p_role->get_uid(), proto::common::Achieve_Event_Type::ACHIEVE_HERO_NUMBER_LEVEL, p_hero->get_current_level());
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::starup_hero(role_ptr p_role, hero_ptr p_hero, uint32_t replace, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] starup_hero[%d] begin", p_role->get_uid(), p_hero->get_tid());
	auto p_hero_config = GET_CONF(HeroStar, hash_util_t::hash_to_uint32(p_hero->get_tid(), p_hero->get_star()));
	if (NULL == p_hero_config)
	{
		log_error("HeroStar p_hero_config[%d:%d] not found!!", p_hero->get_tid(), p_hero->get_star());
		return errcode_enum::notice_unknown;
	}
	auto p_next_hero_config = GET_CONF(HeroStar, hash_util_t::hash_to_uint32(p_hero->get_tid(), p_hero->get_star()+1));
	if (NULL == p_next_hero_config)
	{
		log_error("role[%lu] hero[%d] star max!!", p_role->get_uid(), p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	if ((int)p_hero->get_current_level() < p_hero_config->need_level())
	{
		log_error("role[%lu] hero[%d] level[%d] not enough[%d]!!", p_role->get_uid(), p_hero->get_tid(), p_hero->get_current_level(), p_hero_config->need_level());
		return errcode_enum::notice_unknown;
	}
	if ((int)money_manager_t::get_money(p_role, proto::common::MONEY_TYPE_COPPER) < p_hero_config->consume_money())
	{
		log_error("role[%lu] hero[%d] can't starup_hero! copper[%d] not enough", p_role->get_uid(), p_hero->get_tid(), p_hero_config->consume_money());
		return errcode_enum::notice_copper_money_not_enough;
	}
	if ((int)money_manager_t::get_money(p_role, proto::common::MONEY_TYPE_HEROSOUL) < p_hero_config->consume_herosoul())
	{
		log_error("role[%lu] hero[%d] can't starup_hero! herosoul[%d] not enough", p_role->get_uid(), p_hero->get_tid(), p_hero_config->consume_herosoul());
		return errcode_enum::notice_copper_money_not_enough;
	}
	if (0 == replace)
	{
		if (errcode_enum::error_ok != item_manager_t::remove_item(p_role, p_hero_config->consume_material().first, p_hero_config->consume_material().second, log_enum::source_type_hero_starup, p_hero->get_tid(), p_data))
		{
			log_error("role[%lu] hero[%d] star_item is not enough!!", p_role->get_uid(), p_hero->get_tid());
			return errcode_enum::notice_item_not_enough;
		}
	}
	else
	{
		uint32_t material_id = p_hero_config->consume_material().first;
		uint32_t material_count = p_hero_config->consume_material().second;
		uint32_t rest_count = item_manager_t::get_item_count(p_role, material_id);
		if (rest_count >= material_count)
		{
			item_manager_t::remove_item(p_role, material_id, material_count, log_enum::source_type_hero_starup, p_hero->get_tid(), p_data);
		}
		else
		{
			Hero* p_base_conf = GET_CONF(Hero, p_hero->get_tid());
			if (NULL == p_base_conf)
			{
				log_error("NULL == p_base_conf Hero[%d]", p_hero->get_tid());
				return errcode_enum::notice_unknown;
			}
			if (starup_item.find(p_base_conf->rarity()) == starup_item.end())
			{
				log_error("hero_rarity[%d]  starup_item not found", p_base_conf->rarity());
				return errcode_enum::notice_unknown;
			}
			uint32_t need_item = starup_item[p_base_conf->rarity()];
			uint32_t need_count = material_count - rest_count;
			if (item_manager_t::has_item(p_role, need_item, need_count))
			{
				item_manager_t::remove_item(p_role, material_id, rest_count, log_enum::source_type_hero_starup, p_hero->get_tid(), p_data);
				item_manager_t::remove_item(p_role, need_item, need_count, log_enum::source_type_hero_starup, p_hero->get_tid(), p_data);
			}
			else
			{
				log_error("role[%lu] hero[%d] star_item is not enough!!", p_role->get_uid(), p_hero->get_tid());
				return errcode_enum::notice_item_not_enough;
			}
		}
	}
	
	money_manager_t::use_money(p_role, proto::common::MONEY_TYPE_COPPER, p_hero_config->consume_money(), log_enum::source_type_hero_starup, p_hero->get_tid());
	money_manager_t::use_money(p_role, proto::common::MONEY_TYPE_HEROSOUL, p_hero_config->consume_herosoul(), log_enum::source_type_hero_starup, p_hero->get_tid());

	uint32_t old_star = p_hero->get_star();
	uint32_t new_star = old_star;
	++new_star;
	
	p_hero->set_star(new_star);
	p_hero->save_self(p_role->get_uid());
	//hero_manager_t::save_all_datas(p_role);
	proto::common::personal_info* p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] starup_hero[%d] success,from[star:%d] to[star:%d]", p_role->get_uid(), p_hero->get_tid(), old_star, new_star);
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_starup, old_star, 1, new_star);

	//成就通知
	achieve_common_t::notify_progress_state(p_role->get_uid(), proto::common::Achieve_Event_Type::ACHIEVE_HERO_NUMBER_STAR, p_hero->get_star());
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::advance_hero(role_ptr p_role, hero_ptr p_hero, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return false;
	}
	CULTI_LOG("role[%lu] advance_hero[%d] begin", p_role->get_uid(), p_hero->get_tid());
	uint32_t old_grade = p_hero->get_grade();
	auto p_hero_config = GET_CONF(HeroGrade, hash_util_t::hash_to_uint32(p_hero->get_tid(), old_grade));
	if (NULL == p_hero_config)
	{
		log_error("p_hero_config[%d:%d] not found!!", p_hero->get_tid(), old_grade);
		return errcode_enum::notice_unknown;
	}
	auto p_next_hero_config = GET_CONF(HeroGrade, hash_util_t::hash_to_uint32(p_hero->get_tid(), old_grade + 1));
	if (NULL == p_next_hero_config)
	{
		log_error("role[%lu] hero[%d] grade max!!", p_role->get_uid(), p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	if (p_hero_config->need_role_level() > p_role->get_level())
	{
		log_error("role[%lu] hero[%d] role_level[%d] not enough, need[%d]!!", p_role->get_uid(), p_hero->get_tid(), p_role->get_level(), p_hero_config->need_role_level());
		return errcode_enum::error_level_not_enough;
	}
	if (p_hero_config->need_level() > p_hero->get_current_level())
	{
		log_error("role[%lu] hero[%d] level[%d] not enough, need[%d]!!", p_role->get_uid(), p_hero->get_tid(), p_hero->get_current_level(), p_hero_config->need_level());
		return errcode_enum::notice_hero_levle_not_enough;
	}

	if (money_manager_t::get_money(p_role, proto::common::MONEY_TYPE_COPPER) < p_hero_config->consume_money())
	{
		log_error("role[%lu] hero[%d] can't starup_hero! copper[%d] not enough", p_role->get_uid(), p_hero->get_tid(), p_hero_config->consume_money());
		return errcode_enum::notice_copper_money_not_enough;
	}

	if (errcode_enum::error_ok != item_manager_t::remove_items(p_role, p_hero_config->consume_material(), log_enum::source_type_hero_advanced, p_hero->get_tid(), p_data))
	{
		log_error("role[%lu] hero[%d] advanced_item is not enough!!", p_role->get_uid(), p_hero->get_tid());
		return errcode_enum::notice_item_not_enough;
	}
	money_manager_t::use_money(p_role, proto::common::MONEY_TYPE_COPPER, p_hero_config->consume_money(), log_enum::source_type_hero_advanced, p_hero->get_tid());
	p_hero->set_grade(p_hero->get_grade() + 1);
	p_hero->save_self(p_role->get_uid());
	//hero_manager_t::save_all_datas(p_role);
	proto::common::personal_info* p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] advance_hero[%d] success, grade from [%d] to [%d]", p_role->get_uid(), p_hero->get_tid(), old_grade, old_grade + 1);
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_advanced, old_grade, 1, p_hero->get_grade());

	//成就通知
	achieve_common_t::notify_progress_state(p_role->get_uid(), proto::common::Achieve_Event_Type::ACHIEVE_HERO_NUMBER_TYPE,p_hero->get_grade());

	//天下大势特殊通知
	general_info_manager_t::update_progress(proto::common::Achieve_Event_Type::ACHIEVE_HERO_TUPO, old_grade, old_grade+1, p_role);

	auto p_task_mgr = p_role->get_task_mgr();
	if (NULL != p_task_mgr)
	{
		p_task_mgr->try_change_task_state(TASK_TARGET_TYPE_HERO_GRADE, *p_data, 1, 1);
	}
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::levelup_skill(role_ptr p_role, hero_ptr p_hero, uint32_t skill_id, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_star() == 0 || p_hero->get_star() > star_skill_level.size())
	{
		log_error("hero[%d] star[%d] limit", p_hero->get_tid(), p_hero->get_star());
		return errcode_enum::notice_unknown;
	}

	uint32_t limit_skill_level = star_skill_level.at(p_hero->get_star() - 1);
	Hero* p_hero_conf = GET_CONF(Hero, p_hero->get_tid());
	if (NULL == p_hero_conf)
	{
		log_error("NULL == p_hero_conf[%d]", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}

	hero_skill hero_skill_data;
	if(!p_hero->find_hero_skill(skill_id, hero_skill_data))
	{
		log_error("role[%lu] hero[%d] can't levelup_skill! skill[%d] not found", p_role->get_uid(), p_hero->get_tid(), skill_id);
		return errcode_enum::notice_unknown;
	}
	if (hero_skill_data.skill_level >= limit_skill_level)
	{
		log_error("role[%lu] hero[%d] can't levelup_skill[%d]! level[%d] limit", p_role->get_uid(), p_hero->get_tid(), skill_id, limit_skill_level);
		return errcode_enum::notice_unknown;
	}
	//if (p_hero_conf->wakeup_skill_type() == proto::common::hero_wakeup_type_unlock &&
	//	p_hero_conf->wakeup_skill_id() == skill_id && 
	//	hero_skill_data.skill_level == 0)
	//{
	//	log_error("levelup_skill error skill[%d] is wakeup_lock", skill_id);
	//	return errcode_enum::notice_unknown;
	//}

	auto p_skill_effect_config = GET_CONF(SkillEffectTable, hash_util_t::hash_to_uint32_move_7(skill_id, hero_skill_data.skill_level));
	if (NULL == p_skill_effect_config)
	{
		log_error("p_skill_effect_config[%d:%d] not found!!", skill_id, hero_skill_data.skill_level);
		return errcode_enum::notice_unknown;
	}
	auto p_next_skill_effect_config = GET_CONF(SkillEffectTable, hash_util_t::hash_to_uint32_move_7(skill_id, hero_skill_data.skill_level +1));
	if (NULL == p_next_skill_effect_config)
	{
		log_error("p_next_skill_effect_config[%d:%d] not found!!", skill_id, hero_skill_data.skill_level +1);
		return errcode_enum::notice_unknown;
	}
	if (money_manager_t::get_money(p_role, proto::common::MONEY_TYPE_COPPER) < p_skill_effect_config->levelup_money())
	{
		log_error("role[%lu] hero[%d] can't levelup_skill[%d]! copper[%d] not enough", p_role->get_uid(), p_hero->get_tid(), skill_id, p_skill_effect_config->levelup_money());
		return errcode_enum::notice_copper_money_not_enough;
	}
	if (money_manager_t::get_money(p_role, proto::common::MONEY_TYPE_HEROSOUL) < p_skill_effect_config->levelup_herosoul())
	{
		log_error("role[%lu] hero[%d] can't levelup_skill[%d]! herosoul[%d] not enough", p_role->get_uid(), p_hero->get_tid(), skill_id, p_skill_effect_config->levelup_herosoul());
		return errcode_enum::notice_copper_money_not_enough;
	}
	uint32_t consume_id = p_skill_effect_config->levelup_consume().first;
	uint32_t consume_num = p_skill_effect_config->levelup_consume().second;
	uint32_t reply_code = item_manager_t::remove_item(p_role, consume_id, consume_num, log_enum::source_type_hero_levelup_skill, skill_id, p_data);
	if (reply_code != errcode_enum::error_ok)
	{
		log_error("role[%lu] hero[%d] can't levelup_skill[%d]! item not enough", p_role->get_uid(), p_hero->get_tid(), skill_id);
		return errcode_enum::notice_item_not_enough;
	}
	money_manager_t::use_money(p_role, proto::common::MONEY_TYPE_COPPER, p_skill_effect_config->levelup_money(), log_enum::source_type_hero_levelup_skill, skill_id, true, p_data);
	money_manager_t::use_money(p_role, proto::common::MONEY_TYPE_HEROSOUL, p_skill_effect_config->levelup_herosoul(), log_enum::source_type_hero_levelup_skill, skill_id, true, p_data);

	p_hero->set_hero_skill_level(skill_id, hero_skill_data.skill_level + 1);
		
	p_hero->save_self(p_role->get_uid());
	//hero_manager_t::save_all_datas(p_role);
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] hero[%d] levelup_skill[%d] success", p_role->get_uid(), p_hero->get_tid(), skill_id);
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_levelup_skill, hero_skill_data.skill_level,1, hero_skill_data.skill_level+1, skill_id);

	//成就通知
	achieve_common_t::notify_progress_state(p_role->get_uid(), proto::common::Achieve_Event_Type::ACHIEVE_HERO_NUMBER_SKILL_LEVEL, hero_skill_data.skill_level + 1);

	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::wakeup_hero(role_ptr p_role, hero_ptr p_hero, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] wakeup_hero[%d] begin", p_role->get_uid(), p_hero->get_tid());
	if (p_hero->get_wakeup() != 0)
	{
		log_error("role[%lu] hero[%d] already wakeup!", p_role->get_uid(), p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	Hero *p_hero_config = GET_CONF(Hero, p_hero->get_tid());
	if (NULL == p_hero_config)
	{
		log_error("Hero p_hero_config[%d] not found!!", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	
	if ((int)money_manager_t::get_money(p_role, proto::common::MONEY_TYPE_COPPER) < p_hero_config->wakeup_consume_money())
	{
		log_error("role[%lu] hero[%d] can't wakeup! copper[%d] not enough", p_role->get_uid(), p_hero->get_tid(), p_hero_config->wakeup_consume_money());
		return errcode_enum::notice_copper_money_not_enough;
	}

	if (errcode_enum::error_ok != item_manager_t::remove_items(p_role, p_hero_config->wakeup_consume_material(), log_enum::source_type_hero_wakeup, p_hero->get_tid(), p_data))
	{
		log_error("role[%lu] hero[%d] can't wakeup! item is not enough!!", p_role->get_uid(), p_hero->get_tid());
		return errcode_enum::notice_item_not_enough;
	}
	money_manager_t::use_money(p_role, proto::common::MONEY_TYPE_COPPER, p_hero_config->wakeup_consume_money(), log_enum::source_type_hero_wakeup, p_hero->get_tid());


	hero_manager_t::check_hero_wakeup_add_plugin(p_role->get_uid(), p_hero->get_tid());
	p_hero->wakeup();
	
	proto::common::personal_info* p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] wakeup hero[%d] success", p_role->get_uid(), p_hero->get_tid());
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_wakeup);

	//if (p_hero_config->wakeup_skill_type() == proto::common::hero_wakeup_type_add)
	//{
	//	p_hero->add_hero_skill(p_hero_config->wakeup_skill_id());
	//}
	//else if (p_hero_config->wakeup_skill_type() == proto::common::hero_wakeup_type_replace)
	//{
	//	p_hero->replace_hero_skill(p_hero_config->wakeup_skill_replace(), p_hero_config->wakeup_skill_id());
	//}
	//else if (p_hero_config->wakeup_skill_type() == proto::common::hero_wakeup_type_unlock)
	//{
	//	hero_skill hero_skill_data;
	//	if (!p_hero->find_hero_skill(p_hero_config->wakeup_skill_id(), hero_skill_data))
	//	{
	//		log_error("wake_up unlock skill[%d] fail", p_hero_config->wakeup_skill_id());
	//		return errcode_enum::notice_unknown;
	//	}
	//	p_hero->set_hero_skill_level(p_hero_config->wakeup_skill_id(), hero_skill_data.skill_level + 1);
	//}
	p_hero->save_self(p_role->get_uid());
	//hero_manager_t::save_all_datas(p_role);
	
	//成就通知
	//achieve_common_t::notify_progress_state(p_role->get_uid(), proto::common::Achieve_Event_Type::ACHIEVE_HERO_NUMBER_STAR, p_hero->get_star());

	std::vector<std::string> param_str_list;
	param_str_list.push_back(common::string_util_t::uint32_to_string(p_hero->get_tid()));
	sys_notice_manager_t::sys_notice_notify(p_role->get_uid(), proto::common::sys_notify_type_hero_wakeup, 0, param_str_list);
	///BROADCAST_SYS_NOTICE_SYS_CHANNEL(p_role->get_uid(), proto::common::sys_notify_type_hero_wakeup, 0,p_hero_config->name().c_str());
	p_role->add_head_frame(proto::common::HEAD_FRAME_AWAKE, p_hero->get_tid());
	
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::unlock_skill(role_ptr p_role, hero_ptr p_hero, uint32_t skill_id, proto::common::role_change_data* p_data)
{
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::replace_skill(role_ptr p_role, hero_ptr p_hero, uint32_t old_skill_id, uint32_t new_skill_id, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_hero_state() == proto::common::hero_state_type_lock)
	{
		log_error("hero[%d] hero_state = lock", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}

	hero_skill old_hero_skill_data;
	if (!p_hero->find_hero_skill(old_skill_id, old_hero_skill_data))
	{
		log_error("role[%lu] hero[%d] old_skill_id[%d] not found", p_role->get_uid(), p_hero->get_tid(), old_skill_id);
		return errcode_enum::notice_unknown;
	}

	SkillEffectTable* p_skill_effect_config = GET_CONF(SkillEffectTable, hash_util_t::hash_to_uint32_move_7(old_skill_id, old_hero_skill_data.skill_level));
	if (NULL == p_skill_effect_config)
	{
		log_error("p_skill_effect_config[%d:%d] not found!!", old_skill_id, old_hero_skill_data.skill_level);
		return errcode_enum::notice_unknown;
	}

	if (p_skill_effect_config->type() == proto::common::skill_type_atk)
	{
		log_error("skill[%d:%d] type = skill_type_atk can't replace", old_skill_id, old_hero_skill_data.skill_level);
		return errcode_enum::notice_unknown;
	}

	hero_skill new_hero_skill_data;
	if (!p_hero->find_hero_skill(new_skill_id, new_hero_skill_data))
	{
		log_error("role[%lu] hero[%d] new_skill_id[%d] not found", p_role->get_uid(), p_hero->get_tid(), new_skill_id);
		return errcode_enum::notice_unknown;
	}
	// 给新技能设置位置
	p_hero->set_hero_skill_pos(new_skill_id, old_hero_skill_data.skill_pos);
	// 旧技能位置改成0
	p_hero->set_hero_skill_pos(old_skill_id, 0);

	p_hero->save_self(p_role->get_uid());
	//hero_manager_t::save_all_datas(p_role);
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] hero[%d] replace_skill [%d] to [%d] success", p_role->get_uid(), p_hero->get_tid(), old_skill_id, new_skill_id);
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_replace_skill, old_skill_id, 0, new_skill_id);
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::active_talent(role_ptr p_role, hero_ptr p_hero, uint32_t talent_id, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] active_talent begin", p_role->get_uid());
	Hero *p_hero_config = GET_CONF(Hero, p_hero->get_tid());
	if (NULL == p_hero_config)
	{
		log_error("Hero p_hero_config[%d] not found!!", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	HeroTalentPlan *p_talent_plan_config = GET_CONF(HeroTalentPlan, p_hero_config->talent());
	if (NULL == p_talent_plan_config)
	{
		log_error("HeroTalentPlan p_talent_plan_config[%d] not found!!", p_hero_config->talent());
		return errcode_enum::notice_unknown;
	}
	talent_ptr p_talent = p_hero->get_talent(talent_id);
	if (NULL != p_talent)
	{
		log_error("role[%lu] hero[%d] p_talent[%d] exist!!", p_role->get_uid(), p_hero->get_tid(), talent_id);
		return errcode_enum::notice_unknown;
	}
	//先找到目标天赋在武将天赋方案中的位置
	int32_t index = -1;
	for (uint32_t i = 0; i < p_talent_plan_config->plan().size(); ++i)
	{
		if (p_talent_plan_config->plan().at(i).first == talent_id)
		{
			index = i;
			break;
		}
	}
	if (-1 == index)
	{
		log_error("HeroTalentPlan p_talent_plan_config[%d] not exist talent[%d]!!", p_hero_config->talent(), talent_id);
		return errcode_enum::notice_unknown;
	}
	//查找对应位置的前置条件
	HeroTalentPos *p_talent_pos_config = GET_CONF(HeroTalentPos, index+1);
	if (NULL == p_talent_pos_config)
	{
		log_error("HeroTalentPos p_talent_pos_config[%d] not found!!", index + 1);
		return errcode_enum::notice_unknown;
	}
	for (auto it : p_talent_pos_config->cond())
	{
		uint32_t pos = it.first;
		uint32_t level = it.second;
		if (0 == pos || pos > p_talent_plan_config->plan().size())
		{
			log_error("HeroTalentPos p_talent_pos_config[%d] invalid, cond pos[%d] invalid!!", index + 1, pos);
			return errcode_enum::notice_unknown;
		}
		uint32_t target_talent_id = p_talent_plan_config->plan().at(pos - 1).first;
		talent_ptr p_target_talent = p_hero->get_talent(target_talent_id);
		if (NULL == p_target_talent)
		{
			log_error("role[%lu] hero[%d] cond p_target_talent[%d] not exist!!", p_role->get_uid(), p_hero->get_tid(), target_talent_id);
			return errcode_enum::notice_unknown;
		}
		if (p_target_talent->get_level() < level)
		{
			log_error("role[%lu] hero[%d] cond p_talent[%d] level[%d] not enough, need[%d]!!", p_role->get_uid(), 
				p_hero->get_tid(), target_talent_id, p_target_talent->get_level(), level);
			return errcode_enum::notice_unknown;
		}
	}
	p_talent = p_hero->add_talent(talent_id, 0);
	p_hero->save_self(p_role->get_uid());
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] hero[%d] active_talent[%d] success", p_role->get_uid(), p_hero->get_tid(), talent_id);
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_active_talent);
	return errcode_enum::error_ok;
}


uint32_t cultivate_manager_t::levelup_talent(role_ptr p_role, hero_ptr p_hero, uint32_t talent_id, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] levelup_talent begin", p_role->get_uid());
	Hero *p_hero_config = GET_CONF(Hero, p_hero->get_tid());
	if (NULL == p_hero_config)
	{
		log_error("Hero p_hero_config[%d] not found!!", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	HeroTalentPlan *p_talent_plan_config = GET_CONF(HeroTalentPlan, p_hero_config->talent());
	if (NULL == p_talent_plan_config)
	{
		log_error("HeroTalentPlan p_talent_plan_config[%d] not found!!", p_hero_config->talent());
		return errcode_enum::notice_unknown;
	}
	//先找到目标天赋在武将天赋方案中的位置
	int32_t index = -1;
	uint32_t limit_level = 0;
	for (uint32_t i = 0; i < p_talent_plan_config->plan().size(); ++i)
	{
		if (p_talent_plan_config->plan().at(i).first == talent_id)
		{
			index = i;
			limit_level = p_talent_plan_config->plan().at(i).second;
			break;
		}
	}
	if (-1 == index)
	{
		log_error("HeroTalentPlan p_talent_plan_config[%d] not exist talent[%d]!!", p_hero_config->talent(), talent_id);
		return errcode_enum::notice_unknown;
	}
	talent_ptr p_talent = p_hero->get_talent(talent_id);
	if (NULL == p_talent)
	{
		//查找对应位置的前置条件
		HeroTalentPos *p_talent_pos_config = GET_CONF(HeroTalentPos, index + 1);
		if (NULL == p_talent_pos_config)
		{
			log_error("HeroTalentPos p_talent_pos_config[%d] not found!!", index + 1);
			return errcode_enum::notice_unknown;
		}
		for (auto it : p_talent_pos_config->cond())
		{
			uint32_t pos = it.first;
			uint32_t level = it.second;
			if (0 == pos || pos > p_talent_plan_config->plan().size())
			{
				log_error("HeroTalentPos p_talent_pos_config[%d] invalid, cond pos[%d] invalid!!", index + 1, pos);
				return errcode_enum::notice_unknown;
			}
			uint32_t target_talent_id = p_talent_plan_config->plan().at(pos - 1).first;
			talent_ptr p_target_talent = p_hero->get_talent(target_talent_id);
			if (NULL == p_target_talent)
			{
				log_error("role[%lu] hero[%d] cond p_target_talent[%d] not exist!!", p_role->get_uid(), p_hero->get_tid(), target_talent_id);
				return errcode_enum::notice_unknown;
			}
			if (p_target_talent->get_level() < level)
			{
				log_error("role[%lu] hero[%d] cond p_talent[%d] level[%d] not enough, need[%d]!!", p_role->get_uid(),
					p_hero->get_tid(), target_talent_id, p_target_talent->get_level(), level);
				return errcode_enum::notice_unknown;
			}
		}
		p_talent = p_hero->add_talent(talent_id, 0);
	}
	if (NULL == p_talent)
	{
		log_error("NULL == p_talent");
		return errcode_enum::notice_unknown;
	}
	uint32_t talent_level = p_talent->get_level();
	if (talent_level >= limit_level)
	{
		log_error("role[%lu] hero[%d] cond p_talent[%d] level[%d] max!!", p_role->get_uid(),
			p_hero->get_tid(), talent_id, talent_level);
		return errcode_enum::notice_unknown;
	}
	auto p_talent_level_config = GET_CONF(HeroTalentLevel, hash_util_t::hash_to_uint32(talent_id, talent_level));
	if (NULL == p_talent_level_config)
	{
		log_error("p_talent_level_config[%d:%d] not found!!", talent_id, talent_level);
		return errcode_enum::notice_unknown;
	}
	if (p_hero->get_current_level() < p_talent_level_config->need_level())
	{
		log_error("hero level[%d] not enough, need[%d]!!", p_hero->get_current_level(), p_talent_level_config->need_level());
		return errcode_enum::notice_hero_levle_not_enough;
	}
	
	uint32_t talent_count = p_hero->get_talent_count();
	if (talent_count < p_talent_level_config->consume_talent_point())
	{
		log_error("talent_count[%d] not enough, need[%d]!!", talent_count, p_talent_level_config->consume_talent_point());
		return errcode_enum::notice_talentup_tips4;
	}
	
	p_talent->set_level(talent_level + 1);
	p_hero->set_talent_use(p_hero->get_talent_use() + p_talent_level_config->consume_talent_point());
	p_hero->set_talent_count(talent_count - p_talent_level_config->consume_talent_point());
	p_hero->save_self(p_role->get_uid());
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] hero[%d] levelup_talent[%d] success,talent_level from[%d] to[%d]", p_role->get_uid(), p_hero->get_tid(), talent_id, 0, 1);
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_levelup_talent);

	//成就通知
	achieve_manager_t::notify_achieve_state(p_role->get_uid(), proto::common::Achieve_Event_Type::ACHIEVE_HERO_NUMBER_TALENT_LEVEL, p_talent->get_level());

	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::reset_talent(role_ptr p_role, hero_ptr p_hero, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] reset_talent begin", p_role->get_uid());

	if (p_role->get_level() > get_reset_talent_free_level())
	{
		std::pair<uint32_t, uint32_t> reset_cost;
		get_reset_talent_cost(reset_cost);
		if (!money_manager_t::use_money(p_role, (proto::common::MONEY_TYPE)reset_cost.first, reset_cost.second, log_enum::source_type_hero_reset_talent, p_hero->get_tid()))
		{
			log_error("hero[%d] can't reset_talent! gold not enough", p_hero->get_tid());
			return errcode_enum::notice_gold_money_not_enough;
		}
	}
	uint32_t talent_count = p_hero->get_talent_count();
	uint32_t talent_use = p_hero->get_talent_use();
	p_hero->set_talent_count(talent_count + talent_use);
	p_hero->reset_talent();
	p_hero->set_talent_use(0);
	p_hero->save_self(p_role->get_uid());
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] hero[%d] reset_talent success", p_role->get_uid(), p_hero->get_tid());
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_reset_talent);
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::aware_talent(role_ptr p_role, hero_ptr p_hero, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] aware_talent begin", p_role->get_uid())
	uint32_t talent_level = p_hero->get_talent_level();
	uint32_t talent_degree = p_hero->get_talent_degree();
	uint32_t talent_count = p_hero->get_talent_count();
	HeroTalentAdd *p_talent_add = GET_CONF(HeroTalentAdd, talent_level);
	if (NULL == p_talent_add)
	{
		log_error("HeroTalentAdd p_talent_add[%d] not found!!", talent_level);
		return errcode_enum::notice_unknown;
	}
	if (talent_degree >= p_talent_add->degree())
	{
		//升级
		HeroTalentAdd *p_next_talent_add = GET_CONF(HeroTalentAdd, talent_level+1);
		if (NULL == p_next_talent_add)
		{
			log_error("HeroTalentAdd p_next_talent_add[%d] not found!!", talent_level + 1);
			return errcode_enum::notice_unknown;
		}
		uint32_t reply_code = item_manager_t::remove_items(p_role, p_next_talent_add->level_consume(), log_enum::source_type_hero_talentadd, p_hero->get_tid(), p_data);
		if (reply_code != errcode_enum::error_ok)
		{
			log_error("add_talent item not enough!!");
			return errcode_enum::notice_item_not_enough;
		}
		talent_degree = 0;
		talent_level += 1;
		talent_count += p_next_talent_add->level_award();
	}
	else
	{
		//升段
		uint32_t reply_code = item_manager_t::remove_items(p_role, p_talent_add->degree_consume(), log_enum::source_type_hero_talentadd, p_hero->get_tid(), p_data);
		if (reply_code != errcode_enum::error_ok)
		{
			log_error("add_talent item not enough!!");
			return errcode_enum::notice_item_not_enough;
		}
		talent_degree += 1;
		talent_count += p_talent_add->degree_award();
	}
	
	p_hero->set_talent_count(talent_count);
	p_hero->set_talent_level(talent_level);
	p_hero->set_talent_degree(talent_degree);
	p_hero->save_self(p_role->get_uid());
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] add_talent success", p_role->get_uid());
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_talentadd);
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::smelt_hero(role_ptr p_role, hero_ptr p_hero, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] smelt_hero begin", p_role->get_uid());
	if (p_hero->is_role())
	{
		log_error("role[%lu] smelt_hero[%lu] is role!!", p_role->get_uid(), p_hero->get_unique_id());
		return errcode_enum::notice_unknown;
	}
	Hero *p_hero_config = GET_CONF(Hero, p_hero->get_tid());
	if (NULL == p_hero_config)
	{
		log_error("Hero p_hero_config[%d] not found!!", p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	auto smelt_hero_level = GET_CONF(Comprehensive, comprehensive_common::hero_reborn_level);
	uint32_t need_level = GET_COMPREHENSIVE_VALUE_1(smelt_hero_level);
	if (p_role->get_level() < need_level)
	{
		log_error("role[%lu] smelt_hero level[%d] not enough, need[%d]", p_role->get_uid(), p_role->get_level(), need_level);
		return errcode_enum::notice_role_levle_not_enough;
	}
	if (!p_hero->can_reset())
	{
		log_error("role[%lu] smelt_hero[%lu] failed, hero cannot smelt", p_role->get_uid(), p_hero->get_unique_id());
		return errcode_enum::notice_unknown;
	}
	auto smelt_consume = GET_CONF(Comprehensive, comprehensive_common::hero_reborn_item_id);
	uint32_t smelt_consume_item = GET_COMPREHENSIVE_VALUE_1(smelt_consume);
	if (errcode_enum::error_ok != item_manager_t::remove_item(p_role, smelt_consume_item, 1, log_enum::source_type_hero_smelt, p_hero->get_tid(), p_data))
	{
		log_error("role[%lu] smelt_hero[%lu] failed, smelt_consume_item not enough", p_role->get_uid(), p_hero->get_unique_id());
		return errcode_enum::notice_item_not_enough;
	}

	std::map<uint32_t, uint32_t> item_id_count;
	//经验回收
	uint32_t exp = p_hero->get_current_exp();
	for (uint32_t i = 1; i < p_hero->get_current_level(); ++i)
	{
		auto p_level_demad = GET_CONF(LevelDemad, hash_util_t::hash_to_uint32(p_hero_config->level_curve(), i));
		if (NULL == p_level_demad)
		{
			log_error("LevelDemad [%d:%d] not found", p_hero_config->level_curve(), i);
			break;
		}
		exp += p_level_demad->exp();
	}
	log_warn("exp[%d]", exp);
	std::map<uint32_t, uint32_t>::reverse_iterator it = levelup_item.rbegin();
	for (; it != levelup_item.rend(); ++it)
	{
		uint32_t item_id = it->first;
		uint32_t add_exp = it->second;
		uint32_t add_num = exp / add_exp;
		exp = exp % add_exp;
		if (exp > 0 && exp < 100 && add_exp == 100)
		{
			add_num += 1;
		}
		if (add_num > 0)
		{
			item_id_count[item_id] += add_num;
		}
	}

	//升星回收
	for (uint32_t i = p_hero_config->star(); i < p_hero->get_star(); ++i)
	{
		auto p_star_config = GET_CONF(HeroStar, hash_util_t::hash_to_uint32(p_hero->get_tid(), i));
		if (NULL == p_star_config)
		{
			log_error("HeroStar[%d:%d] not found!!", p_hero->get_tid(), i);
			break;
		}
		money_manager_t::add_money(p_role, proto::common::MONEY_TYPE_COPPER, p_star_config->consume_money(), log_enum::source_type_hero_smelt, p_hero->get_tid());
		money_manager_t::add_money(p_role, proto::common::MONEY_TYPE_HEROSOUL, p_star_config->consume_herosoul(), log_enum::source_type_hero_smelt, p_hero->get_tid());
		item_id_count[p_star_config->consume_material().first] += p_star_config->consume_material().second;
	}

	//升阶回收
	for (uint32_t i = 0; i < p_hero->get_grade(); ++i)
	{
		auto p_grade_config = GET_CONF(HeroGrade, hash_util_t::hash_to_uint32(p_hero->get_tid(), i));
		if (NULL == p_grade_config)
		{
			log_error("HeroGrade[%d:%d] not found!!", p_hero->get_tid(), i);
			break;
		}
		money_manager_t::add_money(p_role, proto::common::MONEY_TYPE_COPPER, p_grade_config->consume_money(), log_enum::source_type_hero_smelt, p_hero->get_tid());
		for (auto it : p_grade_config->consume_material())
		{
			item_id_count[it.first] += it.second;
		}
	}

	//觉醒回收
	if (p_hero->get_wakeup() > 0)
	{
		money_manager_t::add_money(p_role, proto::common::MONEY_TYPE_COPPER, p_hero_config->wakeup_consume_money(), log_enum::source_type_hero_smelt, p_hero->get_tid());
		for (auto it : p_hero_config->wakeup_consume_material())
		{
			item_id_count[it.first] += it.second;
		}
	}

	//技能回收
	const HeroSkillMap& hsm = p_hero->get_skill_map();
	for (auto it : hsm)
	{
		uint32_t skill_id = it.first;
		uint32_t skill_level = it.second.skill_level;
		for (uint32_t i = 1; i < skill_level; i++)
		{
			auto p_skill_effect_config = GET_CONF(SkillEffectTable, hash_util_t::hash_to_uint32_move_7(skill_id, i));
			if (NULL == p_skill_effect_config)
			{
				log_error("p_skill_effect_config[%d:%d] not found!!", skill_id, i);
				break;
			}
			money_manager_t::add_money(p_role, proto::common::MONEY_TYPE_COPPER, p_skill_effect_config->levelup_money(), log_enum::source_type_hero_smelt, p_hero->get_tid());
			money_manager_t::add_money(p_role, proto::common::MONEY_TYPE_HEROSOUL, p_skill_effect_config->levelup_herosoul(), log_enum::source_type_hero_smelt, p_hero->get_tid());
			item_id_count[p_skill_effect_config->levelup_consume().first] += p_skill_effect_config->levelup_consume().second;
		}
	}

	//天赋觉悟
	if (p_hero->get_talent_degree() > 0)
	{
		HeroTalentAdd *p_talent_add = GET_CONF(HeroTalentAdd, p_hero->get_talent_level());
		if (NULL == p_talent_add)
		{
			log_error("HeroTalentAdd p_talent_add[%d] not found!!", p_hero->get_talent_level());
			return errcode_enum::notice_unknown;
		}
		for (uint32_t i = 0; i < p_hero->get_talent_degree(); ++i)
		{
			for (auto it : p_talent_add->degree_consume())
			{
				item_id_count[it.first] += it.second;
			}
		}
	}
	
	for (uint32_t i = 1; i < p_hero->get_talent_level(); ++i)
	{
		HeroTalentAdd *p_talent_add = GET_CONF(HeroTalentAdd, i);
		if (NULL == p_talent_add)
		{
			log_error("HeroTalentAdd p_talent_add[%d] not found!!", i);
			return errcode_enum::notice_unknown;
		}
		HeroTalentAdd *p_next_talent_add = GET_CONF(HeroTalentAdd, i + 1);
		if (NULL == p_next_talent_add)
		{
			log_error("HeroTalentAdd p_next_talent_add[%d] not found!!", i + 1);
			return errcode_enum::notice_unknown;
		}
		for (uint32_t j = 0; j < p_talent_add->degree(); ++j)
		{
			for (auto it : p_talent_add->degree_consume())
			{
				item_id_count[it.first] += it.second;
			}
		}
		for (auto it : p_next_talent_add->level_consume())
		{
			item_id_count[it.first] += it.second;
		}
	}
	uint32_t reply_code = errcode_enum::error_ok;
	if (item_manager_t::check_add_items(p_role, item_id_count))
	{
		item_manager_t::add_items(p_role, item_id_count, log_enum::source_type_hero_smelt, p_hero->get_tid(), p_data);
	}
	else
	{
		reply_code = errcode_enum::task_bag_full_mail;
		mail_manager_t::send_mail(p_role->get_uid(), proto::common::MAIL_TYPE_SYS, mailcode_enum::sys_mail_collect,
			item_id_count, proto::common::MAIL_GET_TYPE_SYS);
	}
	//天赋回收
	reset_talent(p_role, p_hero, p_data);
	//武将重置
	p_hero->reset();

	p_hero->save_self(p_role->get_uid());
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	CULTI_LOG("role[%lu] smelt_hero success", p_role->get_uid());
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_smelt);
	return reply_code;
}

uint32_t cultivate_manager_t::famous_hero(role_ptr p_role, hero_ptr p_hero, uint32_t famous_id, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_hero)
	{
		log_error("NULL == p_hero");
		return errcode_enum::notice_hero_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	CULTI_LOG("role[%lu] add_famous begin", p_role->get_uid());
	HeroFamous* p_conf = GET_CONF(HeroFamous, famous_id);
	if (NULL == p_conf)
	{
		log_error("NULL == p_conf HeroFamous[%d]", famous_id);
		return errcode_enum::notice_unknown;
	}
	if (p_conf->hero_id() != p_hero->get_tid())
	{
		log_error("HeroFamous[%d] not match hero[%d]", famous_id, p_hero->get_tid());
		return errcode_enum::notice_unknown;
	}
	for (auto need_hero : p_conf->need_hero())
	{
		if (NULL == hero_manager_t::get_hero(p_role, need_hero))
		{
			log_error("HeroFamous[%d] need_hero[%d] not exist", famous_id, need_hero);
			return errcode_enum::notice_unknown;
		}
	}
	p_hero->add_famous(famous_id);
	p_hero->save_self(p_role->get_uid());
	CULTI_LOG("role[%lu] add_famous success", p_role->get_uid());
	log_wrapper_t::send_hero_log(p_role->get_uid(), p_role->get_level(), p_hero->get_unique_id(), p_hero->get_tid(), log_enum::opt_type_set, log_enum::source_type_hero_talentadd);
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::recruit_hero(role_ptr p_role, uint32_t hero_tid, proto::common::role_change_data* p_data)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	if (NULL == p_data)
	{
		log_error("NULL == p_data");
		return errcode_enum::notice_unknown;
	}
	if (NULL != hero_manager_t::get_hero(p_role, hero_tid))
	{
		log_error("role[%lu] hero[%d] can't recruit! hero already exist", p_role->get_uid(), hero_tid);
		return errcode_enum::notice_hero_repeat;
	}
	auto p_hero_conf = GET_CONF(Hero, hero_tid);
	if (NULL == p_hero_conf)
	{
		log_error("hero[%d] can't recruit! p_hero_conf not found", hero_tid);
		return errcode_enum::notice_unknown;
	}
	
	if (errcode_enum::error_ok != item_manager_t::remove_item(p_role, p_hero_conf->material_id(), p_hero_conf->compose_count(), log_enum::source_type_hero_recruit, hero_tid, p_data))
	{
		log_error("role[%lu] hero[%d] can't recruit! hire_item[%d] not enough", p_role->get_uid(), hero_tid, p_hero_conf->material_id());
		return errcode_enum::notice_item_not_enough;
	}
	hero_manager_t::add_hero(p_role, hero_tid, log_enum::source_type_hero_recruit, p_data);
	auto p_task_mgr = p_role->get_task_mgr();
	if (NULL != p_task_mgr)
	{
		p_task_mgr->try_change_task_state(TASK_TARGET_TYPE_RECRUIT, *p_data, hero_tid, 1);
	}
	proto::common::personal_info *p_info = p_data->mutable_per_info();
	p_role->get_personal_info(p_info);
	return errcode_enum::error_ok;
}

uint32_t cultivate_manager_t::change_name(role_ptr p_role, uint64_t hero_uid, const std::string& name)
{
	if (NULL == p_role)
	{
		log_error("NULL == p_role");
		return errcode_enum::notice_role_null;
	}
	auto change_name_level = GET_CONF(Comprehensive, comprehensive_common::role_generals_change_name_level);
	uint32_t need_level = GET_COMPREHENSIVE_VALUE_1(change_name_level);
	if (p_role->get_level() < need_level)
	{
		log_error("role[%lu] level[%d] not enough, need[%d]", p_role->get_uid(), p_role->get_level(), need_level);
		return errcode_enum::error_level_not_enough;
	}
	hero_ptr p_hero = hero_manager_t::get_hero_by_unique_id(p_role, hero_uid);
	if (NULL == p_hero)
	{
		log_error("role[%lu] NULL == p_hero[%lu]", p_role->get_uid(), hero_uid);
		return errcode_enum::notice_hero_null;
	}
	if (p_hero->get_nick_name() == name)
	{
		log_error("role[%lu] p_hero[%lu] has same nick_name", p_role->get_uid(), hero_uid);
		return errcode_enum::notice_unknown;
	}
	// 检查特殊字符
	if (!common::string_util_t::is_no_special_char(name))
	{
		log_error("nickname[%s] has special char!", name.c_str());
		return errcode_enum::sys_notice_not_chinese_word;
	}

	uint32_t name_size = common::string_util_t::get_char_size(name);

	if (name_size > 3)
	{
		log_error("nickname[%s] length[%d] error!", name.c_str(), name_size);
		return errcode_enum::role_change_name_error;
	}

	p_hero->set_nick_name(name);
	return errcode_enum::error_ok;
}

void cultivate_manager_t::get_unrecruit_hero(role_ptr p_role, std::vector<uint32_t>& tids)
{
	std::map<uint32_t, HeroGet*> hero_get_map;
	GET_ALL_CONF(HeroGet, hero_get_map);
	for (auto recruit_conf : hero_get_map)
	{
		auto conf = recruit_conf.second;
        if (NULL == conf)
        {
            continue;
        }
		hero_ptr p_hero = hero_manager_t::get_hero(p_role, conf->id());
		if (p_hero != NULL) // 已拥有
		{
			continue;
		}

		tids.push_back(conf->id());
	}
}

uint32_t cultivate_manager_t::get_reset_talent_free_level()
{
	auto reset_talent_free_level = GET_CONF(Comprehensive, comprehensive_common::hero_talent_reset_lvl);
	uint32_t val = GET_COMPREHENSIVE_VALUE_1(reset_talent_free_level);
	return val;
}

void cultivate_manager_t::get_reset_talent_cost(std::pair<uint32_t, uint32_t>& rtc)
{
	auto reset_talent_cost = GET_CONF(Comprehensive, comprehensive_common::hero_talent_reset_cost);
	if (NULL == reset_talent_cost)
	{
		log_error("Comprehensive[%d] not found", comprehensive_common::hero_talent_reset_cost);
		return;
	}
	if (!reset_talent_cost->parameter1().empty())
	{
		Dawn::parseTuple(rtc, reset_talent_cost->parameter1().c_str(), ":");
	}
}

uint32_t cultivate_manager_t::get_limit_level_by_grade(uint32_t grade)
{
	uint32_t level = 0;
	for (auto it : grade_level)
	{
		if (grade >= it.first && it.second > level)
		{
			level = it.second;
		}
	}
	return level;
}
