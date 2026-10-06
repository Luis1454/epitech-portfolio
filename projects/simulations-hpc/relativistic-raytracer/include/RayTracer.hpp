/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** RayTracer.hpp
*/

#ifndef RAYTRACER_HPP_
    #define RAYTRACER_HPP_

    #include "Parser/Parser.hpp"
    #include "Objects/Object.hpp"
    #include "Physics/Light.hpp"
    #include "Engine/Camera.hpp"
    #include "Engine/Scene.hpp"
    #include "Engine/Renderer.hpp"
    #include "Engine/Exporter.hpp"

    #include <SFML/Graphics.hpp>
    #include <memory>
    #include <ctime>
    #include <thread>
    #include <algorithm>
    #include <queue>
    #include <mutex>
    #include <future>

    #define BOUNCES 5
    #define MAX_THREADS 32
    #define TILE_SIZE {100, 100}

class RayTracer {
    public:
        RayTracer();
        ~RayTracer();

        void initRayTracer(Parser pars, int sfml);

    private:
        Scene _scene;
        Renderer _renderer;
};

#endif /* RAYTRACER_HPP_ */
