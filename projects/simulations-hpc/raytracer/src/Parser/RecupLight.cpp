/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_light
*/

#include "../../include/Parser/RecupLight.hpp"
#include "../../include/Error/Error.hpp"

recup_light::recup_light() {}

recup_light::~recup_light() {}

void recup_light::extract_light_info(const std::string& token)
{
    std::istringstream iss(token);
    std::string key;
    iss >> key;
    if (key == "environment") {
        _lights.envTexturePath = _stringutils.recup_string("path", token);
        _lights.envIntensity = _stringutils.extract(token, "intensity", 1);
    }
    if (key == "ambient") {
        _lights.ambient = {0, 0, 0, 0};
        _lights.ambient.intensity = _stringutils.extract(token, "intensity", 0.5);
        _lights.ambient.r = _stringutils.extract(token, "r", 1);
        _lights.ambient.g = _stringutils.extract(token, "g", 1);
        _lights.ambient.b = _stringutils.extract(token, "b", 1);
        if (_lights.ambient.r < 0 || _lights.ambient.r > 255
        || _lights.ambient.g < 0 || _lights.ambient.g > 255
        || _lights.ambient.b < 0 || _lights.ambient.b > 255)
            throw err::ErrorColorNotInRange();
        if (_lights.ambient.intensity < 0)
            throw err::ErrorIntensityNotPositive();
    } else if (key == "point") {
        point_t point;
        point.x = _stringutils.extract(token, "x", 0);
        point.y = _stringutils.extract(token, "y", 0);
        point.z = _stringutils.extract(token, "z", 2);
        point.diffuse = _stringutils.extract(token, "diffuse", 0.5);
        if (point.diffuse < 0 || point.diffuse > 1)
            throw err::ErrorDiffuseNotInRange();
        point.specular = _stringutils.extract(token, "specular", 0.5);
        if (point.specular < 0 || point.specular > 1)
            throw err::ErrorSpecular();
        point.intensity = _stringutils.extract(token, "intensity", 50);
        if (point.intensity < 0)
            throw err::ErrorIntensityNotPositive();
        _lights.points.push_back(point);
    } else if (key == "directional") {
        directional_t directional;
        directional.r = _stringutils.extract(token, "x", 1);
        directional.g = _stringutils.extract(token, "y", 1);
        directional.b = _stringutils.extract(token, "z", 1);
        directional.intensity = _stringutils.extract(token, "intensity", 0.5);
        if (directional.intensity < 0)
            throw err::ErrorIntensityNotPositive();
        _lights.directionals.push_back(directional);
    }
}

void recup_light::set_info(std::vector<std::string> tokens)
{
    bool light_block = false;

    for (const auto& token : tokens) {
        if (token.find("lights") != std::string::npos) {
            light_block = true;
            continue;
        }
        if (light_block) {
            if (token[0] == '}' && token[1] == ';') {
                light_block = false;
                continue;
            }
            extract_light_info(token);
        }
    }
}

light_t recup_light::get_info() const
{
    return _lights;
}
