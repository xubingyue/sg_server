#include "center_listener.hpp"
#include "main/db_server_fwd.hpp"
#include "main/db_server.hpp"

USING_NS_NETWORK;
USING_NS_COMMON;

void center_listener_t::on_new_accept(const tcp_socket_ptr& s)
{
    env::server->get_ios().post(boost::bind(&db_server_t::on_add_center, env::server, s));
}

void center_listener_t::on_new_msg(const tcp_socket_ptr& s, const message_t& msg)
{
    if (msg.has_uid())
    {
        env::server->get_ios().post(boost::bind(&db_server_t::on_center_msg, env::server, s, msg.get_uid(), msg.head.cmd, msg.body));
	}
	else
	{
		env::server->get_ios().post(boost::bind(&db_server_t::on_center_msg, env::server, s, 0, msg.head.cmd, msg.body));
	}
}

void center_listener_t::on_close(const tcp_socket_ptr& s)
{
    env::server->get_ios().post(boost::bind(&db_server_t::on_del_center, env::server, s));
}

void center_listener_t::send_msg_to_center(const msg_buf_ptr& msg)
{
    env::server->post_network_send_msg(get_socket(), msg);
}