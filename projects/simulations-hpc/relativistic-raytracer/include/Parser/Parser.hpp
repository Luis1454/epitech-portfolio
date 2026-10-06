/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <iostream>
    #include <fstream>
    #include <memory>

    #include "RecupLight.hpp"
    #include "RecupCamera.hpp"
    #include "RecupPrimitive.hpp"
    #include "RecupEffect.hpp"
    #include "StringUtils.hpp"

    typedef struct primitive_s primitive_t;
    typedef struct light_s light_t;
    typedef struct camera_s camera_t;
    typedef struct effect_s effect_t;

class Parser {
    public:
        Parser();
        ~Parser();
        bool it_cfg_file(std::string file);
        bool fileExist(const std::string &name);
        bool parser(int ac, char **av);
        std::string parseConfig(std::string path);
        std::vector<std::string> remove_comment(std::vector<std::string> tokens);
        camera_t get_camera_from_pars();
        light_t get_light_from_pars();
        std::vector<primitive_t> get_primitive_from_pars();
        effect_t get_effect_from_pars();

    private:
        light_t _lights;
        camera_t _camera;
        std::vector<primitive_t> _primitives;
        effect_t _effect;
};

#endif /* !PARSER_HPP_ */
