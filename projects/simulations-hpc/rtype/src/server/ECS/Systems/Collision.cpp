/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Collision
*/

#include "Collision.hpp"

Collision::Collision()
{
    this->_name = "Collision";
}

void Collision::update() {
    std::shared_ptr<Health> healths = getElement<Health>(0);
    std::shared_ptr<RigidBody> bodies = getElement<RigidBody>(0);
    std::shared_ptr<Position> positions = getElement<Position>(0);
    std::shared_ptr<Projectiles> proj = getElement<Projectiles>(0);
    std::shared_ptr<State> state = getElement<State>(0);
    std::shared_ptr<Enemy> enemy = getElement<Enemy>(0);
    std::shared_ptr<Player> player = getElement<Player>(0);

    std::map<std::string, std::shared_ptr<Component>> comps = {
        {"Health", healths},
        {"RigidBody", bodies},
        {"Position", positions},
        {"Projectiles", proj},
        {"State", state},
        {"Enemy", enemy},
        {"Player", player}
    };

    for (auto &c : comps)
        if (c.second == nullptr) {
            std::cout << "Collision : Missing component " << c.first << std::endl;
            return;
        }

    for (auto &b : bodies->getEntities()) {
        int x = positions->getX(b.first);
        int y = positions->getY(b.first);
        bodies->setBody(b.first, sf::FloatRect(x, y, 100, 100));
    }

    std::vector<std::pair<int, int>> collisions = bodies->intersect(bodies->getIDs());
    std::vector<std::pair<int, int>> impacts = bodies->intersect(proj->getIDs());

    for (auto &id : collisions) {
        float relativeX = bodies->getBody(id.first).left - bodies->getBody(id.second).left;
        float relativeY = bodies->getBody(id.first).top - bodies->getBody(id.second).top;

        healths->takeDamages(id.first, std::max(25.0f * _dt, 1.0f));

        // apply knockback
        float knockback = 300.0f * _dt;
        float angle = std::atan2(relativeY, relativeX);
        float knockbackX = knockback * std::cos(angle);
        float knockbackY = knockback * std::sin(angle);
        positions->setX(id.first, positions->getX(id.first) + knockbackX);
        positions->setY(id.first, positions->getY(id.first) + knockbackY);
    }

    for (auto &id : impacts) {
        std::shared_ptr<Entity> e = proj->getEntity(id.second);

        int damage = (e != nullptr ? proj->getDamage(id.second) : 0);

        float relativeX = bodies->getBody(id.first).left - bodies->getBody(id.second).left;
        float relativeY = bodies->getBody(id.first).top - bodies->getBody(id.second).top;

        if (relativeX > 0)
            healths->takeDamages(id.first, damage);
    }

    for (auto &id : impacts) {
        std::shared_ptr<Entity> isAProj = proj->getEntity(id.first);
        std::shared_ptr<Entity> isBProj = proj->getEntity(id.second);
        std::shared_ptr<Entity> isAEnemy = enemy->getEntity(id.first);
        std::shared_ptr<Entity> isBEnemy = enemy->getEntity(id.second);
        std::shared_ptr<Entity> s = state->getEntity(id.second);
        std::size_t emitter = proj->getEmitter(id.second);

        if (player->getEntity(emitter) == nullptr)
            std::cout << "Projectile emitter not found" << std::endl;

        if (isAEnemy != nullptr && isBProj != nullptr) {
            player->addScore(emitter, proj->getDamage(id.second));
            if (healths->getHealth(id.first) <= 0)
                player->addKill(emitter);
            printf("player score: %d kill: %d\n", player->getScore(emitter), player->getNbKills(emitter));
        }

        if ((isAProj == nullptr && isBProj != nullptr) || s == nullptr)
            state->setState(id.second, StateType::DEAD);
    }
}
