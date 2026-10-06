/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Error
*/

#include "../../include/Error/Error.hpp"

using namespace err;

Error::Error(List_error type) : _message(selectErrorMessage(type))
{
}

const char* Error::what() const noexcept
{
    return _message.c_str();
}

std::string Error::selectErrorMessage(List_error type) const
{
    for (const auto& error : error_messages)
        if (error.type == type)
            return error.message;
    return "";
}