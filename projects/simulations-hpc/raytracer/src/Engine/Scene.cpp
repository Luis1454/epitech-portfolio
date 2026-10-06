/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** Scene
*/

#include "../../include/RayTracer.hpp"
#include "../../include/Physics/Ray.hpp"
#include "../../include/Objects/Circle.hpp"
#include "../../include/Objects/Sphere.hpp"
#include "../../include/Objects/Cylinder.hpp"
#include "../../include/Objects/Triangle.hpp"
#include "../../include/Objects/Plane.hpp"
#include "../../include/Objects/Rect.hpp"
#include "../../include/Objects/Cube.hpp"

Scene::Scene()
{
    env = Environment();
}

Scene::~Scene() {}

bool Scene::isInObject(Vector3d point, ObjectList &obj) {
    for (auto &o : obj)
        if (o->getPosition().distance(point) < o->getSize())
            return true;
    return false;
}

void Scene::traceRay(Ray &ray, std::shared_ptr<Light> &light, Environment &env, int n) {
    ObjectList stack;

    if (n > BOUNCES)
        return;
    for (auto &obj : _objects)
        if (obj->intersect(ray))
            stack.push_back(obj);
    std::sort(stack.begin(), stack.end(), [&](std::shared_ptr<AObject> a, std::shared_ptr<AObject> b) {
        return a->getLastIntersect().distance(ray.getOrigin()) < b->getLastIntersect().distance(ray.getOrigin());
    });

    for (auto &obj : stack) {
        Ray r;

        r.setColor(Color(0, 0, 0));
        r.setDirection(ray.getDirection());
        r.setOrigin(obj->getLastIntersect() + obj->getNormal(obj->getLastIntersect()) * 1e-9);
        if (light->isVisible(_objects, r))
            light->illuminate(r, obj->getNormal(r.getOrigin()));
        if (!isInObject(r.getOrigin(), _objects)) {
            obj->reflect(r);
            traceRay(r, light, env, n + 1);
            ray.setColor((ray.getColor() + r.getColor() * obj->getColor()).lowCut());
        }
        if (obj->getColor().getA() == 1)
            break;
    }
    Ray tmp = ray;
    light->illuminate(tmp, Vector3d(0, 0, 0));
    if (ray.getColor() <= tmp.getColor()) {
        light->illuminate(ray, Vector3d(0, 0, 0));
        ray.setColor(ray.getColor() + env.getPixel(ray.getDirection()));
    }
}

void Scene::addObject(std::shared_ptr<AObject> object)
{
    std::shared_ptr<AObject> obj = object;
    _objects.push_back(obj);
}

void Scene::setupCamera(Parser pars)
{
    _camera = pars.get_camera_from_pars();
    _cam.setSize(_camera.width, _camera.height);
    _cam.setFov(_camera.fov);
    _cam.setDirection(Vector3d(_camera.dir_x, _camera.dir_y, _camera.dir_z));
    _cam.rotate(Vector3d(_camera.rot_x, _camera.rot_y, _camera.rot_z), M_PI / 4);
    _cam.setPosition(Vector3d(_camera.pos_x, _camera.pos_y, _camera.pos_z));
}

void Scene::setupLightPoints()
{
    LightPoint point;

    for (auto &light : _light.points) {
        point.setPosition(Vector3d(light.x, light.y, light.z));
        point.setIntensity(light.intensity);
        point.setColor(Color(1, 1, 1));
        point.setRadius(light.diffuse);
        _lights.push_back(std::make_shared<LightPoint>(point));
    }
}

void Scene::setupAmbient()
{
    Ambient ambient;

    ambient.setIntensity(_light.ambient.intensity);
    ambient.setColor(Color(_light.ambient.r, _light.ambient.g, _light.ambient.b) / 255);
    _lights.push_back(std::make_shared<Ambient>(ambient));
}

void Scene::setupDirectionals()
{
    Directional direct;

    for (auto &light : _light.directionals) {
        direct.setDirection(Vector3d(light.r, light.g, light.b));
        direct.setIntensity(light.intensity);
        direct.setColor(Color(1, 1, 1));
        _lights.push_back(std::make_shared<Directional>(direct));
    }
}

void Scene::setupEnvironment()
{
    if (_light.envTexturePath == "")
        return;
    env.setTexture(_light.envTexturePath, _light.envIntensity);
    std::cout << "Environment texture \"" << _light.envTexturePath << "\" loaded" << std::endl;
}

void Scene::setupLights(Parser pars)
{
    _light = pars.get_light_from_pars();
    setupAmbient();
    setupLightPoints();
    setupDirectionals();
    setupEnvironment();
}

void Scene::setupPrimitives(Parser pars)
{
    std::vector<primitive_t> primitives = pars.get_primitive_from_pars();
    Vector3d normal;
    Vector3d pos;
    Color color;

    auto createPrimitive = [&](const primitive_t& primitive) -> std::shared_ptr<AObject> {
        pos = Vector3d(primitive.pos_x, primitive.pos_y, primitive.pos_z);
        color = Color(primitive.color_r, primitive.color_g, primitive.color_b) / 255;
        color.setA(1 - primitive.transparency);
        normal = Vector3d(primitive.normal_x, primitive.normal_y, primitive.normal_z);

        if (primitive.type == "circle")
            return std::make_shared<Circle>(primitive.radius, pos, color, normal);
        if (primitive.type == "sphere")
            return std::make_shared<Sphere>(primitive.radius, pos, color);
        if (primitive.type == "cylinder")
            return std::make_shared<Cylinder>(primitive.radius, primitive.height, pos, normal, color);
        if (primitive.type == "rectangle")
            return std::make_shared<Rect>(Vector3d(primitive.size_x,
                primitive.size_y, primitive.size_z), pos, color);
        if (primitive.type == "plane")
            return std::make_shared<Plane>(pos, normal, color);
        return std::shared_ptr<AObject>(nullptr);
    };

    for (auto &primitive : primitives) {
        auto object = createPrimitive(primitive);
        if (object != nullptr)
            _objects.push_back(object);
    }
}

void Scene::setupEffects(Parser pars)
{
    _effect = pars.get_effect_from_pars();
}

void Scene::setupRayTracer(Parser pars)
{
    setupCamera(pars);
    setupLights(pars);
    setupPrimitives(pars);
    setupEffects(pars);
}

Camera Scene::getCamera()
{
    return _cam;
}

Light Scene::getLight()
{
    return light;
}

std::vector<std::shared_ptr<Light>> Scene::getLights()
{
    return _lights;
}

camera_t Scene::getCameraPars()
{
    return _camera;
}

light_t Scene::getLightPars()
{
    return _light;
}

ObjectList Scene::getObjects()
{
    return _objects;
}

effect_t Scene::getEffect()
{
    return _effect;
}
