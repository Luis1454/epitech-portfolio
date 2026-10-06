/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_primitive
*/

#include "../../include/Parser/RecupPrimitive.hpp"
#include "../../include/Error/Error.hpp"

recup_primitive::recup_primitive() {}

recup_primitive::~recup_primitive() {}

primitive_t recup_primitive::extract_primitive_info(const std::string& token, primitive_t prim)
{
    std::istringstream iss(token);
    std::string key;
    std::vector<std::string> primitives = {"sphere", "plane", "rectangle", "circle", "triangle",
    "cylinder", "cone", "cube", "pyramid", "torus", "paraboloid", "hyperboloid", "ellipsoid", "mobius", "kleinbottle"};

    iss >> key;
    if (std::find(primitives.begin(), primitives.end(), key) != primitives.end()) {
        prim.type = key;
        prim.pos_x = _stringutils.extract(token, "x", 0);
        prim.pos_y = _stringutils.extract(token, "y", 0);
        prim.pos_z = _stringutils.extract(token, "z", 0);
        prim.radius = _stringutils.extract(token, "radius", 0.5);
        if (prim.radius < 0)
            throw err::ErrorRadius();
        prim.height = _stringutils.extract(token, "height", 1);
        if (prim.height < 0)
            throw err::ErrorHeight();
        prim.size_x = _stringutils.extract(token, "size_x", 1);
        prim.size_y = _stringutils.extract(token, "size_y", 1);
        prim.size_z = _stringutils.extract(token, "size_z", 1);
        if (prim.size_x < 0 || prim.size_y < 0 || prim.size_z < 0)
            throw err::ErrorSize();
        prim.normal_x = _stringutils.extract(token, "normal_x", 0);
        prim.normal_y = _stringutils.extract(token, "normal_y", 0);
        prim.normal_z = _stringutils.extract(token, "normal_z", 0);
        prim.color_r = _stringutils.extract(token, "r", 255);
        prim.color_g = _stringutils.extract(token, "g", 255);
        prim.color_b = _stringutils.extract(token, "b", 255);
        if (prim.color_r < 0 || prim.color_r > 255 || prim.color_g < 0
        || prim.color_g > 255 || prim.color_b < 0 || prim.color_b > 255)
            throw err::ErrorColorNotInRange();
        prim.transparency = _stringutils.extract(token, "transparency", 0);
        if (prim.transparency < 0 || prim.transparency > 1)
            throw err::ErrorTransparency();
    } else
        prim.type = "";
    return prim;
}

void recup_primitive::set_info(std::vector<std::string> tokens)
{
    bool prim_block = false;
    _primitives.clear();

    for (const auto& token : tokens) {
        if (token.find("primitives") != std::string::npos) {
            prim_block = true;
            continue;
        }
        if (prim_block) {
            if (token[0] == '}' && token[1] == ';') {
                prim_block = false;
                continue;
            }
            primitive_t prim;
            prim = extract_primitive_info(token, prim);
            if (prim.type != "")
                _primitives.push_back(prim);
        }
    }
}

std::vector<primitive_t> recup_primitive::get_info() const
{
    return _primitives;
}
