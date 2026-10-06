/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Reciever
*/

#ifndef RECIEVER_HPP_
    #define RECIEVER_HPP_

    #include <vector>
    #include <sstream>
    #include <iostream>

    #include "../Utils/Utils.hpp"

class Reciever {
    public:
        Reciever();
        ~Reciever();
        void recieveMessage(std::vector<int> pipefd);
        std::string getMessage();

    private:
        Utils::Pipe pipe_Utils;
        std::string _message;
};

#endif /* !RECIEVER_HPP_ */
