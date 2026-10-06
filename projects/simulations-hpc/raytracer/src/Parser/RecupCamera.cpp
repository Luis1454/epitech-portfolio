/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_camera
*/

#include "../../include/Parser/RecupCamera.hpp"
#include "../../include/Error/Error.hpp"

recup_camera::recup_camera()
{
}

recup_camera::~recup_camera() {}

camera_t recup_camera::extract_camera_info(const std::string& token, camera_t camera)
{
    std::istringstream iss(token);
    std::string key;
    iss >> key;
    if (key == "resolution") {
        camera.width = _stringutils.extract(token, "width", 1920);
        camera.height = _stringutils.extract(token, "height", 1080);
        if (camera.width < 0 || camera.height < 0)
            throw err::ErrorWindowResolution();
    } else if (key == "position") {
        camera.pos_x = _stringutils.extract(token, "x", 0);
        camera.pos_y = _stringutils.extract(token, "y", 0);
        camera.pos_z = _stringutils.extract(token, "z", 0);
    } else if (key == "direction") {
        camera.dir_x = _stringutils.extract(token, "x", 0);
        camera.dir_y = _stringutils.extract(token, "y", 0);
        camera.dir_z = _stringutils.extract(token, "z", 0);
    } else if (key == "rotation") {
        camera.rot_x = _stringutils.extract(token, "x", 0);
        camera.rot_y = _stringutils.extract(token, "y", 0);
        camera.rot_z = _stringutils.extract(token, "z", 0);
    } else if (key == "fieldOfView") {
        char discard;
        iss >> discard >> camera.fov;
        if (camera.fov < 0 || camera.fov > 180)
            throw err::ErrorFieldOfViewNotInRange();
    }
    return camera;
}

void recup_camera::set_info(std::vector<std::string> tokens)
{
    bool camera_block = false;

    _camera.width = 1920;
    _camera.height = 1080;
    _camera.pos_x = 0;
    _camera.pos_y = 0;
    _camera.pos_z = 0;
    _camera.dir_x = 1;
    _camera.dir_y = 0;
    _camera.dir_z = 0;
    _camera.rot_x = 0;
    _camera.rot_y = 0;
    _camera.rot_z = 0;
    _camera.fov = 65;
    for (const auto& token : tokens) {
        if (token.find("camera") != std::string::npos) {
            camera_block = true;
            continue;
        }
        if (camera_block) {
            if (token[0] == '}' && token[1] == ';') {
                camera_block = false;
                continue;
            }
            _camera = extract_camera_info(token, _camera);
        }
    }
}

camera_t recup_camera::get_info() const
{
    return _camera;
}
