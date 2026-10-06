/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Sender
*/

#include "../../include/Utils/Sender.hpp"

Sender::Sender()
{
    _message = "";
}

Sender::~Sender()
{
}

void Sender::prepareMessage(std::string message)
{
    _message = message;
}

void Sender::sendMessage(std::vector<int> pipefd)
{
    pipe_Utils.write_pipe(pipefd[1], _message.c_str(), _message.size());
}