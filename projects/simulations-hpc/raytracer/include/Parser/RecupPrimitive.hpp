/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_primitive
*/

#ifndef RECUP_PRIMITIVE_HPP_
    #define RECUP_PRIMITIVE_HPP_

    #include <algorithm>

    #include "IParsingSection.hpp"
    #include "StringUtils.hpp"

    typedef struct primitive_s {
        std::string type;
        float pos_x;
        float pos_y;
        float pos_z;
        float size_x;
        float size_y;
        float size_z;
        float radius;
        float height;
        float color_r;
        float color_g;
        float color_b;
        float transparency;
        float normal_x;
        float normal_y;
        float normal_z;
    } primitive_t;

class recup_primitive : public IParsingSection<std::vector<primitive_t>> {
    public:
        recup_primitive();
        ~recup_primitive();
        void set_info(std::vector<std::string> tokens) override;
        std::vector<primitive_t> get_info() const override;
    private:
        primitive_t extract_primitive_info(const std::string& token, primitive_t prim);
        std::vector<primitive_t> _primitives;
        StringUtils _stringutils;
};

#endif /* !RECUP_PRIMITIVE_HPP_ */
