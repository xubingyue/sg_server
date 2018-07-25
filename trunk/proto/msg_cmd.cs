namespace msg_cmd
{
	public enum cmd
	{
		// ------------------------client -> login------------------------
		cl_check_version_request = 101,
		cl_login_request = 102,

		// ------------------------login -> client------------------------
		lc_check_version_reply = 401,
		lc_login_reply = 402,
		lc_kick_role_notify = 403,
		lc_login_queue_notify = 404,

		// ------------------------client -> gate------------------------
		ca_connect_request = 501,
		ca_pingpong_request = 502,
		ca_logout_request = 503,
		ca_lock_notify = 504,
		ca_unlock_notify = 505,
		ca_login_game_request = 506,
		ca_create_role_request = 507,
		ca_frames_check_request = 508,

		// ------------------------gate -> client------------------------
		ac_kick_role_notify = 601,
		ac_pingpong_reply = 602,
		ac_connect_reply = 603,
		ac_logout_reply = 604,
		ac_masked_msg_notify = 605,
		ac_login_game_reply = 606,
		ac_create_role_reply = 607,
		ac_frames_check_reply = 608,

		// ------------------------client -> game------------------------
		cg_gm_cmd_request = 701,
		cg_jump_reading_start_notify = 702,
		cg_add_hero_request = 703,
		cg_change_nickname_request = 704,
		cg_jump_reading_break_notify = 705,
		cg_use_item_request = 706,
		cg_change_sys_state_notify = 707,
		cg_enter_scene_request = 708,
		cg_jump_scene_request = 709,
		cg_update_formation_request = 710,
		cg_get_build_copper_request = 711,
		cg_upgrade_interior_build_request = 712,
		cg_dispatch_task_request = 713,
		cg_refresh_task_request = 714,
		cg_upgrade_task_star_level_request = 715,
		cg_get_interior_reward_request = 716,
		cg_complete_interior_task_request = 717,
		cg_get_offline_reward_request = 718,
		cg_instant_battle_request = 719,
		cg_hero_cultivate_request = 720,
		cg_hero_recruit_request = 721,
		cg_enter_fight_request = 722,
		cg_sell_bag_item_request = 723,
		cg_accept_task_request = 724,
		cg_commit_task_request = 725,
		cg_drop_task_request = 726,
		cg_create_family_request = 727,
		cg_start_collect_request = 728,
		cg_end_collect_request = 729,
		cg_fight_update_formation_request = 730,
		cg_fight_update_cur_form_id_request = 731,
		cg_combat_mark_target_notify = 732,
		cg_combat_speak_notify = 733,
		cg_combat_ask_escape_req = 734,
		cg_change_name_request = 735,
		cg_combat_recovery_ask_reply = 736,
		cg_role_main_hero_change_request = 737,
		cg_career_award_request = 738,
		cg_troop_jump_end_request = 739,
		cg_get_fight_formation_req = 740,
		cg_change_pk_mode_request = 741,
		cg_cancel_collect_request = 742,
		cg_expedition_data_request = 743,
		cg_expedition_fight_request = 744,
		cg_expedition_refresh_request = 745,
		cg_expedition_help_request = 746,
		cg_expedition_shop_request = 747,
		cg_equip_strengthen_request = 748,
		cg_equip_smelt_box_request = 749,
		cg_equip_smelt_request = 750,
		cg_equip_exchange_request = 751,
		cg_equip_on_request = 752,
		cg_equip_off_request = 753,
		cg_equip_remake_attr_request = 754,
		cg_equip_smelt_data_request = 755,
		cg_equip_remake_exattr_request = 756,
		cg_equip_replace_exattr_request = 757,
		cg_get_family_list_request = 758,
		cg_get_family_info_request = 759,
		cg_help_task_request = 760,
		cg_get_family_member_list_request = 761,
		cg_cancel_join_family_request = 762,
		cg_redbag_send_request = 763,
		cg_new_role_combat_notify = 764,
		cg_expedition_award_request = 765,
		cg_expedition_box_request = 766,
		cg_hero_change_name_request = 767,
		cg_task_refresh_shilian_request = 768,
		cg_get_fight_special_heroes_request = 769,
		cg_patrol_request = 770,
		cg_watch_combat_request = 771,
		cg_cancel_watch_combat_request = 772,
		cg_offline_arena_buy_request = 773,
		cg_field_boss_attack_request = 774,
		cg_role_main_hero_unlock_request = 775,
		cg_kill_task_monster_request = 776,
		cg_get_level_reward_request = 777,
		cg_activity_shop_get_info_request = 778,
		cg_activity_shop_buy_request = 779,
		cg_title_change_request = 780,
		cg_recharge_total_award_request = 781,
		cg_family_skill_data_request = 782,
		cg_family_skill_levelup_request = 783,
		cg_recharge_total_data_request = 784,
		cg_move_request = 785,
		cg_equip_soul_request = 786,
		cg_server_time_request = 787,
		cg_equip_add_remake_count_request = 788,
		cg_liandan_data_request = 789,
		cg_liandan_unlock_request = 790,
		cg_liandan_doing_request = 791,
		cg_liandan_return_request = 792,
		cg_liandan_done_request = 793,
		cg_equip_plan_data_request = 794,
		cg_equip_plan_create_request = 795,
		cg_equip_plan_modify_request = 796,
		cg_equip_plan_delete_request = 797,
		cg_equip_plan_use_request = 798,
		cg_recharge_cheap_request = 799,
		cg_recharge_cheap_buy_request = 800,
		cg_trade_buy_item_request = 801,
		cg_trade_sell_item_request = 802,
		cg_get_city_trade_shop_request = 803,
		cg_finish_fight_request = 804,
		cg_impeach_family_general_request = 805,
		cg_family_shop_buy_request = 806,
		cg_handbook_award_request = 807,
		cg_task_event_award_request = 808,
		__cg_refresh_troop_list_request = 809,
		__cg_modify_troop_request = 810,
		__cg_transfer_troop_leader_request = 811,
		cg_get_family_activities_request = 812,
		cg_office_data_request = 813,
		__cg_office_levelup_request = 814,
		cg_office_award_request = 815,
		__cg_kick_family_member_request = 816,
		cg_use_mount_request = 817,
		cg_turn_mount_request = 818,
		cg_update_cur_form_id_request = 819,
		cg_combat_loading_end_ntf = 820,
		cg_combat_form_request = 821,
		cg_combat_play_end_ntf = 822,
		cg_country_bounty_data_request = 823,
		cg_country_bounty_accept_request = 824,
		cg_combat_before_form_ready_request = 825,
		cg_country_bounty_refresh_request = 826,
		cg_country_bounty_box_request = 827,
		cg_trade_supplement_request = 828,
		cg_trade_event_request = 829,
		cg_field_boss_request = 830,
		cg_combat_escape_ntf = 831,
		cg_exchange_money_request = 832,
		cg_fight_study_request = 833,
		cg_fight_study_cancel_notify = 834,
		cg_fight_study_answer_request = 835,
		cg_combat_auto_fight_request = 836,
		cg_activity_data_request = 837,
		cg_liveness_box_request = 838,
		cg_arena_join_request = 839,
		cg_arena_match_request = 840,
		cg_treasure_data_request = 841,
		cg_treasure_drop_request = 842,
		cg_treasure_gather_request = 843,
		cg_arena_buy_ticket_request = 844,
		cg_pk_request = 845,
		cg_challenge_request = 846,
		cg_challenge_process_request = 847,
		cg_get_arena_rank_data_request = 848,
		cg_troop_create_request = 849,
		cg_troop_back_request = 850,
		cg_troop_join_request = 851,
		cg_troop_auto_match_request = 852,
		cg_gold_luckydraw_data_request = 853,
		cg_gold_luckydraw_award_request = 854,
		__cg_troop_invite_join_request = 855,
		cg_troop_process_invite_request = 856,
		__cg_troop_auto_join_flag_request = 857,
		cg_arena_cancel_match_request = 858,
		__cg_troop_quit_request = 859,
		cg_arena_self_rank_request = 860,
		cg_tower_trigger_fight_request = 861,
		cg_leave_arena_request = 862,
		cg_dungeon_buy_request = 863,
		cg_dungeon_times_request = 864,
		__cg_troop_transfer_leader_request = 865,
		cg_king_war_jump_request = 866,
		cg_king_war_rank_list_request = 867,
		cg_enter_king_war_scene_request = 868,
		cg_king_war_attack_start_request = 869,
		cg_king_war_attack_end_request = 870,
		cg_king_war_defence_request = 871,
		cg_object_revive_request = 872,
		cg_ask_king_war_fight_request = 873,
		cg_king_war_attack_end_notify = 874,
		cg_buy_goods_request = 875,
		__cg_ask_king_war_result_request = 876,
		cg_get_achieve_infolist_request = 877,
		cg_get_achieve_record_request = 878,
		cg_get_achieve_reward_request = 879,
		cg_world_cup_play_request = 880,
		cg_tower_data_request = 881,
		cg_tower_fight_request = 882,
		cg_tower_auto_fight_request = 883,
		cg_tower_auto_fight_immediately_request = 884,
		cg_tower_auto_fight_reward_request = 885,
		cg_tower_reset_request = 886,
		cg_tower_achieve_reward_request = 887,
		cg_world_cup_bet_request = 888,
		cg_world_cup_bet_reward_request = 889,
		cg_red_point_request = 890,
		cg_activate_life_star_request = 891,
		cg_break_life_state_request = 892,
		cg_finish_new_role_guide_notify = 893,
		cg_luckydraw_request = 894,
		cg_role_dungeon_info_request = 895,
		cg_open_dungeon_request = 896,
		cg_open_dugeon_team_check_reply = 897,
		cg_ask_team_check_reuqest = 898,
		cg_dungeon_leave_request = 899,
		cg_dungeon_fight_again_request = 900,
		cg_change_hero_plugin_request = 901,
		cg_goods_buy_request = 902,
		cg_goods_sell_request = 903,
		cg_goods_return_request = 904,
		cg_goods_resell_request = 905,
		cg_goods_profit_request = 906,
		cg_section_request = 907,
		cg_section_reward_request = 908,
		cg_troop_trade_request = 909,
		cg_family_war_member_request = 910,
		cg_family_war_fight_data_request = 911,
		cg_recharge_request = 912,
		cg_active_reward_list_request = 913,
		cg_leave_family_war_request = 914,
		cg_ask_enter_battlefield_requet = 915,
		cg_ask_formations_info_request = 916,
		cg_formations_hero_update_request = 917,
		cg_formations_hero_revive_request = 918,
		cg_long_hurt_info_request = 919,
		cg_family_war_attack_long_request = 920,
		cg_family_war_result_info_request = 921,
		__cg_formations_hero_down_request = 922,
		cg_random_shop_info_request = 923,
		cg_random_shop_buy_request = 924,
		cg_random_shop_refresh_request = 925,
		cg_enter_arena_request = 926,
		cg_section_pass_pve_request = 927,
		cg_family_prayer_request = 928,
		cg_family_prayer_gift_request = 929,
		cg_change_multi_state_request = 930,
		cg_dungeon_event_request = 931,
		cg_get_active_reward_request = 932,
		cg_recharge_reward_request = 933,
		cg_luckydraw_data_request = 934,
		cg_merage_item_request = 935,
		cg_set_gm_level = 936,
		cg_sell_hero_chip_request = 937,
		cg_buy_vigour_request = 938,
		cg_task_quick_data_request = 939,
		cg_task_quick_complete_request = 940,
		cg_quick_fight_elite_page_request = 941,
		cg_reset_quick_fight_elite_page_request = 942,
		cg_get_money_tree_request = 943,
		cg_shake_money_tree_request = 944,
		cg_levelup_money_tree_request = 945,
		cg_get_7d_login_request = 946,
		cg_get_7d_login_prize_request = 947,
		cg_up_level_lifelabel_request = 948,
		cg_replace_head_request = 949,
		cg_head_frame_list_request = 950,
		cg_use_multiple_chosen_item_request = 951,
		cg_get_month_card_info_request = 952,
		cg_buy_month_card_request = 953,
		cg_get_month_card_prize_request = 954,
		cg_auto_buy_task_item_request = 955,
		cg_auto_complete_task_request = 956,
		cg_get_level_fund_info_request = 957,
		cg_get_level_fund_prize_request = 958,
		cg_buy_level_fund_request = 959,
		cg_get_exchange_info_request = 960,
		cg_get_exchange_prize_request = 961,
		cg_get_limit_buy_info_request = 962,
		cg_buy_limit_request = 963,
		cg_get_sd_target_info_request = 964,
		cg_get_sd_target_red_request = 965,
		cg_get_sd_target_prize_request = 966,
		cg_patrol_hire_info_request = 967,
		cg_get_patrol_hire_rwd_request = 968,
		cg_fast_patrol_hire_request = 969,
		cg_change_patrol_hire_request = 970,
		cg_get_general_event_info_request = 971,
		cg_get_general_event_detail_request = 972,
		cg_get_general_event_prize_request = 973,
		cg_get_server_level_limit_request = 974,
		cg_ignore_lineup_flag_request = 975,

		// ------------------------client -> account------------------------
		cn_server_info_request = 1501,

		// ------------------------account -> client------------------------
		nc_server_info_reply = 1601,

		// ------------------------game -> client------------------------
		gc_gm_cmd_reply = 1701,
		gc_common_error_notify = 1702,
		gc_career_award_reply = 1703,
		gc_change_nickname_reply = 1704,
		gc_enter_game_reply = 1705,
		gc_item_changed_notify = 1706,
		gc_use_item_reply = 1707,
		gc_change_sys_state_notify = 1708,
		gc_enter_scene_notify = 1709,
		gc_jump_scene_reply = 1710,
		gc_role_into_vision_notify = 1711,
		gc_role_outo_vision_notify = 1712,
		gc_update_formation_reply = 1713,
		gc_interior_info_notify = 1714,
		gc_get_build_copper_reply = 1715,
		gc_upgrade_interior_build_reply = 1716,
		gc_interior_task_finished_notify = 1717,
		gc_dispatch_task_reply = 1718,
		gc_refresh_task_reply = 1719,
		gc_upgrade_task_star_level_reply = 1720,
		gc_get_interior_reward_reply = 1721,
		gc_complete_interior_task_reply = 1722,
		gc_get_offline_reward_reply = 1723,
		gc_instant_battle_reply = 1724,
		gc_offline_info_notify = 1725,
		gc_hero_cultivate_reply = 1726,
		gc_hero_recruit_reply = 1727,
		gc_hero_info_notify = 1728,
		gc_area_id_notify = 1729,
		gc_enter_fight_reply = 1730,
		gc_role_change_data_notify = 1731,
		gc_update_function_code_ntf = 1732,
		gc_accept_task_reply = 1733,
		gc_sell_bag_item_reply = 1734,
		gc_commit_task_reply = 1735,
		gc_drop_task_reply = 1736,
		gc_task_change_ntf = 1737,
		gc_create_family_reply = 1738,
		gc_start_collect_reply = 1739,
		gc_end_collect_reply = 1740,
		gc_combat_speak_notify = 1741,
		gc_change_name_reply = 1742,
		gc_combat_mark_target_notify = 1743,
		gc_dungeon_buy_reply = 1744,
		gc_hero_change_name_reply = 1745,
		gc_title_change_reply = 1746,
		gc_recharge_total_award_reply = 1747,
		gc_fight_update_formation_reply = 1748,
		gc_fight_update_cur_form_id_reply = 1749,
		gc_combat_escape_ntf = 1750,
		gc_recharge_total_data_reply = 1751,
		gc_role_main_hero_unlock_reply = 1752,
		gc_scene_object_info_notify = 1753,
		gc_troop_formation_ntf = 1754,
		gc_combat_ask_escape_rep = 1755,
		gc_combat_recovery_notify = 1756,
		gc_change_pk_mode_reply = 1757,
		gc_combat_recovery_ask_req = 1758,
		gc_reconnect_combat_result_ntf = 1759,
		gc_get_fight_formation_reply = 1760,
		gc_cancel_collect_reply = 1761,
		gc_expedition_data_reply = 1762,
		gc_expedition_fight_reply = 1763,
		gc_expedition_refresh_reply = 1764,
		gc_expedition_help_reply = 1765,
		gc_expedition_shop_reply = 1766,
		gc_system_hint_notify = 1767,
		gc_equip_exchange_reply = 1768,
		gc_equip_on_reply = 1769,
		gc_equip_off_reply = 1770,
		gc_equip_remake_attr_reply = 1771,
		gc_equip_smelt_data_reply = 1772,
		gc_equip_remake_exattr_reply = 1773,
		gc_equip_replace_exattr_reply = 1774,
		gc_equip_smelt_reply = 1775,
		gc_equip_smelt_box_reply = 1776,
		gc_equip_strengthen_reply = 1777,
		gc_help_task_reply = 1778,
		gc_expedition_award_reply = 1779,
		gc_expedition_box_reply = 1780,
		gc_redbag_send_reply = 1781,
		gc_get_fight_special_heroes_reply = 1782,
		gc_redbag_draw_notify = 1783,
		gc_patrol_reply = 1784,
		gc_patrol_notify = 1785,
		gc_role_main_hero_change_reply = 1786,
		gc_update_all_formation_reply = 1787,
		gc_task_refresh_shilian_reply = 1788,
		gc_watch_combat_reply = 1789,
		gc_cancel_watch_combat_reply = 1790,
		gc_equip_soul_reply = 1791,
		gc_offline_arena_record_award_reply = 1792,
		gc_offline_arena_class_award_notify = 1793,
		gc_offline_arena_buy_reply = 1794,
		gc_luckydraw_data_reply = 1795,
		gc_kill_task_monster_reply = 1796,
		gc_level_reward_info_notify = 1797,
		gc_get_level_reward_reply = 1798,
		gc_jump_reading_start_notify = 1799,
		gc_troop_jump_end_reply = 1800,
		gc_jump_reading_break_notify = 1801,
		gc_change_country_name_reply = 1802,
		gc_modify_year_name_reply = 1803,
		gc_activity_shop_get_info_reply = 1804,
		gc_activity_shop_buy_reply = 1805,
		gc_offline_arena_score_award_reply = 1806,
		gc_batch_move_notify = 1807,
		gc_move_notify = 1808,
		gc_enter_scene_reply = 1809,
		gc_get_availabel_member_for_officer_reply = 1810,
		gc_field_boss_attack_reply = 1811,
		gc_field_boss_reply = 1812,
		gc_liandan_data_reply = 1813,
		gc_liandan_unlock_reply = 1814,
		gc_liandan_doing_reply = 1815,
		gc_liandan_return_reply = 1816,
		gc_liandan_done_reply = 1817,
		gc_equip_plan_data_reply = 1818,
		gc_equip_plan_create_reply = 1819,
		gc_equip_plan_modify_reply = 1820,
		gc_equip_plan_delete_reply = 1821,
		gc_equip_plan_use_reply = 1822,
		gc_offline_arena_sweep_award_notify = 1823,
		gc_server_time_reply = 1824,
		gc_equip_add_remake_count_reply = 1825,
		gc_trade_buy_item_reply = 1826,
		gc_trade_sell_item_reply = 1827,
		gc_get_city_trade_shop_reply = 1828,
		gc_enter_fight_notify = 1829,
		gc_finish_fight_reply = 1830,
		gc_impeach_family_general_reply = 1831,
		gc_family_shop_buy_reply = 1832,
		gc_recharge_cheap_reply = 1833,
		gc_recharge_cheap_buy_reply = 1834,
		gc_office_data_reply = 1835,
		gc_office_levelup_notify = 1836,
		gc_office_award_reply = 1837,
		gc_handbook_award_reply = 1838,
		gc_task_event_data_notify = 1839,
		gc_task_event_award_reply = 1840,
		gc_get_family_activities_reply = 1841,
		__gc_family_activity_change_ntf = 1842,
		gc_kick_user_notify = 1843,
		__gc_do_family_activity_reply = 1844,
		__gc_impeach_status_notify = 1845,
		gc_family_skill_data_reply = 1846,
		gc_family_skill_levelup_reply = 1847,
		__gc_family_assign_reply = 1848,
		__gc_kick_family_member_reply = 1849,
		__gc_family_officer_changed_notify = 1850,
		gc_next_day_notify = 1851,
		gc_activity_done_notify = 1852,
		__gc_family_members_change_notify = 1853,
		__gc_family_notification_change_notify = 1854,
		__gc_family_declaration_change_notify = 1855,
		__gc_family_auto_newbie_status_notify = 1856,
		gc_dungeon_times_reply = 1857,
		gc_combat_loading_end_reply = 1858,
		gc_combat_play_end_reply = 1859,
		gc_combat_before_form_ready_reply = 1860,
		gc_combat_reset_form_notify = 1861,
		gc_use_mount_reply = 1862,
		gc_turn_mount_reply = 1863,
		gc_update_cur_form_id_reply = 1864,
		gc_field_boss_notify = 1865,
		gc_combat_start_loading_ntf = 1866,
		gc_combat_data_ntf = 1867,
		gc_combat_form_reply = 1868,
		gc_combat_result_ntf = 1869,
		gc_country_bounty_data_reply = 1870,
		gc_country_bounty_accept_reply = 1871,
		__gc_country_bounty_drop_reply = 1872,
		gc_country_bounty_refresh_reply = 1873,
		gc_country_bounty_box_reply = 1874,
		gc_trade_supplement_reply = 1875,
		gc_trade_event_reply = 1876,
		gc_country_bounty_finish_ntf = 1877,
		gc_field_boss_pos_info_notify = 1878,
		gc_exchange_money_reply = 1879,
		gc_fight_study_reply = 1880,
		gc_fight_study_notify = 1881,
		gc_fight_study_answer_reply = 1882,
		gc_fight_study_answer_notify = 1883,
		gc_combat_auto_fight_reply = 1884,
		gc_activity_data_reply = 1885,
		gc_liveness_box_reply = 1886,
		gc_arena_join_reply = 1887,
		gc_arena_match_reply = 1888,
		gc_arena_battle_result_notify = 1889,
		gc_mail_get_addenda_reply = 1890,
		gc_treasure_data_reply = 1891,
		gc_treasure_drop_reply = 1892,
		gc_treasure_gather_reply = 1893,
		gc_arena_buy_ticket_reply = 1894,
		gc_sys_init_notice_notify = 1895,
		gc_sys_notice_notify = 1896,
		gc_combat_obj_state_ntf = 1897,
		gc_pk_reply = 1898,
		gc_challenge_reply = 1899,
		gc_challenge_process_reply = 1900,
		gc_get_arena_rank_data_reply = 1901,
		gc_troop_create_reply = 1902,
		gc_troop_back_reply = 1903,
		gc_troop_event_notify = 1904,
		gc_troop_join_reply = 1905,
		gc_tower_trigger_fight_reply = 1906,
		gc_tower_trigger_notify = 1907,
		gc_tower_other_trigger_notify = 1908,
		gc_troop_invite_shadow_reply = 1909,
		gc_gold_luckydraw_data_reply = 1910,
		gc_gold_luckydraw_award_reply = 1911,
		gc_arena_cancel_match_reply = 1912,
		__gc_troop_quit_reply = 1913,
		gc_arena_self_rank_reply = 1914,
		__gc_troop_change_formation_reply = 1915,
		__gc_troop_modify_reply = 1916,
		gc_family_platform_info_notify = 1917,
		gc_king_war_jump_reply = 1918,
		gc_king_war_reward_notify = 1919,
		gc_troop_auto_match_reply = 1920,
		gc_king_war_rank_list_reply = 1921,
		gc_enter_king_war_scene_reply = 1922,
		gc_king_war_scene_start_notify = 1923,
		gc_king_war_icon_notify = 1924,
		gc_king_war_attack_start_reply = 1925,
		gc_king_war_attack_end_reply = 1926,
		gc_king_war_defence_reply = 1927,
		gc_object_hp_change_notify = 1928,
		gc_object_death_notify = 1929,
		gc_object_revive_reply = 1930,
		gc_ask_king_war_fight_reply = 1931,
		gc_role_battle_value_notify = 1932,
		gc_update_long_info_notify = 1933,
		gc_buy_goods_reply = 1934,
		gc_artifact_left_time_notify = 1935,
		__gc_king_war_result_reply = 1936,
		gc_achieve_finish_notify = 1937,
		gc_get_achieve_infolist_reply = 1938,
		gc_get_achieve_record_reply = 1939,
		gc_get_achieve_reward_reply = 1940,
		gc_world_cup_play_reply = 1941,
		gc_tower_data_reply = 1942,
		gc_tower_fight_reply = 1943,
		gc_tower_auto_fight_reply = 1944,
		gc_tower_auto_fight_immediately_reply = 1945,
		gc_tower_auto_fight_reward_reply = 1946,
		gc_tower_reset_reply = 1947,
		gc_tower_achieve_reward_reply = 1948,
		gc_world_cup_bet_reply = 1949,
		gc_world_cup_bet_reward_reply = 1950,
		gc_red_point_notify = 1951,
		gc_update_fighting_notify = 1952,
		gc_activate_life_star_reply = 1953,
		gc_break_life_state_reply = 1954,
		gc_luckydraw_reply = 1955,
		gc_touch_new_role_guide_notify = 1956,
		gc_role_dungeon_info_reply = 1957,
		gc_open_dungeon_reply = 1958,
		gc_dugeon_team_check_request = 1959,
		gc_sync_team_check_notify = 1960,
		gc_ask_team_check_reply = 1961,
		gc_dungeon_schedule_data_notify = 1962,
		gc_notify_dungeon_result_notify = 1963,
		gc_tactic_update_ntf = 1964,
		gc_dungeon_reward_limit_notify = 1965,
		gc_role_buff_update_ntf = 1966,
		gc_dungeon_fight_again_reply = 1967,
		gc_update_npc_code_ntf = 1968,
		gc_object_scene_jump_notify = 1969,
		gc_change_hero_plugin_reply = 1970,
		gc_goods_buy_reply = 1971,
		gc_goods_sell_reply = 1972,
		gc_goods_return_reply = 1973,
		gc_goods_resell_reply = 1974,
		gc_goods_profit_reply = 1975,
		gc_update_collect_code_ntf = 1976,
		gc_trade_info_notify = 1977,
		gc_section_reply = 1978,
		gc_section_reward_reply = 1979,
		gc_troop_trade_notify = 1980,
		gc_ask_formations_info_reply = 1981,
		gc_family_war_member_reply = 1982,
		gc_family_war_fight_info_notify = 1983,
		gc_attack_icon_notify = 1984,
		gc_family_war_fight_data_reply = 1985,
		gc_recharge_reply = 1986,
		gc_active_reward_list_reply = 1987,
		gc_active_reward_finish_notify = 1988,
		gc_ask_enter_battlefield_reply = 1989,
		gc_formations_info_notify = 1990,
		gc_formations_hero_update_reply = 1991,
		gc_formations_hero_revive_reply = 1992,
		gc_attack_platform_fight_notify = 1993,
		gc_long_hurt_info_reply = 1994,
		gc_family_war_attack_long_reply = 1995,
		gc_family_war_result_info_reply = 1996,
		gc_family_long_info_notify = 1997,
		gc_trade_supplement_notify = 1998,
		gc_random_shop_info_reply = 1999,
		gc_random_shop_buy_reply = 2000,
		gc_random_shop_refresh_reply = 2001,
		gc_dungeon_leave_reply = 2002,
		gc_enter_arena_reply = 2003,
		gc_enter_game_for_hero_reply = 2004,
		gc_enter_game_for_item_reply = 2005,
		gc_family_prayer_reply = 2006,
		gc_family_prayer_gift_reply = 2007,
		gc_change_multi_state_reply = 2008,
		gc_section_pass_pve_reply = 2009,
		gc_get_active_reward_reply = 2010,
		gc_recharge_reward_reply = 2011,
		gc_section_online_reward_notify = 2012,
		gc_merage_item_reply = 2013,
		gc_zhuagui_task_over_reply = 2014,
		gc_del_task = 2015,
		gc_buy_wish_summon_reply = 2016,
		gc_sell_hero_chip_reply = 2017,
		gc_buy_vigour_reply = 2018,
		gc_vigour_info_notify = 2019,
		gc_task_quick_data_reply  = 2020,
		gc_task_quick_complete_reply = 2021,
		gc_quick_fight_elite_page_reply = 2022,
		gc_reset_quick_fight_elite_page_reply = 2023,
		gc_get_money_tree_reply = 2024,
		gc_shake_money_tree_reply = 2025,
		gc_levelup_money_tree_reply = 2026,
		gc_get_7d_login_reply = 2027,
		gc_get_7d_login_prize_reply = 2028,
		gc_up_level_lifelabel_reply = 2029,
		gc_section_task_finish_notify = 2030,
		gc_replace_head_reply = 2031,
		gc_head_frame_list_reply = 2032,
		gc_use_multiple_chosen_item_reply = 2033,
		gc_get_month_card_info_reply = 2034,
		gc_buy_month_card_reply = 2035,
		gc_get_month_card_prize_reply = 2036,
		gc_auto_task_buy_item_reply = 2037,
		gc_auto_complete_task_reply = 2038,
		gc_init_active_info_reply = 2039,
		gc_active_start_reply = 2040,
		gc_active_stop_reply = 2041,
		gc_get_level_fund_info_reply = 2042,
		gc_get_level_fund_prize_reply = 2043,
		gc_buy_level_fund_reply = 2044,
		gc_get_exchange_info_reply = 2045,
		gc_get_exchange_prize_reply = 2046,
		gc_get_limit_buy_info_reply = 2047,
		gc_buy_limit_reply = 2048,
		gc_get_sd_target_info_reply = 2049,
		gc_get_sd_target_red_reply = 2050,
		gc_get_sd_target_prize_reply = 2051,
		gc_patrol_hire_info_reply = 2052,
		gc_get_patrol_hire_rwd_reply = 2053,
		gc_fast_patrol_hire_reply = 2054,
		gc_change_patrol_hire_reply = 2055,
		__gc_patrol_hire_finish_notify = 2056,
		gc_get_general_event_info_reply = 2057,
		gc_get_general_event_detail_reply = 2058,
		gc_get_general_event_prize_reply = 2059,
		gc_get_server_level_limit_reply = 2060,
		gc_active_update_reply = 2061,
		gc_ignore_lineup_flag_reply = 2062,
		gc_combat_summon_ntf = 2063,
		gc_sync_enemy_hurt_hp = 2064,
		gc_finish_new_role_guide_reply = 2065,

		//  -------------------------client -> chat------------------------
		ch_test_request = 4001,
		ch_channel_chat_request = 4002,
		__ch_get_item_info_request = 4003,
		__ch_get_hero_info_request = 4004,
		ch_get_server_channel_list_request = 4005,
		ch_change_server_channel_request = 4006,
		ch_server_channel_chat_request = 4007,
		ch_hero_strategy_hero_info_request = 4008,
		ch_hero_strategy_get_comments_request = 4009,
		ch_hero_strategy_like_request = 4010,
		ch_hero_strategy_create_comment_request = 4011,

		//  -------------------------chat -> client------------------------
		hc_test_reply = 4101,
		hc_channel_chat_reply = 4102,
		hc_channel_chat_notify = 4103,
		__hc_get_item_info_reply = 4104,
		__hc_get_hero_info_reply = 4105,
		hc_get_server_channel_list_reply = 4106,
		hc_change_server_channel_reply = 4107,
		hc_change_server_channel_notify = 4108,
		hc_server_channel_chat_reply = 4109,
		hc_server_channel_chat_notify = 4110,
		hc_hero_strategy_hero_info_reply = 4111,
		hc_hero_strategy_get_comments_reply = 4112,
		hc_hero_strategy_like_reply = 4113,
		hc_hero_strategy_create_comment_reply = 4114,

		//  -------------------------client -> center------------------------
		ce_reply_family_invite_request = 8101,
		ce_join_family_request = 8102,
		ce_family_invite_request = 8103,
		ce_get_family_list_request = 8104,
		ce_get_family_info_request = 8105,
		ce_get_family_member_list_request = 8106,
		ce_approve_join_family_request = 8107,
		ce_one_key_approve_join_family_request = 8108,
		ce_one_key_decline_join_family_request = 8109,
		ce_toggle_auto_newbie_request = 8110,
		ce_leave_family_request = 8111,
		ce_upgrade_family_build_request = 8112,
		ce_modify_family_declaration_request = 8113,
		ce_modify_family_notification_request = 8114,
		ce_get_family_build_info_request = 8115,
		ce_decline_join_family_request = 8116,
		ce_clear_family_build_upgrade_cd_request = 8117,
		ce_family_fuzzy_query_request = 8118,
		ce_abandon_impeach_family_general_request = 8119,
		ce_approve_impeach_family_general_request = 8120,
		ce_get_impeach_data_request = 8121,
		ce_country_preview_request = 8122,
		ce_country_alliance_request = 8123,
		ce_dismiss_alliance_request = 8124,
		ce_country_info_request = 8125,
		ce_modify_year_name_request = 8126,
		ce_modify_notice_request = 8127,
		ce_open_appoint_request = 8128,
		ce_appoint_officer_request = 8129,
		ce_fire_officer_request = 8130,
		ce_resign_officer_request = 8131,
		ce_country_family_list_request = 8132,
		ce_country_create_list_request = 8133,
		ce_refuse_family_invite_request = 8134,
		ce_get_family_shop_request = 8135,
		ce_country_flag_list_request = 8136,
		ce_family_assign_request = 8137,
		ce_family_fire_request = 8138,
		ce_kick_family_member_request = 8139,
		ce_redbag_draw_request = 8140,
		ce_change_country_name_request = 8141,
		ce_king_war_scene_num_request = 8142,
		ce_offline_arena_score_award_request = 8143,
		ce_offline_arena_sweep_request = 8144,
		ce_rank_request = 8145,
		ce_rank_time_request = 8146,
		__ce_do_country_activity_request = 8147,
		__ce_field_boss_request = 8148,
		__ce_get_country_affires_request = 8149,
		ce_field_boss_info_request = 8150,
		ce_family_apply_list_request = 8151,
		ce_get_friends_request = 8152,
		ce_add_friend_request = 8153,
		ce_remove_friend_request = 8154,
		ce_black_friend_request = 8155,
		ce_friend_search_user_by_id_request = 8156,
		ce_friend_search_user_by_name_request = 8157,
		ce_refresh_recommend_friends_list_request = 8158,
		ce_top_friend_request = 8159,
		ce_cancel_top_friend_request = 8160,
		ce_clear_friends_request = 8161,
		ce_get_recent_friends_request = 8162,
		ce_get_black_friends_request = 8163,
		ce_cancel_black_friend_request = 8164,
		ce_clear_recent_friends_request = 8165,
		ce_clear_black_friends_request = 8166,
		ce_get_friend_applier_list_request = 8167,
		ce_approve_add_friend_request = 8168,
		ce_clear_friend_appliers_request = 8169,
		ce_mail_list_request = 8170,
		ce_mail_content_request = 8171,
		ce_mail_get_addenda_request = 8172,
		ce_mail_remove_request = 8173,
		ce_mail_batch_request = 8174,
		ce_personal_chat_request = 8175,
		ce_challenge_request = 8176,
		ce_king_war_sign_up_request = 8177,
		ce_king_war_offer_money_request = 8178,
		ce_king_war_sign_up_list_request = 8179,
		ce_challenge_record_request = 8180,
		ce_shop_goods_request = 8181,
		ce_buy_goods_request = 8182,
		ce_world_cup_data_request = 8183,
		ce_world_cup_odds_request = 8184,
		ce_personal_chat_notice_request = 8185,
		ce_troop_kick_request = 8186,
		ce_world_trend_info_request = 8187,
		ce_king_war_undo_sign_up_request = 8188,
		ce_troop_apply_member_request = 8189,
		ce_troop_process_apply_request = 8190,
		ce_troop_invite_join_request = 8191,
		ce_troop_invite_single_request = 8192,
		ce_troop_auto_join_flag_request = 8193,
		ce_troop_quit_request = 8194,
		ce_troop_modify_request = 8195,
		ce_troop_list_request = 8196,
		ce_troop_invite_shadow_request = 8197,
		ce_troop_transfer_leader_request = 8198,
		ce_troop_leave_request = 8199,
		ce_goods_selling_list_request = 8200,
		ce_goods_selling_data_request = 8201,
		ce_goods_care_request = 8202,
		ce_goods_self_request = 8203,
		ce_goods_sell_info_request = 8204,
		ce_goods_docare_request = 8205,
		ce_goods_clear_care_request = 8206,
		ce_goods_cancel_request = 8207,
		ce_get_family_war_list_request = 8208,
		ce_get_family_war_history_request = 8209,
		ce_enter_family_war_scene_request = 8210,
		ce_family_prayer_list_request = 8211,
		ce_prayer_gift_reward_request = 8212,
		ce_prayer_record_request = 8213,
		ce_other_role_info_request = 8214,
		ce_offline_arena_data_request = 8215,
		ce_offline_arena_enemy_data_request = 8216,
		ce_offline_arena_fight_request = 8217,
		ce_offline_arena_record_award_request = 8218,
		ce_offline_arena_rank_request = 8219,
		ce_offline_arena_record_request = 8220,
		ce_buy_wish_summon_request = 8221,
		ce_open_summon_wish_request = 8222,
		ce_get_wish_summon_info_request = 8223,
		ce_get_king_info_request = 8224,
		ce_get_king_money_request = 8225,
		ce_exchange_cdkey_request = 8226,
		__ce_invite_shadow_request = 8227,
		ce_king_war_like_request = 8228,
		ce_king_war_notice_request = 8229,
		ce_king_war_help_family_list_request = 8230,
		ce_king_war_help_family_fuzzy_request = 8231,
		ce_king_war_invite_help_request = 8232,
		ce_cencel_king_war_invite_request = 8233,
		ce_cencel_king_war_help_request = 8234,
		ce_king_war_invite_process_request = 8235,
		ce_king_war_invites_clear_request = 8236,
		ce_give_friend_point_request = 8237,
		ce_get_friend_point_request = 8238,
		ce_get_relation_award_request = 8239,
		ce_give_present_request = 8240,
		ce_get_relation_award_data_request = 8241,

		//  -------------------------center -> client------------------------
		ec_create_family_reply = 9101,
		ec_join_family_reply = 9102,
		ec_family_fuzzy_query_reply = 9103,
		ec_get_family_list_reply = 9104,
		ec_get_family_info_reply = 9105,
		ec_get_family_member_list_reply = 9106,
		ec_one_key_approve_join_family_reply = 9107,
		ec_one_key_decline_join_family_reply = 9108,
		ec_toggle_auto_newbie_reply = 9109,
		ec_approve_join_family_reply = 9110,
		ec_leave_family_reply = 9111,
		ec_upgrade_family_build_reply = 9112,
		ec_modify_family_declaration_reply = 9113,
		ec_modify_family_notification_reply = 9114,
		ec_get_family_build_info_reply = 9115,
		ec_decline_join_family_reply = 9116,
		ec_clear_family_build_upgrade_cd_reply = 9117,
		ec_impeach_family_general_reply = 9118,
		ec_abandon_impeach_family_general_reply = 9119,
		ec_approve_impeach_family_general_reply = 9120,
		ec_impeach_start_notify = 9121,
		ec_impeach_result_notify = 9122,
		ec_impeach_status_notify = 9123,
		ec_family_id_notify = 9124,
		ec_get_impeach_data_reply = 9125,
		ec_family_invite_reply = 9126,
		ec_family_notification_change_notify = 9127,
		ec_family_declaration_change_notify = 9128,
		ec_family_invite_notify = 9129,
		ec_reply_family_invite_reply = 9130,
		ec_family_invite_refuse_notify = 9131,
		ec_get_family_shop_reply = 9132,
		ec_family_shop_buy_reply = 9133,
		ec_silence_role_ntf = 9134,
		ec_country_preview_reply = 9135,
		ec_country_alliance_reply = 9136,
		ec_dismiss_alliance_reply = 9137,
		ec_country_info_reply = 9138,
		ec_modify_year_name_reply = 9139,
		ec_modify_notice_reply = 9140,
		ec_open_appoint_reply = 9141,
		ec_appoint_officer_reply = 9142,
		ec_fire_officer_reply = 9143,
		ec_resign_officer_reply = 9144,
		ec_country_family_list_reply = 9145,
		ec_country_alliance_notify = 9146,
		ec_family_assign_reply = 9147,
		ec_kick_family_member_reply = 9148,
		ec_family_officer_changed_notify = 9149,
		ec_family_fire_reply = 9150,
		ec_country_create_list_reply = 9151,
		ec_country_flag_list_reply = 9152,
		ec_change_country_name_reply = 9153,
		ec_update_country_notify = 9154,
		ec_world_trend_info_reply = 9155,
		ec_king_war_undo_sign_up_reply = 9156,
		ec_king_war_scene_num_reply = 9157,
		ec_king_war_like_reply = 9158,
		ec_king_war_notice_reply = 9159,
		ec_offline_arena_sweep_reply = 9160,
		ec_friend_troop_notify = 9161,
		ec_rank_time_reply = 9162,
		ec_rank_reply = 9163,
		ec_family_members_in_notify = 9164,
		ec_family_members_out_notify = 9165,
		ec_family_money_change_notify = 9166,
		__ec_country_officer_change_notify = 9167,
		__ec_country_affire_change_notify = 9168,
		__ec_get_country_activities_reply = 9169,
		__ec_do_country_activity_reply = 9170,
		__ec_country_activity_change_ntf = 9171,
		__ec_field_boss_reply = 9172,
		ec_field_boss_info_notify = 9173,
		__ec_field_boss_refresh_notify = 9174,
		__ec_get_country_affires_reply = 9175,
		ec_family_apply_list_reply = 9176,
		ec_redbag_notify = 9177,
		__ec_family_apply_list_out_notify = 9178,
		ec_get_friends_reply = 9179,
		ec_add_friend_reply = 9180,
		ec_remove_friend_reply = 9181,
		ec_black_friend_reply = 9182,
		ec_friend_search_user_by_id_reply = 9183,
		ec_friend_search_user_by_name_reply = 9184,
		ec_refresh_recommend_friends_list_reply = 9185,
		ec_top_friend_reply = 9186,
		ec_cancel_top_friend_reply = 9187,
		ec_clear_friends_reply = 9188,
		ec_redbag_draw_reply = 9189,
		ec_get_recent_friends_reply = 9190,
		ec_get_black_friends_reply = 9191,
		ec_cancel_black_friend_reply = 9192,
		ec_clear_recent_friends_reply = 9193,
		ec_clear_black_friends_reply = 9194,
		ec_get_friend_applier_list_reply = 9195,
		ec_approve_add_friend_reply = 9196,
		ec_clear_friend_appliers_reply = 9197,
		ec_new_mail_notify = 9198,
		ec_mail_list_notify = 9199,
		ec_mail_state_change_notify = 9200,
		ec_mail_content_reply = 9201,
		ec_personal_chat_reply = 9202,
		ec_personal_chat_notify = 9203,
		ec_friend_member_update_notify = 9204,
		ec_challenge_reply = 9205,
		ec_challenge_invite_notify = 9206,
		ec_challenge_result_notify = 9207,
		ec_batch_personal_chat_notify = 9208,
		ec_king_war_sign_up_reply = 9209,
		ec_king_war_offer_money_reply = 9210,
		ec_king_war_sign_up_list_reply = 9211,
		ec_king_war_notice_notify = 9212,
		__ec_king_war_result = 9213,
		ec_challenge_ready_notify = 9214,
		ec_challenge_fight_start_notify = 9215,
		ec_challenge_record_reply = 9216,
		ec_challenge_coming_notify = 9217,
		ec_challenge_win_without_fight_notify = 9218,
		ec_shop_goods_reply = 9219,
		ec_buy_goods_reply = 9220,
		ec_world_cup_data_reply = 9221,
		ec_world_cup_coming_quarter_notify = 9222,
		ec_world_cup_coming_soon_notify = 9223,
		ec_world_cup_ready_notify = 9224,
		ec_world_cup_odds_reply = 9225,
		ec_troop_create_reply = 9226,
		ec_troop_kick_reply = 9227,
		ec_troop_event_notify = 9228,
		ec_troop_join_reply = 9229,
		ec_troop_apply_member_reply = 9230,
		ec_troop_process_apply_reply = 9231,
		ec_troop_invite_join_reply = 9232,
		ec_troop_invite_join_notify = 9233,
		ec_troop_process_invite_reply = 9234,
		ec_troop_auto_join_flag_reply = 9235,
		ec_troop_quit_reply = 9236,
		ec_troop_modify_reply = 9237,
		ec_troop_list_reply = 9238,
		ec_troop_invite_shadow_reply = 9239,
		ec_troop_transfer_leader_reply = 9240,
		ec_troop_leave_reply = 9241,
		ec_goods_selling_list_reply = 9242,
		ec_goods_selling_data_reply = 9243,
		ec_goods_care_reply = 9244,
		ec_goods_self_reply = 9245,
		ec_goods_sell_info_reply = 9246,
		ec_goods_docare_reply = 9247,
		ec_goods_clear_care_reply = 9248,
		ec_goods_cancel_reply = 9249,
		ec_get_family_war_list_reply = 9250,
		ec_get_family_war_history_reply = 9251,
		ec_enter_family_war_scene_reply = 9252,
		ec_troop_invite_result_notify = 9253,
		ec_family_prayer_list_reply = 9254,
		ec_prayer_gift_reward_reply = 9255,
		ec_prayer_record_reply = 9256,
		ec_family_prayer_reply = 9257,
		ec_sys_notice_notify = 9258,
		ec_troop_rejoin_notify = 9259,
		ec_other_role_info_reply = 9260,
		ec_offline_arena_data_reply = 9261,
		ec_offline_arena_enemy_data_reply = 9262,
		ec_offline_arena_fight_reply = 9263,
		ec_offline_arena_record_notify = 9264,
		ec_offline_arena_rank_reply = 9265,
		ec_offline_arena_record_reply = 9266,
		ec_get_wish_summon_info_reply = 9267,
		ec_open_summon_wish_reply = 9268,
		ec_get_king_info_reply = 9269,
		ec_get_king_money_reply = 9270,
		ec_exchange_cdkey_reply = 9271,
		__ec_invite_shadow_reply = 9272,
		ec_king_war_help_family_list_reply = 9273,
		ec_king_war_help_family_fuzzy_reply = 9274,
		ec_king_war_invite_help_reply = 9275,
		ec_cencel_king_war_invite_reply = 9276,
		ec_cencel_king_war_help_reply = 9277,
		ec_king_war_invite_help_notify = 9278,
		ec_king_war_invite_process_reply = 9279,
		ec_give_friend_point_reply = 9280,
		ec_get_friend_point_reply = 9281,
		ec_get_relation_award_reply = 9282,
		ec_give_present_reply = 9283,
		ec_can_get_relation_award_notify = 9284,
		ec_get_relation_award_data_reply = 9285,
		ec_get_present_notify = 9286,
		ec_friendliness_change_notify = 9287,
		ec_family_war_state_notify = 9288,

	}
}
