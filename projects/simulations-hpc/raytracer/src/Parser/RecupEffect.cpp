/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-raytracer-alexis.salaun
** File description:
** recup_effects
*/

#include "../../include/Parser/RecupEffect.hpp"
#include "../../include/Error/Error.hpp"

recup_effect::recup_effect()
{
}

recup_effect::~recup_effect()
{
}

effect_t recup_effect::extract_effect_info(const std::string& token, effect_t effect)
{
    std::istringstream iss(token);
    std::string key;
    iss >> key;
    if (key == "bloom") {
        effect.bloom_threshold = _stringutils.extract(token, "threshold", 0.8);
        if (effect.bloom_threshold < 0 || effect.bloom_threshold > 1)
            throw err::ErrorThresholdNotInRange();
        effect.bloom_sigma = _stringutils.extract(token, "sigma", 100);
        if (effect.bloom_sigma < 0)
            throw err::ErrorSigmaNotPositive();
        effect.bloom_radius = _stringutils.extract(token, "radius", 50);
        if (effect.bloom_radius < 0)
            throw err::ErrorRadius();
    }
    if (key == "chromaticAberration")
        effect.chromaticAberration = _stringutils.extract(token, key, 0.5);
    if (key == "gaussianBlur") {
        effect.gaussianBlur_sigma = _stringutils.extract(token, "sigma", 1);
        if (effect.gaussianBlur_sigma < 0 || effect.gaussianBlur_sigma > 1)
            throw err::ErroraGaussianBlurSigma();
        effect.gaussianBlur_radius = _stringutils.extract(token, "radius", 0);
        if (effect.gaussianBlur_radius < 0)
            throw err::ErroraGaussianBlurRadius();
    }
    return effect;
}

void recup_effect::set_info(std::vector<std::string> tokens)
{
    bool effect_block = false;

    _effect.bloom_threshold = -1;
    _effect.bloom_sigma = 100;
    _effect.bloom_radius = 50;
    _effect.chromaticAberration = 0.5;
    _effect.gaussianBlur_sigma = -1;
    _effect.gaussianBlur_radius = 0;
    for (const auto& token : tokens) {
        if (token.find("effects") != std::string::npos) {
            effect_block = true;
            continue;
        }
        if (effect_block) {
            if (token[0] == '}' && token[1] == ';') {
                effect_block = false;
                continue;
            }
            _effect = extract_effect_info(token, _effect);
        }
    }
}

effect_t recup_effect::get_info() const
{
    return _effect;
}
