#include "UdpServer.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <mutex>
#include <thread>
#include <cstdint>
#include "../Protocol/Protocol.hpp"

UdpServer::UdpServer(asio::io_context& io_context, uint16_t port)
    : io_context_(io_context),
      socket_(io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)),
      running_(false) {
}

UdpServer::~UdpServer() {
    stop();
}

void UdpServer::start(ECS &ecs) {
    running_ = true;
    std::cout << "Server started on port " << socket_.local_endpoint().port() << std::endl;
    do_receive(ecs);
}

void UdpServer::stop() {
    running_ = false;
    socket_.close();
}

void UdpServer::do_receive(ECS &ecs) {
    recv_buffer_.resize(1024);
    socket_.async_receive_from(
        asio::buffer(recv_buffer_), remote_endpoint_,
        [this, &ecs](const asio::error_code& error, std::size_t bytes_transferred) {
            ecs.setLastEndpoint(remote_endpoint_);
            handle_receive(error, bytes_transferred, ecs);
        });
}

void UdpServer::handle_receive(const asio::error_code& error, std::size_t bytes_transferred, ECS &ecs) {
    if (!error && bytes_transferred > 0) {
        recv_buffer_.resize(bytes_transferred);
        // process_packet(recv_buffer_);
        Protocol<Byte> protocol;
        protocol.setBuffer(recv_buffer_);
        protocol.runRequest(ecs);

        std::vector<uint8_t> req;

        for (auto i : protocol.getBuffer())
            req.push_back(i);

        Buffer tmp = protocol.getBuffer();
        uint64_t player_id = tmp.toType(8, 16);

        send(req, remote_endpoint_);
    } else if (error)
        std::cerr << "Erreur lors de la réception d'un paquet: " << error.message() << "\n";

    if (running_)
        do_receive(ecs);
}

void UdpServer::send(const std::vector<uint8_t>& data, asio::ip::udp::endpoint endpoint) {
    socket_.async_send_to(asio::buffer(data), endpoint,
        [](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error)
                std::cerr << "Erreur lors de l'envoi d'un paquet: " << error.message() << "\n";
        });
}

void UdpServer::sendRequestToAllClients(ECS &ecs, std::vector<field_t> &fields) {
    Protocol<Byte> protocol;

    protocol.clearBuffer();
    protocol.resizeBuffer(32);
    protocol.setBuffer(protocol.createPacket(fields));
    protocol.runRequest(ecs);

    for (auto &client : ecs.getClients())
        send(protocol.getBuffer(), client.second);
}

void UdpServer::sendRequestTo(ECS &ecs, std::vector<field_t> &fields, asio::ip::udp::endpoint client) {
    Protocol<Byte> protocol;

    protocol.clearBuffer();
    protocol.resizeBuffer(32);
    protocol.setBuffer(protocol.createPacket(fields));
    protocol.runRequest(ecs);

    send(protocol.getBuffer(), client);
}
