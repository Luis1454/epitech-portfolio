/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Egg.hpp
*/

#ifndef EGG_HPP_
#define EGG_HPP_

#include <memory>
#include "Team.hpp"
#include <SFML/Graphics.hpp>

class Egg : public sf::Drawable {
    public:
        Egg();
        Egg(int id);
        Egg(int eggId, int playerId, sf::Vector2i pos, std::shared_ptr<sf::Sprite> sprite);
        ~Egg();

        int getId() const;
        void setId(int id);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
        sf::Vector2i getPosition();
        void setPosition(sf::Vector2i pos);

        std::shared_ptr<sf::Sprite> getSprite();
        void setSprite(std::shared_ptr<sf::Sprite> sprite);

    private:
        int _id;
        int _playerId;
        sf::Vector2i _offset;
        sf::Vector2i _position;
        sf::Vector2f _spriteSize;
        std::shared_ptr<Team> _team;
        std::shared_ptr<sf::Sprite> _sprite;
};

#endif /* !EGG_HPP_ */
