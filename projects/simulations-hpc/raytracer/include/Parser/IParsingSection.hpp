/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** IParsingSection
*/

#ifndef IPARSINGSECTION_HPP_
    #define IPARSINGSECTION_HPP_

    #include <vector>
    #include <string>
    #include <iostream>
    #include <fstream>
    #include <sstream>

    template<typename T>

class IParsingSection {
    public:
        virtual void set_info(const std::vector<std::string> tokens) = 0;
        virtual T get_info() const = 0;
};

#endif /* !IPARSINGSECTION_HPP_ */
