/*
** EPITECH PROJECT, 2024
** Environment.hpp
** File description:
** Environment
*/

#ifndef ENVIRONMENT_HPP_
    #define ENVIRONMENT_HPP_

    #include <string>
    #include <vector>
    #include <fstream>
    #include <sstream>

    #include "../Physics/Color.hpp"
    #include "../Physics/Vector.hpp"

class Environment {
    public:
        Environment();
        ~Environment();

        void setTexture(std::string path, double intensity);
        Color getPixel(Vector3d direction);

    private:
        std::string _texture;
        Image _colors;
};

#endif /* !ENVIRONMENT_HPP_ */
