/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** parser
*/

#include "../../include/Parser/Parser.hpp"
#include "../../include/Error/Error.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool Parser::fileExist(const std::string &name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

bool Parser::it_cfg_file(std::string file)
{
    std::string cfg = ".cfg";
    std::string::size_type found = file.find(cfg);

    if (found == std::string::npos)
        return false;
    return true;
}

bool Parser::parser(int ac, char **av)
{
    try {
        if (ac < 2)
            throw err::ErrorNotEnoughArg();
        if (ac > 3)
            throw err::ErrorTooMuchArg();
        if (!fileExist(av[1]))
            throw err::ErrorFileNotExist();
        if (!it_cfg_file(av[1]))
            throw err::ErrorTypeFile();
        parseConfig(av[1]);
        return true;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return false;
}

std::vector<std::string> Parser::remove_comment(std::vector<std::string> tokens)
{
    std::vector<std::string> new_tokens;

    for (std::string token : tokens) {
        for (size_t i = 0; i < token.size(); i++)
            if (token[i] == '#') {
                token = token.substr(0, i);
                break;
            }
        new_tokens.push_back(token);
    }
    return new_tokens;
}

std::string Parser::parseConfig(std::string path)
{
    std::ifstream f(path);
    std::string str;
    std::string scene;
    while (std::getline(f, str)) {
        scene += str;
        scene += '\n';
    }
    std::vector<std::string> tokens = StringUtils::split(scene, "\n");
    tokens = remove_comment(tokens);
    recup_camera camera;
    recup_light light;
    recup_primitive primitive;
    recup_effect effect;
    camera.set_info(tokens);
    _camera = camera.get_info();
    primitive.set_info(tokens);
    _primitives = primitive.get_info();
    light.set_info(tokens);
    _lights = light.get_info();
    effect.set_info(tokens);
    _effect = effect.get_info();
    return scene;
}

camera_t Parser::get_camera_from_pars()
{
    return _camera;
}

light_t Parser::get_light_from_pars()
{
    return _lights;
}

std::vector<primitive_t> Parser::get_primitive_from_pars()
{
    return _primitives;
}

effect_t Parser::get_effect_from_pars()
{
    return _effect;
}
