/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** ReceiveGameEvent
*/

#include "ReceiveGameEvent.hpp"

template<typename T>
ReceiveGameEvent<T>::ReceiveGameEvent() {
    this->_type = "Receive Game Event";
}

template<typename T>
void ReceiveGameEvent<T>::execute(Buffer<T> &buffer, ECS &ecs) {
    long long id = buffer.toType(8, 16);
    std::string msg;
    int nbLvls = 0;
    int lvl = 0;

    std::shared_ptr<EventMessage> eventMessage = ecs.getElement<EventMessage>(0);
    if (eventMessage == nullptr) {
        std::cout << "EventMessage not found" << std::endl;
        return;
    }

    int type = buffer.toType(24, 8);
    std::cout << "Received Game Event: " << type << std::endl;

    ecs.setLastMsgTime(std::chrono::system_clock::now());

    switch (type) {
        case EventType::evt_gameStart:
            nbLvls = buffer.toType(32, 8);
            msg = "Game started (" + std::to_string(nbLvls) + " levels)";
            break;
        case EventType::evt_gameOver:
            msg = "Game over (level " + std::to_string(ecs.getTrack().getCurrentLevel()) + ")";
            break;
        case EventType::evt_gameWon:
            msg = "You  won!";
            break;
        case EventType::evt_LevelStart:
            lvl = buffer.toType(32, 8);
            msg = "Level " + std::to_string(lvl + 1) + " (" + std::to_string(ecs.getTrack().getLevel(lvl).getNbEnemies()) + " enemies)";
            break;
        case EventType::evt_LevelEnd:
            lvl = buffer.toType(32, 8);
            msg = "Level " + std::to_string(lvl + 1) + " completed";
            break;

        default:
            break;
    }

    std::cout << msg << std::endl;
    if (msg.size() > 0) {
        std::shared_ptr<sf::Text> text = eventMessage->getText("default");
        if (text == nullptr) {
            std::cout << "Text not found" << std::endl;
            return;
        }
        text->setString(msg);
        if (text->getGlobalBounds().width > 1920) {
            text->setScale(1920 / text->getGlobalBounds().width, 1080 / text->getGlobalBounds().height);
        }
        if (text->getGlobalBounds().height > 1080) {
            text->setScale(1920 / text->getGlobalBounds().width, 1080 / text->getGlobalBounds().height);
        }
        text->setOrigin(
            text->getLocalBounds().width / 2,
            text->getLocalBounds().height / 2
        );
    }

    buffer.clear();
    buffer.append(0);
}
