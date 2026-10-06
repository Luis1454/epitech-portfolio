/*
** EPITECH PROJECT, 2024
** Environment.cpp
** File description:
** Environment
*/

#include "../../include/Lights/Environment.hpp"

Environment::Environment() {}

Environment::~Environment() {}

void Environment::setTexture(std::string path, double intensity) {
    std::ifstream file(path);
    std::string line;
    std::getline(file, line);

    _colors.resize(0);
    if (line != "P6") {
        std::cerr << "Invalid PPM file" << std::endl;
        return;
    }
    std::getline(file, line);
    std::istringstream iss(line);
    int width, height;
    iss >> width >> height;
    std::getline(file, line);
    _colors.resize(height);
    for (int i = 0; i < height; i++) {
        _colors[i].resize(width);
        for (int j = 0; j < width; j++) {
            std::vector<char> rgb(3);
            file.read(&rgb[0], 3);
            _colors[i][j] = Color(
                (unsigned char)rgb[0] / 255.0,
                (unsigned char)rgb[1] / 255.0,
                (unsigned char)rgb[2] / 255.0
            ) * intensity;
        }
    }
    file.close();
}

Color Environment::getPixel(Vector3d direction)
{
    if (_colors.size() == 0)
        return Color("black");
    double x = (std::atan2(direction.getY(), direction.getX()) + M_PI) / (2 * M_PI);
    double y = std::acos(direction.getZ()) / M_PI;
    int i = y * _colors.size();
    int j = x * _colors[0].size();
    return _colors[i][j];
}