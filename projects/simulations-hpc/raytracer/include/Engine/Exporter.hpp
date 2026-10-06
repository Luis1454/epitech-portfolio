/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Exporter
*/

#ifndef EXPORTER_HPP_
    #define EXPORTER_HPP_

    #include <iostream>
    #include <vector>

    #include "../Physics/Color.hpp"

class Exporter {
    public:
        Exporter();
        ~Exporter();

        void createFile(std::string file);
        void writeImage(std::string file, Image img);
};

#endif /* !EXPORTER_HPP_ */
