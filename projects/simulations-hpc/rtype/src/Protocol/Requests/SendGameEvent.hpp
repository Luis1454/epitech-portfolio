/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** SendGameEvent
*/

#ifndef SendGameEvent_HPP_
#define SendGameEvent_HPP_

#include "Request.hpp"
#include "../../server/ECS/Components/Velocity.hpp"

typedef enum EventType_s {
    evt_gameStart,
    evt_gameOver,
    evt_gameWon,
    evt_playerScore,
    evt_LevelStart,
    evt_LevelEnd,
    evt_EnemyCount,
    evt_playerDeath,
} EventType;

template <typename T>
class SendGameEvent : public Request<T> {
    public:
        SendGameEvent();
        ~SendGameEvent() = default;

        void execute(Buffer<T> &buffer, ECS &ecs) override;
};

template class SendGameEvent<uint64_t>;
template class SendGameEvent<char>;
template class SendGameEvent<Byte>;
template class SendGameEvent<int>;

#endif /* !SendGameEvent_HPP_ */
