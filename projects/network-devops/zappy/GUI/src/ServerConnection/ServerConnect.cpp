/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** ServerConnect.cpp
*/

#include "../../include/ServerConnect.hpp"
#include <chrono>
#include <thread>

ServerConnect::ServerConnect()
{
    _port = -1;
}

ServerConnect::~ServerConnect()
{
}

void ServerConnect::setPort(int port)
{
    _port = port;
}

int ServerConnect::getPort() const
{
    return _port;
}

void ServerConnect::use_host(std::string const arg)
{
    try {
        _port = std::atoi(arg.c_str());
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    if (_port < 0)
        throw err::InvalidPortNumber();
}

void ServerConnect::connectToServer(const std::string &host, unsigned short port)
{
    if (_socket.connect(host, port) != sf::Socket::Done)
        std::cerr << "Failed to connect to server\n";
    else
        std::cout << "Connected to server\n";
}

void ServerConnect::sendMessage(std::string msg, int delay)
{
    if (_socket.send(msg.c_str(), msg.size()) != sf::Socket::Done)
        std::cerr << "Failed to send message to server\n";
    else
        std::cout << "Message " << msg << " sent to server\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

std::string ServerConnect::receiveMessage()
{
    char buffer[8192];
    std::size_t received;

    if (_socket.receive(buffer, sizeof(buffer), received) == sf::Socket::Done)
        return std::string(buffer, received);
    return "";
}

void ServerConnect::receiveMessages()
{
    std::string message = receiveMessage();
    Cmd cmd;

    _cmds.clear();

    if (!message.empty())
        _cmds = cmd.split(message);
}

std::vector<std::shared_ptr<Cmd>> ServerConnect::getCommands() const
{
    return _cmds;
}
