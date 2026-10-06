/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** ChromaticAberration
*/

#include "../../include/Effects/ChromaticAberration.hpp"
#include "../../include/Physics/Vector.hpp"

ChromaticAberration::ChromaticAberration(std::unique_ptr<Effect> imageEffect, double force)
{
    _imageEffect = std::move(imageEffect);
    _force = force;
}

ChromaticAberration::~ChromaticAberration()
{
}

void ChromaticAberration::applyEffect(std::vector<std::vector<Color>> &img)
{
    Image tmp = img;
    Color min = Color(1, 0, 1);
    Color max = Color(0, 1, 1);

    for (size_t i = 0; i < img.size(); i++) {
        for (size_t j = 0; j < img[i].size(); j++) {
            Vector3d dir = (Vector3d(i, j, 0) - Vector3d(img.size() / 2, img[0].size() / 2, 0));
            double dist = std::max(dir.getX(), dir.getY());
            dir.normalize();
            Vector3d offset = dir * _force;
            for (double k = -_force; k <= _force; k += 1.0 / dist) {
                Vector3d pos = Vector3d(i, j, 0) + offset * k;
                if (pos.getX() * (1 + k) >= 0 && pos.getX() * (1 + k) < img.size()
                && pos.getY() * (1 + k) >= 0 && pos.getY() * (1 + k) < img[0].size()) {
                    Color c = min + (max - min) * (k + _force) / (2 * _force);
                    img[i][j] -= tmp[pos.getX() * (1 + k)][pos.getY() * (1 + k)] * c / 10;
                    img[pos.getX() * (1 + k)][pos.getY() * (1 + k)] += tmp[i][j] * c / 10;
                }
            }
        }
    }
}
