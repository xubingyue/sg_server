#include "gm_server.hpp"
#include "log.hpp"
#include "center/center_msg_handler.hpp"
#include "admin/admin_msg_handler.hpp"
#include "cdkey/cdkey_msg_handler.hpp"
#include "redis_client.hpp"
#include "redis_gm_table.hpp"

USING_NS_NETWORK;
USING_NS_COMMON;

gm_server_t::gm_server_t()
{
}

gm_server_t::~gm_server_t()
{
}

//----------------------------------------------------------------------------------
bool gm_server_t::on_init_server()
{
    CMD_INIT;

    // xml
    if (!load_xml())
    {
        close_xml();
        COMMON_ASSERT(false);
        return false;
    }

    // log
    if (!g_log.open(env::xml->log_path, server_name(), env::xml->is_log_trace, env::xml->is_log_debug, env::xml->is_log_info, env::xml->is_new_logfile_per_hour))
    {
        COMMON_ASSERT(false);
        return false;
    }

    // zdb
    if (!init_zdb())
    {
        COMMON_ASSERT(false);
        return false;
    }

	// redis
	if (!init_redis())
	{
		COMMON_ASSERT(false);
		return false;
	}

    // network
    if (!init_network())
    {
        COMMON_ASSERT(false);
        return false;
    }

	up_server_info();

    return true;
}

bool gm_server_t::on_close_server()
{
	stop_network();

    close_network();

    close_zdb();

	close_redis();

    close_xml();

    g_log.close();

    CMD_CLOSE;

    return true;
}

void gm_server_t::on_run_server()
{
    log_info("gm server running...");
}

//----------------------------------------------------------------------------------
bool gm_server_t::load_xml()
{
    if (!load_server_xml())
    {
        printf("\033[31mload [%s] failed!\033[0m\n", SERVER_XML_PATH);
        return false;
    }
    printf("load [%s] success!\n", SERVER_XML_PATH);

    return true;
}

bool gm_server_t::load_server_xml()
{
    try
    {
        boost::property_tree::ptree pt;
        boost::property_tree::xml_parser::read_xml(SERVER_XML_PATH, pt);

        env::xml = new gm_xml_t;

		env::xml->srv_group.group_id = pt.get<uint32_t>("server.server_id");
		env::xml->srv_group.group_name = pt.get<std::string>("server.server_name");
        env::xml->srv_group.platform = pt.get<uint32_t>("server.platform");

		env::xml->thread_num.network = pt.get<uint32_t>("server.gm_server.thread_num.network");

        env::xml->listen_at_admin.ip = pt.get<std::string>("server.gm_server.listen.gmtool.ip");
        env::xml->listen_at_admin.port = pt.get<uint32_t>("server.gm_server.listen.gmtool.port");
		CHECK_PORT(env::xml->listen_at_admin.port);
		
        env::xml->listen_at_admin.out_ip = pt.get<std::string>("server.gm_server.listen.gmtool.out_ip");
        env::xml->listen_at_admin.out_port = pt.get<uint32_t>("server.gm_server.listen.gmtool.out_port");
		CHECK_PORT(env::xml->listen_at_admin.out_port);
        
        env::xml->connect_to_center.ip = pt.get<std::string>("server.center_server.listen.gm.ip");
        env::xml->connect_to_center.port = pt.get<uint32_t>("server.center_server.listen.gm.port");
        CHECK_PORT(env::xml->connect_to_center.port);

		env::xml->mysql.host = pt.get<std::string>("server.gm_server.mysql.host");
		env::xml->mysql.db = pt.get<std::string>("server.gm_server.mysql.db");
		env::xml->mysql.user = pt.get<std::string>("server.gm_server.mysql.user");
		env::xml->mysql.pwd = pt.get<std::string>("server.gm_server.mysql.pwd");
        //env::xml->mysql.init_conn = pt.get<uint32_t>("server.gm_server.mysql.init_connections");
        //env::xml->mysql.max_conn = pt.get<uint32_t>("server.gm_server.mysql.max_connections");

        std::string str_ip_white_list = pt.get<std::string>("server.common.ip_white_list");
        string_util_t::split(str_ip_white_list, env::xml->ip_white_list, ";");
        if (env::xml->ip_white_list.empty())
        {
            printf("\033[31mip_white_list is empty!\033[0m\n");
            return false;
        }

        env::xml->log_path = pt.get<std::string>("server.common.log_path");
        env::xml->is_log_trace = pt.get<bool>("server.common.log_trace");
        env::xml->is_log_debug = pt.get<bool>("server.common.log_debug");
		env::xml->is_log_info = pt.get<bool>("server.common.log_info");
		env::xml->is_log_msg_count = pt.get<bool>("server.common.log_msg_count");
		env::xml->is_new_logfile_per_hour = pt.get<bool>("server.common.new_logfile_per_hour");
		env::xml->reconnect_interval_time = pt.get<uint32_t>("server.common.reconnect_interval_time");
        env::xml->url.cdkey_url = pt.get<std::string>("server.url.cdkey_url");

		//redis
		env::xml->redis.host = pt.get<std::string>("server.gm_server.redis.host");
		env::xml->redis.port = pt.get<uint32_t>("server.gm_server.redis.port");
		env::xml->redis.pwd = pt.get<std::string>("server.gm_server.redis.pwd");
		env::xml->redis.db = pt.get<uint32_t>("server.gm_server.redis.db");
		env::xml->redis.conn_overtime = pt.get<uint32_t>("server.gm_server.redis.conn");

    }
    catch (boost::property_tree::ptree_error& e)
    {
        printf("\033[31mthrow error[%s]\033[0m\n", e.what());
        return false;
    }

    if (NULL == env::xml)
    {
        printf("\033[31menv::xml is NULL!\033[0m\n");
        return false;
    }

    return true;
}
void gm_server_t::close_xml()
{
    SAFE_DELETE_P(env::xml);
    log_info("close xml success!");
}

