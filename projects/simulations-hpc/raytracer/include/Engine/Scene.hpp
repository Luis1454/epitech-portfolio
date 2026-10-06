/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

#include "../Objects/Object.hpp"
#include "../Physics/Light.hpp"

#include "../Lights/Directional.hpp"
#include "../Lights/Ambient.hpp"
#include "../Lights/LightPoint.hpp"
#include "../Lights/Environment.hpp"

#include "../Effects/Bloom.hpp"
#include "../Effects/Clamp.hpp"
#include "../Effects/GaussianBlur.hpp"

#include "../Parser/Parser.hpp"
#include "Camera.hpp"

class Scene {
    public:
        Scene();
        ~Scene();

        void traceRay(Ray &ray, std::shared_ptr<Light> &light, Environment &env, int n = 0);
        bool isInObject(Vector3d point, ObjectList &obj);
        void addObject(std::shared_ptr<AObject> object);
        void setupCamera(Parser pars);
        void setupLights(Parser pars);
        void setupAmbient();
        void setupEnvironment();
        void setupDirectionals();
        void setupLightPoints();
        void setupPrimitives(Parser pars);
        void setupRayTracer(Parser pars);
        void setupEffects(Parser pars);

        Camera getCamera();
        Light getLight();
        std::vector<std::shared_ptr<Light>> getLights();
        camera_t getCameraPars();
        light_t getLightPars();
        ObjectList getObjects();
        effect_t getEffect();
        Environment env;

    private:
        std::vector<std::shared_ptr<Light>> _lights;
        ObjectList _objects;
        std::vector<primitive_t> primitives;
        Camera _cam;
        camera_t _camera;
        Light light;
        light_t _light;
        effect_t _effect;

};

#endif /* !SCENE_HPP_ */
