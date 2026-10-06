/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** stringutils
*/

#include "../../include/Parser/StringUtils.hpp"

std::vector<std::string> StringUtils::split(std::string str, std::string delimiter)
{
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;

    str.erase(0, str.find_first_not_of(" \t"));
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
        str.erase(0, str.find_first_not_of(" \t"));
    }
    str.erase(str.find_last_not_of(" \t") + 1);
    if (!str.empty())
        tokens.push_back(str);
    return tokens;
}

bool StringUtils::its_number(const std::string &str)
{
    if (str.empty())
        return false;
    if (str[0] == '-') {
        for (size_t i = 1; i < str.length(); ++i)
            if (!std::isdigit(str[i]) && str[i] != '.')
                return false;
    } else
        for (char c : str)
            if (!std::isdigit(c) && c != '.')
                return false;
    return true;
}

float StringUtils::recup_float(std::string to_search, std::string tokens)
{
    std::vector<std::string> words = split(tokens, " ");

    for (size_t i = 0; i < words.size(); i++) {
        if (words[i] == to_search && its_number(words[i + 1]))
            return std::stof(words[i + 1]);
        if (words[i] == to_search && words[i + 1] == "=" && its_number(words[i + 2]))
            return std::stof(words[i + 2]);
    }
    return __INT_MAX__;
}

float StringUtils::extract(std::string token, std::string key, int dflt) {
    return recup_float(key, token) == __INT_MAX__ ? dflt : recup_float(key, token);
}

std::string StringUtils::recup_string(std::string to_search, std::string tokens)
{
    std::vector<std::string> words = split(tokens, " ");

    for (size_t i = 0; i < words.size(); i++) {
        if (words[i] == to_search && words[i + 1] != "=")
            return words[i + 1];
        if (words[i] == to_search && words[i + 1] == "=" && words[i + 2] != "")
            return words[i + 2];
    }
    return "";
}