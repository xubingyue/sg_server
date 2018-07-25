#ifndef __GAME_GATE_listener_HPP__
#define __GAME_GATE_listener_HPP__

#include "network.hpp"

class gate_listener_t
    : public network::acceptor_callback_t
{
public:
    gate_listener_t() {}
    virtual ~gate_listener_t() {}

    virtual const char* name() { return "gate"; }
    virtual void on_new_accept(const network::tcp_socket_ptr& s);
    virtual void on_new_msg(const network::tcp_socket_ptr& s, const network::message_t& msg);
    virtual void on_close(const network::tcp_socket_ptr& s );
};

#endif
