/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Exporter
*/

#include "../../include/RayTracer.hpp"

Exporter::Exporter()
{
}

Exporter::~Exporter()
{
}

void Exporter::createFile(std::string file)
{
    std::ofstream ofs(file, std::ios::out | std::ios::binary);
    ofs.close();
}

void Exporter::writeImage(std::string file, Image img)
{
    createFile(file);
    std::ofstream ofs(file, std::ios::out | std::ios::binary);
    ofs << "P6\n" << img.size() << " " << img.front().size() << "\n255\n";
    for (std::size_t i = 0; i < img.front().size(); i++)
        for (std::size_t j = 0; j < img.size(); j++) {
            ofs << (unsigned char)(img[j][i].getR() * 255)
                << (unsigned char)(img[j][i].getG() * 255)
                << (unsigned char)(img[j][i].getB() * 255);
        }
    ofs.close();
}
