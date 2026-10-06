#ifndef RENDER_HPP_
#define RENDER_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "../Components/Sprite.hpp"
#include "../server/ECS/Systems/System.hpp"

class Render : public System {
    public:
        Render(sf::RenderWindow& window);
        ~Render() = default;
        void update() override;

    private:
        sf::RenderWindow& _window;
};

#endif // RENDER_HPP
