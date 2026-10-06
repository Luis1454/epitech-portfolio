/*
** EPITECH PROJECT, 2024
** RayTracer.cpp
** File description:
** RayTracer
*/

#include "../include/Physics/Vector.hpp"
#include "../include/Physics/Light.hpp"
#include "../include/Engine/Camera.hpp"
#include "../include/RayTracer.hpp"

RayTracer::RayTracer() {}

RayTracer::~RayTracer() {}

void RayTracer::initRayTracer(Parser pars, int sfml)
{
    _scene.setupRayTracer(pars);
    if (sfml)
        _renderer.initWindow(_scene.getCamera());
    _renderer.render(_scene, sfml);
}
