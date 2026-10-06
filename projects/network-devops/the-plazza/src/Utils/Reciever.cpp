/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Reciever
*/

#include "../../include/Utils/Reciever.hpp"

Reciever::Reciever()
{
    _message = "";
}

Reciever::~Reciever()
{
}

void Reciever::recieveMessage(std::vector<int> pipefd)
{
    _message = pipe_Utils.read_pipe(pipefd[0], 100);
}

std::string Reciever::getMessage()
{
    return _message;
}
