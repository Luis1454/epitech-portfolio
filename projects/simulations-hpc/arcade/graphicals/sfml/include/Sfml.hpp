/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../IDisplayModule.hpp"

class Sfml : public IDisplayModule {
    public:
        Sfml();
        ~Sfml();
        void setWindow() override;
        int is_lib() override;
        void drawWindow() override;
        void clear() override;
        void drawRect(int x, int y, int width, int height, Color color, int mode) override;
        void drawCircle(int x, int y, int radius, Color color, int mode) override;
        void drawText(int x, int y, std::string text, Color color, int mode) override;
        void loadFont(std::string path) override;
        int pollEvent() override;
        void closeWindow() override;
        int getKeys() override;
        int getWidth() override;
        int getHeight() override;

    private:
        sf::RenderWindow _window;
        sf::Font _font;
        int _key;
        int _lastKey;
        sf::Color getColor(Color color);
};

sf::Color operator*(sf::Color color, float value)
{
    return sf::Color(color.r * value, color.g * value, color.b * value, color.a * value);
}

sf::Color operator+(sf::Color color, float value)
{
    return sf::Color(color.r + value, color.g + value, color.b + value, color.a + value);
}

sf::Color operator-(sf::Color color, float value)
{
    return sf::Color(color.r - value, color.g - value, color.b - value, color.a - value);
}

#endif /* SFML_HPP_ */
