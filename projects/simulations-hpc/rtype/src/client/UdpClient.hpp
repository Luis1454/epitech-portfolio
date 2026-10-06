#ifndef UDPCLIENT_HPP
#define UDPCLIENT_HPP

#include <asio.hpp>
#include <vector>
#include <string>
#include <thread>
#include <atomic>
#include <queue>
#include "../server/ECS/ECS.hpp"
#include "../Protocol/Protocol.hpp"

class UdpClient {
public:
    UdpClient(const std::string& host, uint16_t port, ECS &ecs);
    ~UdpClient();

    void start();
    void stop();

    void addRequest(std::vector<field_t> fields);

    void executePool();

private:
    asio::io_context io_context_;
    asio::ip::udp::socket socket_;
    asio::ip::udp::endpoint server_endpoint_;
    std::atomic<bool> running_;
    std::thread communication_thread_;
    std::queue<std::vector<field_t>> _pool;
    std::mutex _socketMutex;
    ECS &_ecs;

    void communicate();
};

#endif /* UDPCLIENT_HPP */
