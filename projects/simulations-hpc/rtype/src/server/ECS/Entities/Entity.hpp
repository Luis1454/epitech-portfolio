/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

typedef enum ComponentType {
    e_None,
    e_Player,
    e_Boss,
    e_Enemy,
    e_Position,
    e_Velocity,
    e_Health,
    e_Projectile
} ComponentType;

class Entity {
    public:
        Entity();
        ~Entity();

    protected:
};

#endif /* !ENTITY_HPP_ */
