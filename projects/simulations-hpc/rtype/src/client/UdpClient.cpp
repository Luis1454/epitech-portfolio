#include "UdpClient.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include "../Protocol/Requests/ReceiveEntityPos.hpp"
#include "../server/ECS/Components/Health.hpp"
#include "../server/ECS/Components/Player.hpp"
#include "../server/ECS/Components/Enemy.hpp"
#include "Components/Sprite.hpp"
#include "Components/LifeBar.hpp"
#include <string>

UdpClient::UdpClient(const std::string& host, uint16_t port, ECS &ecs)
    : io_context_(), socket_(io_context_), server_endpoint_(asio::ip::make_address(host), port), _ecs(ecs) {
    socket_.open(asio::ip::udp::v4());
    socket_.bind(asio::ip::udp::endpoint(asio::ip::udp::v4(), 0)); // cette ligne permet de récupérer le port attribué par le système
    socket_.connect(server_endpoint_); 
}

UdpClient::~UdpClient() {
    stop();
}

void UdpClient::start() {
    running_ = true;
    communication_thread_ = std::thread([this]() { communicate(); });
}

void UdpClient::stop() {
    running_ = false;
    if (communication_thread_.joinable())
        communication_thread_.join();
}

void UdpClient::addRequest(std::vector<field_t> fields) {
    _pool.push(fields);
}

void UdpClient::communicate() {
    try {
        int i = 0;
        while (running_)
            executePool();

    } catch (const std::exception& e) {
        std::cerr << "Erreur dans la communication : " << e.what() << std::endl;
    }
}

void UdpClient::executePool()
{
    Protocol<Byte> protocol;
    Buffer<Byte> buffer;

    for (int i = 0; i < _pool.size(); i++) {
        std::vector<Byte> packet = Protocol<Byte>::createPacket(_pool.front());
        std::lock_guard<std::mutex> lock(_socketMutex);
        socket_.send_to(asio::buffer(packet), server_endpoint_);
        _pool.pop();
    }
    std::vector<Byte> recv_buffer(1024);
    asio::ip::udp::endpoint sender_endpoint;

    std::lock_guard<std::mutex> lock(_socketMutex);
    size_t len = socket_.receive_from(asio::buffer(recv_buffer), sender_endpoint);
    recv_buffer.resize(len);
    buffer = recv_buffer;

    long long cmd_id = buffer.toType(0, 8);
    std::shared_ptr<Position> position = _ecs.getElement<Position>(0);
    if (position == nullptr) {
        std::cerr << "Position component not found!" << std::endl;
        return;
    }
    std::shared_ptr<Sprite> sprite = _ecs.getElement<Sprite>(0);
    if (sprite == nullptr) {
        std::cerr << "Sprite component not found!" << std::endl;
        return;
    }
    std::shared_ptr<Enemy> enemy = _ecs.getElement<Enemy>(0);
    if (enemy == nullptr) {
        std::cerr << "Enemy component not found!" << std::endl;
        return;
    }
    std::size_t player_id = buffer.toType(8, 16);
    if (cmd_id == 6) {
        std::cout << "Player id : " << player_id << std::endl;
        _ecs.setClientId(player_id);
        _ecs.addEntity(player_id, std::make_shared<Entity>());
        std::shared_ptr<Player> player = _ecs.getElement<Player>(0);
        if (player == nullptr) {
            std::cerr << "Player component not found!" << std::endl;
            return;
        }
        std::shared_ptr<Entity> entity = _ecs.getEntities().at(player_id);

       if (entity == nullptr) {
            std::cerr << "Erreur: L'entité avec l'ID " << player_id << " est introuvable !" << std::endl;
            return;
        }
        position->addEntity(player_id, entity);
        position->setX(player_id, 0);
        position->setY(player_id, 0);
        player->addEntity(player_id, entity);
        player->setName(player_id, "player");
        sprite->addEntity(player_id, entity);
        sprite->setSprite("entity_" + std::to_string(player_id), sprite->getTexture("player"));
        sprite->addPlayer(player_id, "entity_" + std::to_string(player_id));
        sprite->getSprite("entity_" + std::to_string(player_id)).setScale(0.2, 0.2);
        // set origin
        sprite->getSprite("entity_" + std::to_string(player_id)).setOrigin(sprite->getSprite("entity_" +
            std::to_string(player_id)).getLocalBounds().width / 2, sprite->getSprite("entity_" +
            std::to_string(player_id)).getLocalBounds().height / 2);

        std::shared_ptr<LifeBar> lifeBar = _ecs.getElement<LifeBar>(0);
        if (lifeBar == nullptr) {
            std::cerr << "LifeBar component not found!" << std::endl;
            return;
        }
        lifeBar->addEntity(player_id, entity);
        HealthBar testBar(20, 100, 40, sf::Vector2f(100, 100));
        lifeBar->addLifeBar(player_id, std::shared_ptr<HealthBar> (new HealthBar(testBar)));

        std::shared_ptr<Health> health = _ecs.getElement<Health>(0);
        if (health == nullptr) {
            std::cerr << "Health component not found!" << std::endl;
            return;
        }
        health->addEntity(player_id, entity);
        health->setHealth(player_id, 100);
        health->setMaxHealth(player_id, 100);
        health->setMinHealth(player_id, 0);

    } else {
        protocol.setBuffer(buffer.data());
        protocol.runRequest(_ecs);
    }
}
