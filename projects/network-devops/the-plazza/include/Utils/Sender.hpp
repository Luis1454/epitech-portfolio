/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Sender
*/

#ifndef SENDER_HPP_
    #define SENDER_HPP_

    #include "../../include/Utils/Utils.hpp"
    #include "../../include/Parsing/Parsing.hpp"

class Sender {
    public:
        Sender();
        ~Sender();
        void prepareMessage(std::string message);
        void sendMessage(std::vector<int> pipefd);

    private:
        std::string _message;
        Utils::Pipe pipe_Utils;
};

#endif /* !SENDER_HPP_ */
