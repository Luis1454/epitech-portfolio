/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_effect
*/

#ifndef RECUP_EFFECT_HPP_
    #define RECUP_EFFECT_HPP_

    #include "IParsingSection.hpp"
    #include "StringUtils.hpp"

    typedef struct effect_s {
        float bloom_threshold;
        float bloom_sigma;
        float bloom_radius;
        float chromaticAberration;
        float gaussianBlur_sigma;
        float gaussianBlur_radius;
    } effect_t;

class recup_effect : public IParsingSection<effect_t> {
    public:
        recup_effect();
        ~recup_effect();
        void set_info(std::vector<std::string> tokens) override;
        effect_t get_info() const override;
    private:
        effect_t extract_effect_info(const std::string& token, effect_t effect);
        effect_t _effect;
        StringUtils _stringutils;
};

#endif /* !RECUP_EFFECT_HPP_ */
