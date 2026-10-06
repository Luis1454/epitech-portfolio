/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_light
*/

#ifndef RECUP_LIGHT_HPP_
    #define RECUP_LIGHT_HPP_

    #include "IParsingSection.hpp"
    #include "StringUtils.hpp"

    typedef struct point_s {
        float x;
        float y;
        float z;
        float intensity;
        float diffuse;
        float specular;
    } point_t;

    typedef struct directional_s {
        float r;
        float g;
        float b;
        float intensity;
    } directional_t;

    typedef struct ambient_s {
        float r;
        float g;
        float b;
        float intensity;
    } ambient_t;

    typedef struct light_s {
        ambient_t ambient;
        std::vector<point_t> points;
        std::vector<directional_t> directionals;
        std::string envTexturePath;
        float envIntensity;
    } light_t;

class recup_light : public IParsingSection<light_t> {
    public:
        recup_light();
        ~recup_light();
        void set_info(std::vector<std::string> tokens) override;
        light_t get_info() const override;
    private:
        float extract(std::string token, std::string key, int dflt);
        void extract_light_info(const std::string &token);
        light_t _lights;
        StringUtils _stringutils;
};

#endif /* !RECUP_LIGHT_HPP_ */
