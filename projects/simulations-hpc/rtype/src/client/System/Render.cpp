#include "Render.hpp"
#include "../Components/Sprite.hpp"
#include "../Components/LifeBar.hpp"
#include "../Components/EventMessage.hpp"
#include "../../server/ECS/Components/Boss.hpp"
#include "../../server/ECS/Components/Health.hpp"
#include "../../server/ECS/Components/Position.hpp"

Render::Render(sf::RenderWindow& window) : _window(window) {}

void Render::update() {
    this->_name = "Render";

    std::shared_ptr<Boss> boss = getElement<Boss>(0);
    std::shared_ptr<Position> pos = getElement<Position>(0);
    std::shared_ptr<Sprite> sprite = getElement<Sprite>(0);
    std::shared_ptr<LifeBar> life = getElement<LifeBar>(0);
    std::shared_ptr<Health> health = getElement<Health>(0);
    std::shared_ptr<EventMessage> event = getElement<EventMessage>(0);

    std::map<std::string, std::shared_ptr<Component>> checks = {
        {"Boss", boss},
        {"Position", pos},
        {"LifeBar", life},
        {"Health", health},
        {"Sprite", sprite},
        {"EventMessage", event}
    };

    for (auto &check : checks)
        if (check.second == nullptr) {
            std::cerr << "Component " << check.first << " is missing in render method" << std::endl;
            return;
        }

    for (auto& s : sprite->getEntities()) {
        int x = pos->getX(s.first);
        int y = pos->getY(s.first);
        bool isBoss = boss->getEntity(s.first) != nullptr;
        sprite->getSprite("entity_"+std::to_string(s.first)).setPosition(x, y);
        if (health->getEntity(s.first) != nullptr && life->getEntity(s.first) != nullptr) {
            life->setMinLife(s.first, health->getMinHealth(s.first));
            life->setMaxLife(s.first, health->getMaxHealth(s.first));
            life->setLifeBar(s.first, health->getHealth(s.first));
            life->setPosition(s.first, sf::Vector2f(x + 20, y - (isBoss ? 120 : 20)));
        }
    }

    for (const auto& [id, component] : _components) {
        if (auto sprite = std::dynamic_pointer_cast<Sprite>(component); sprite != nullptr)
            sprite->draw(_window);
        if (auto lifeBar = std::dynamic_pointer_cast<LifeBar>(component); lifeBar != nullptr)
            lifeBar->draw(_window);
    }
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = now - this->_refTime;
    if (elapsed_seconds.count() <= 3.0)
        event->draw(_window);
}
