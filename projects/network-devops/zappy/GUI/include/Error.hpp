/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Error.cpp
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <cstring>
#include <cstdlib>

#define MY_EXIT_FAILURE 84

namespace err {

    class InvalidArgument : public std::exception {
    public:
        InvalidArgument(const std::string& message) : _message(message) {}
        const char* what() const noexcept override {
            return _message.c_str();
        }
    private:
        std::string _message;
    };

    class NotEnoughArguments : public InvalidArgument {
    public:
        NotEnoughArguments() : InvalidArgument("Error: Not enough arguments") {}
    };

    class InvalidPortNumber : public InvalidArgument {
    public:
        InvalidPortNumber() : InvalidArgument("Error: Invalid port number") {}
    };

    class NoPortNumberProvided : public InvalidArgument {
    public:
        NoPortNumberProvided() : InvalidArgument("Error: No port number provided") {}
    };

    class NoHostnameProvided : public InvalidArgument {
    public:
        NoHostnameProvided() : InvalidArgument("Error: No hostname provided") {}
    };

    class UnknownOption : public InvalidArgument {
    public:
        UnknownOption(const std::string& option) : InvalidArgument("Error: Unknown option " + option) {}
    };
    class ErrorWindowResolution : public std::exception {
        public:
            ErrorWindowResolution() {}
            const char *what() const noexcept override {
                return "Error: Window resolution must be higher to 0 x 0";
            }
        private:
            std::string _message;
    };
    class ErrorWindowCreation : public std::exception {
        public:
            ErrorWindowCreation() {}
            const char *what() const noexcept override {
                return "Error: Window creation failed";
            }
        private:
            std::string _message;
    };
    class NoMachineNameProvided : public InvalidArgument {
    public:
        NoMachineNameProvided() : InvalidArgument("Error: No machine name provided") {}
    };
}

#endif /* !ERROR_HPP_ */