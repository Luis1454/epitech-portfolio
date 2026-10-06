/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** story.hpp
*/

#ifndef STORY_HPP_
#define STORY_HPP_

#include <SFML/Graphics.hpp>

class Story {
public:
    Story();
    ~Story() = default;
    void update();
    void render(sf::RenderWindow &window);
    bool handleEvents(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);


private:
    std::string loadStoryFromJson(const std::string& filePath);
    std::string wrapText(const std::string& text, float maxWidth, const sf::Font& font, unsigned int characterSize);
    sf::Font font;
    sf::Text text;
    std::string storyText;
    std::string visibleText;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    size_t charIndex;
    sf::Clock clock;
    float scrollSpeed;
};
#endif