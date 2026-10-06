/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include <iostream>
    #include <string>
    #include <exception>
    #include <vector>

namespace err {
    enum List_error {
        FORK_FAILED,
        INVALID_ARG,
        NUMBER_ARG,
        COOKING_TIME,
        RESTOCK_TIME,
        VALID_SIZE,
        INVALID_TYPE,
        VALID_NUMBER,
        INVALID_NUMBER_COOKS,
        OUT_OF_RANGE
    };

    struct ErrorInfo {
        List_error type;
        std::string message;
    };

    const std::vector<ErrorInfo> error_messages = {
        {List_error::FORK_FAILED, "Fork failed"},
        {List_error::INVALID_ARG, "Invalid argument, argument must be a number"},
        {List_error::NUMBER_ARG, "Invalid number of arguments, check the usage with ./plazza -h"},
        {List_error::COOKING_TIME, "Invalid cooking time, Must be superior to 0"},
        {List_error::RESTOCK_TIME, "Invalid restock time, Must be superior to 0"},
        {List_error::VALID_SIZE, "Invalid size, must be S, M, L, XL or XXL"},
        {List_error::INVALID_TYPE, "Invalid type, must be a valid pizza type"},
        {List_error::VALID_NUMBER, "Invalid number, must be a valid number starting with x and followed by digits"},
        {List_error::INVALID_NUMBER_COOKS, "Invalid number of cooks, must be superior to 0"},
        {List_error::OUT_OF_RANGE, "Out of range"}
    };

    class Error : public std::exception {
        public:
            Error(List_error type);
            ~Error() = default;
            const char* what() const noexcept override;

        private:
            std::string _message;
            std::string selectErrorMessage(List_error type) const;
    };
}

#endif /* !ERROR_HPP_ */
