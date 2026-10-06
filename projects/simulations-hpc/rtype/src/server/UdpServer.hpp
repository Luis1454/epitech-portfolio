#ifndef UDPSERVER_HPP_
#define UDPSERVER_HPP_

#include <asio.hpp>
#include <vector>
#include <unordered_map>
#include "ECS/ECS.hpp"
#include "../Protocol/Protocol.hpp"

class UdpServer {
public:
    UdpServer(asio::io_context& io_context, uint16_t port);
    ~UdpServer();

    void start(ECS &ecs);
    void stop();
    void send(const std::vector<uint8_t>& data, asio::ip::udp::endpoint endpoint);

    void sendRequestToAllClients(ECS &ecs, std::vector<field_t> &fields);
    void sendRequestTo(ECS &ecs, std::vector<field_t> &fields, asio::ip::udp::endpoint endpoint);

private:
    void do_receive(ECS &ecs);
    void handle_receive(const asio::error_code& error, std::size_t bytes_transferred, ECS &ecs);

    asio::io_context& io_context_;
    asio::ip::udp::socket socket_;
    asio::ip::udp::endpoint remote_endpoint_;
    std::vector<uint8_t> recv_buffer_;
    bool running_;
};

#endif /* UDPSERVER_HPP_ */
