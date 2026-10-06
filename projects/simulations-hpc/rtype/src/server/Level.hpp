/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Level
*/

#ifndef LEVEL_HPP_
#define LEVEL_HPP_

#include <string>
#include <vector>

class Level {
    public:
        Level();
        Level(std::string name, std::size_t nbEnemies, std::size_t enemyHP,
            std::size_t enemySpeed, std::size_t bossHP);
        Level(std::string name, std::size_t nbEnemies, std::size_t enemyHP, 
            std::size_t enemySpeed, std::size_t bossHP, float levelDuration, float transitionDuration);
        ~Level();

        std::string getName() const;
        std::size_t getNbEnemies() const;
        std::size_t getEnemyHP() const;
        std::size_t getEnemySpeed() const;
        std::size_t getBossHP() const;
        std::size_t getKilledEnemies() const;

        void setName(std::string name);
        void setNbEnemies(std::size_t nbEnemies);
        void setEnemyHP(std::size_t enemyHP);
        void setEnemySpeed(std::size_t enemySpeed);
        void setBossHP(std::size_t bossHP);
        void setKilledEnemies(std::size_t killedEnemies);
        void killEnemy();

        void setTransitionDuration(float duration);
        void setLevelDuration(float duration);

        float getTransitionDuration() const;
        float getLevelDuration() const;

        bool isFinished() const;

    private:
        std::string _name;
        std::size_t _killedEnemies;
        std::size_t _nbEnemies;
        std::size_t _enemyHP;
        std::size_t _enemySpeed;
        std::size_t _bossHP;

        float _levelDuration;
        float _transitionDuration;
};

#endif /* !LEVEL_HPP_ */
