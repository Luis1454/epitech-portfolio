/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** StringUtils
*/

#ifndef STRINGUTILS_HPP_
    #define STRINGUTILS_HPP_

    #include <iostream>
    #include <vector>
    #include <string>
    #include <fstream>
    #include <sstream>

class StringUtils {
    public:
        static std::vector<std::string> split(std::string str, std::string delimiter);
        float recup_float(std::string to_search, std::string tokens);
        std::string recup_string(std::string to_search, std::string tokens);
        float extract(std::string token, std::string key, int dflt);
    private:
        bool its_number(const std::string &str);
};

#endif /* !STRINGUTILS_HPP_ */
