/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Scoreboard
*/

#ifndef SCOREBOARD_HPP_
#define SCOREBOARD_HPP_

#include "Info.hpp"

class Scoreboard : public sf::Drawable {
    public:
        Scoreboard();
        ~Scoreboard();

        void setInfo(std::string name, Info info);
        std::map<std::string, Info> getInfos() const;

        void setBackground(sf::RectangleShape background);
        sf::RectangleShape &getBackground();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    private:
        sf::RectangleShape _background;
        std::map<std::string, Info> _infos;
};

#endif /* !SCOREBOARD_HPP_ */
