/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** SendGameEvent
*/

#include "SendGameEvent.hpp"
#include "../../server/Track.hpp"

template <typename T>
SendGameEvent<T>::SendGameEvent() {
    this->_type = "Send Game Event";
}

template <typename T>
void SendGameEvent<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    long long id = buffer.toType(8, 16);
    int type = buffer.toType(24, 8);

    std::shared_ptr<Player> player = nullptr;
    int score = 0;

    buffer.reshape(64 / (sizeof(T) * 8));
    buffer.overwrite(32, this->toVector(0), 32);

    Level &level = ecs.getTrack().getLevel(ecs.getTrack().getCurrentLevel());

    buffer.overwrite(0, this->toVector(18), 8);

    switch (type) {
        case evt_gameStart:
            buffer.overwrite(32, this->toVector(ecs.getTrack().getLevels().size()), 8);
            break;
        case evt_gameOver:
            buffer.overwrite(32, this->toVector(ecs.getTrack().getCurrentLevel()), 8);
            break;
        case evt_gameWon:
            buffer.overwrite(32, this->toVector(ecs.getTrack().getCurrentLevel()), 8);
            break;
        case evt_playerScore:
            player = ecs.getElement<Player>(0);
            if (player == nullptr || player->getEntity(id) == nullptr) {
                buffer.clear();
                buffer.append(0);
                return;
            }
            score = player->getScore(id);
            buffer.overwrite(32, this->toVector(score), 32);
            break;
        case evt_LevelStart:
            buffer.overwrite(32, this->toVector(ecs.getTrack().getCurrentLevel()), 8);
            buffer.overwrite(40, this->toVector(level.getNbEnemies()), 8);
            buffer.overwrite(48, this->toVector(level.getLevelDuration()), 8);
            break;
        case evt_LevelEnd:
            buffer.overwrite(32, this->toVector(ecs.getTrack().getCurrentLevel()), 8);
            break;
        case evt_EnemyCount:
            buffer.overwrite(32, this->toVector(level.getNbEnemies()), 8);
            break;
        case evt_playerDeath:
            buffer.overwrite(32, this->toVector(ecs.getTrack().getCurrentLevel()), 8);
            break;
        default:
            break;
    }
}