//----------------------------------------------------------------------------------
bool gm_server_t::init_zdb()
{
	uint32_t max_con = 5;
	uint32_t open_con = 1;
    boost::tie(m_db_url, env::conn_zdb_pool) = zdb_util_t::open_zdb(
        env::xml->mysql.host,
        env::xml->mysql.db,
        env::xml->mysql.user,
        env::xml->mysql.pwd,
		max_con,
		open_con);
    if (NULL == env::conn_zdb_pool)
    {
        log_error("init zdb connection pool failed!");
        return false;
    }

    return true;
}
void gm_server_t::close_zdb()
{
    zdb_util_t::close_zdb(env::conn_zdb_pool, m_db_url);
}

void gm_server_t::up_server_info()
{
	Connection_T conn = common::zdb_util_t::get_zdb_conn(env::conn_zdb_pool);
	if (NULL == conn)
	{
		log_error("up_server_info conn is null");
		return;
	}
	std::ostringstream sql;
	std::ostringstream cols;
	
	cols << "`server_id` = ?, `server_name` = ?, `ip` = ?, `port` = ?";
	sql << "REPLACE INTO `gm_server_list` SET " << cols.str() << ";";
	TRY
	{
		PreparedStatement_T pre = Connection_prepareStatement(conn, sql.str().c_str());
		PreparedStatement_setInt(pre, 1, env::xml->srv_group.group_id);
		PreparedStatement_setString(pre, 2, env::xml->srv_group.group_name.c_str());
		PreparedStatement_setString(pre, 3, env::xml->listen_at_admin.out_ip.c_str());
		PreparedStatement_setInt(pre, 4, env::xml->listen_at_admin.out_port);

		PreparedStatement_execute(pre);
	}

	CATCH(SQLException)
	{
		log_error("[up_server_info] error: %s", Exception_frame.message);
	}
	FINALLY
	{
		Connection_close(conn);
	}
	END_TRY;
}

//--------------------------------------------------------------------------------------------------
bool gm_server_t::init_redis()
{
	if (!redis_client_t::init(env::server->get_ios(),
		env::xml->redis.host.c_str(),
		env::xml->redis.port,
		env::xml->redis.pwd.c_str(),
		env::xml->redis.db,
		all_gm_table,
		env::xml->redis.conn_overtime))
	{
		log_error("init redis client failed!");
		return false;
	}

	return true;
}

void gm_server_t::close_redis()
{
	redis_client_t::close();
}

//--------------------------------------------------------------------
bool gm_server_t::init_network()
{
    if (!m_network.init(env::xml->thread_num.network, env::xml->ip_white_list))
    {
        log_error("init network failed!");
        return false;
    }

    // listen for admin
    if (!m_network.listen_at(env::xml->listen_at_admin.ip, env::xml->listen_at_admin.port, &m_admin_listener))
    {
        return false;
    }
    else
    {
        if (!admin_msg_handler_t::init_msg_handler())
        {
            log_error("init admin msg handler failed!");
            return false;
        }
    }

    //connect to center
    if (!m_network.connect_to(env::xml->connect_to_center.ip, env::xml->connect_to_center.port, &m_center_connector, env::xml->reconnect_interval_time))
    {
        return false;
    }
    else
    {
        if (!center_msg_handler_t::init_msg_handler())
        {
            log_error("init center msg handler failed!");
            return false;
        }

		if (!cdkey_msg_handler_t::init_msg_handler())
		{
            log_error("init cdkey msg handler failed!");
            return false;
		}

		if (!center_msg_handler_t::init_center_msg_handler())
		{
            log_error("init center msg handler failed!");
            return false;
		}
    }
	return true;
}
void gm_server_t::close_network()
{
    msg_count_t::write_msg_recv_count_data_file(env::xml->is_log_msg_count);
    msg_count_t::write_msg_send_count_data_file(env::xml->is_log_msg_count);

    //�ͷ�admin

    m_network.close();
}

//-------------------------------------------------------------------------------------------------
void gm_server_t::on_add_center(const network::tcp_socket_ptr& s)
{
    m_center_connector.set_socket(s);
}
void gm_server_t::on_del_center(const network::tcp_socket_ptr& s)
{
    env::server->post_network_close_socket(s);
    m_center_connector.close_socket();
}
void gm_server_t::on_center_msg(const network::tcp_socket_ptr& s, uint64_t uid, uint16_t cmd, const network::msg_buf_ptr& msg_buf)
{
	msg_count_t::push_msg_recv_info(msg_buf, cmd, env::xml->is_log_msg_count);
    center_msg_handler_t::handle_server_msg(s,uid, cmd, msg_buf);
}

//-------------------------------------------------------------------------------------------------
void gm_server_t::on_add_admin(const network::tcp_socket_ptr& s)
{
    m_admin_listener.set_socket(s);
}
void gm_server_t::on_del_admin(const network::tcp_socket_ptr& s)
{
    env::server->post_network_close_socket(s);
    m_admin_listener.close_socket();
}
void gm_server_t::on_admin_msg(const network::tcp_socket_ptr& s, uint64_t uid, uint16_t cmd, const network::msg_buf_ptr& msg_buf)
{
	//msg_count_t::push_msg_recv_info(msg_buf, cmd, env::xml->is_log_msg_count);
    admin_msg_handler_t::handle_server_msg(s,uid, cmd, msg_buf);
}

void gm_server_t::stop_network()
{
	m_network.stop();
}
