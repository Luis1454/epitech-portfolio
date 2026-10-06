/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** ServerConnect.hpp
*/

#ifndef SERVER_CONNECT_HPP_
#define SERVER_CONNECT_HPP_

#include <SFML/Network.hpp>
#include <iostream>
#include <cstring>
#include "Error.hpp"
#include "Commands/Cmd.hpp"

class ServerConnect {
    public:
        ServerConnect();
        ~ServerConnect();
        void setPort(int port);
        int getPort() const;
        void use_host(std::string const arg);
        void sendMessage(std::string msg, int delay = 0);
        void connectToServer(const std::string& host, unsigned short port);
        void receiveMessages();
        std::vector<std::shared_ptr<Cmd>> getCommands() const;
        std::string receiveMessage();

    private:
        std::vector<std::shared_ptr<Cmd>> _cmds;
        sf::SocketSelector _selector;
        sf::TcpSocket _socket;
        std::string _buffer;
        std::string _host;
        int _port;
        Cmd _cmd;
};

#endif /* !SERVER_CONNECT_HPP_ */