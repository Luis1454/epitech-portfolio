/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveNewEntity
*/

#include "ReceiveNewEntity.hpp"

#include "../../server/ECS/Entities/Entity.hpp"
#include "../../server/ECS/Components/Player.hpp"
#include "../../server/ECS/Components/Enemy.hpp"
#include "../../server/ECS/Components/Health.hpp"
#include "../../server/ECS/Components/Boss.hpp"
#include "../../client/Components/LifeBar.hpp"
#include "../../client/Components/Sprite.hpp"

template<typename T>
ReceiveNewEntity<T>::ReceiveNewEntity()
{
    this->_type = "Receive New Entity";
}

template<typename T>
ReceiveNewEntity<T>::~ReceiveNewEntity()
{
}

template<typename T>
void ReceiveNewEntity<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    std::size_t id = buffer.toType(8, 16);

    if (ecs.getElement<Entity>(id, true) == nullptr)
        ecs.addEntity(id, std::make_shared<Entity>());

    std::shared_ptr<Position> pos = ecs.getElement<Position>(0);
    if (pos == nullptr) {
        std::cout << "Position not found" << std::endl;
        return;
    }

    std::shared_ptr<Sprite> sprite = ecs.getElement<Sprite>(0);
    if (sprite == nullptr) {
        std::cerr << "Sprite component not found!" << std::endl;
        return;
    }

    std::vector<std::function<void()>> handlers = {
        0,
        [&]() { ecs.getElement<Player>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); },
        [&]() { ecs.getElement<Boss>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); },
        [&]() { ecs.getElement<Enemy>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); },
        [&]() { ecs.getElement<Position>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); },
        [&]() { ecs.getElement<Velocity>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); },
        [&]() { ecs.getElement<Health>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); },
        [&]() { ecs.getElement<Projectiles>(0)->addEntity(id, ecs.getElement<Entity>(id, true)); }
    };

    std::vector<std::function<bool()>> validator = {
        0,
        [&]() { return ecs.getElement<Player>(0) != nullptr; },
        [&]() { return ecs.getElement<Boss>(0) != nullptr; },
        [&]() { return ecs.getElement<Enemy>(0) != nullptr; },
        [&]() { return ecs.getElement<Position>(0) != nullptr; },
        [&]() { return ecs.getElement<Velocity>(0) != nullptr; },
        [&]() { return ecs.getElement<Health>(0) != nullptr; },
        [&]() { return ecs.getElement<Projectiles>(0) != nullptr; }
    };

    std::map<std::size_t, std::string> textureName = {
        {ComponentType::e_Player, "player"},
        {ComponentType::e_Boss, "boss"},
        {ComponentType::e_Enemy, "enemy"},
        {ComponentType::e_Projectile, "projectile"}
    };

    bool displayed = false;
    for (int i = 0; i < buffer.size(); i++) {
        int type = buffer.toType(24 + i * 8, 8);

        if (!type)
            break;

        if (type < handlers.size() && validator[type]()) {
            handlers[type]();
            if ((type == ComponentType::e_Player || type == ComponentType::e_Projectile
            || type == ComponentType::e_Enemy || type == ComponentType::e_Boss) && !displayed) {
                displayed = true;

                if (pos->getEntity(id) == nullptr)
                    pos->addEntity(id, ecs.getElement<Entity>(id, true));

                if (sprite->getEntity(id) == nullptr)
                    sprite->addEntity(id, ecs.getElement<Entity>(id, true));

                std::string name = "";
                if (textureName.find(type) != textureName.end())
                    name = textureName[type];
                sprite->setSprite("entity_"+std::to_string(id), sprite->getTexture(name));
                sprite->addPlayer(id, "entity_"+std::to_string(id));

                sf::Sprite &s = sprite->getSprite("entity_"+std::to_string(id));

                if (type == ComponentType::e_Boss)
                    s.setScale(1, 1);
                else
                    s.setScale(0.2, 0.2);
                s.setPosition(pos->getX(id), pos->getY(id));
                s.setOrigin(
                    s.getGlobalBounds().width / 2,
                    s.getGlobalBounds().height / 2
                );
            }
            if (type == ComponentType::e_Health) {
                std::shared_ptr<Health> health = ecs.getElement<Health>(0);

                if (health && health->getEntity(id) == nullptr) {
                    health->addEntity(id, ecs.getElement<Entity>(id, true));
                    health->setHealth(id, 100);
                }
                std::shared_ptr<LifeBar> life = ecs.getElement<LifeBar>(0);
                if (life != nullptr && life->getEntity(id) == nullptr) {
                    life->addEntity(id, ecs.getElement<Entity>(id, true));
                    life->addLifeBar(id, std::make_shared<HealthBar>(0, 100, health->getHealth(id),
                    sf::Vector2f(pos->getX(id), pos->getY(id) - 10)));
                }
            }
            if (type == ComponentType::e_Projectile) {
                std::shared_ptr<Projectiles> proj = ecs.getElement<Projectiles>(0);

                if (proj != nullptr && proj->getEntity(id) != nullptr) {
                    proj->setDamage(id, 1);
                    proj->setName(id, "Projectile #"+std::to_string(id));
                }
            }

            if (type == ComponentType::e_Boss) {
                Level &lvl = ecs.getTrack().getLevel(ecs.getTrack().getCurrentLevel());
                std::shared_ptr<Boss> boss = ecs.getElement<Boss>(0);
                std::shared_ptr<Health> health = ecs.getElement<Health>(0);

                if (boss != nullptr && boss->getEntity(id) == nullptr)
                    boss->addEntity(id, ecs.getElement<Entity>(id, true));

                if (health != nullptr && health->getEntity(id) == nullptr)
                    health->addEntity(id, ecs.getElement<Entity>(id, true));

                health->setHealth(id, lvl.getBossHP());
                health->setMaxHealth(id, lvl.getBossHP());
                health->setMinHealth(id, 0);

                std::shared_ptr<LifeBar> life = ecs.getElement<LifeBar>(0);
                if (life != nullptr) {
                    if (life->getEntity(id) == nullptr)
                        life->addEntity(id, ecs.getElement<Entity>(id, true));

                    life->addLifeBar(id, std::make_shared<HealthBar>(0, lvl.getBossHP(), health->getHealth(id),
                    sf::Vector2f(pos->getX(id), pos->getY(id) - 50)));
                }
            }
        }
    }
    buffer.clear();
    buffer.append(0);
}
