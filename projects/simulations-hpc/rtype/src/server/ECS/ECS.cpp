/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ECS
*/

#include "Sparse.hpp"
#include "Components/Component.hpp"
#include "Systems/System.hpp"
#include "Entities/Entity.hpp"
#include "ECS.hpp"
#include <memory>
#include <iostream>

ECS::ECS(Track &track) : _track(track) {
    _maxID = 0;
    _lastUpdate = std::chrono::system_clock::now();
    _lastMsgTime = std::chrono::system_clock::now();
    _dt = 0.01;
}

ECS::~ECS() {}

void ECS::addEntity(std::shared_ptr<Entity> entity) {
    _entities.insert(_entities.size(), entity);
}

void ECS::addEntity(std::size_t id, std::shared_ptr<Entity> entity) {
    _entities.insert(id, entity);
}

void ECS::dropEntity(std::shared_ptr<Entity> const &entity) {
    dropEntity(_entities.getIndex(entity));
}

void ECS::dropEntity(std::size_t idx) {
    for (auto &c : _components)
        if (c.second != nullptr)
            c.second->dropEntity(idx);
    _entities.erase(idx);
}

std::size_t ECS::getNbEntities() const {
    return _entities.size();
}

void ECS::addComponent(std::shared_ptr<Component> const &component) {
    _components.insert(_components.size(), component);
}

void ECS::addComponent(std::size_t id, std::shared_ptr<Component> const &component) {
    _components.insert(id, component);
}

void ECS::dropComponent(std::shared_ptr<Component> const &component) {
    _components.erase(_components.getIndex(component));
}

void ECS::addSystem(std::shared_ptr<System> const &system) {
    _systems.insert(_systems.size(), system);
}

void ECS::addSystem(std::size_t id, std::shared_ptr<System> const &system) {
    _systems.insert(id, system);
}

void ECS::dropSystem(std::shared_ptr<System> const &system) {
    _systems.erase(_systems.getIndex(system));
}

void ECS::setLastMsgTime(std::chrono::system_clock::time_point time) {
    _lastMsgTime = time;
}

std::chrono::system_clock::time_point ECS::getLastMsgTime() const {
    return _lastMsgTime;
}

void ECS::setClientId(std::size_t id) {
    _client_id = id;
}

std::size_t ECS::getClientId() const {
    return _client_id;
}

void ECS::info() const
{
    std::cout << "--- ECS INFO ---" << std::endl;
    std::cout << "Entities (" << _entities.size() <<  "):" << std::endl;
    for (auto &id : _entities)
        std::cout << "\tEntity " << id.first << std::endl;
    std::cout << "\nSystems (" << _systems.size() <<  "): " << std::endl;
    for (const auto &system : _systems)
        system.second->info();
    std::cout << "\nComponents (" << _components.size() <<  "):" << std::endl;
    for (const auto &component : _components)
        component.second->info();
    std::cout << std::endl;
}

void ECS::update()
{
    std::lock_guard<std::mutex> lock(_mutex);
    for (auto &system : _systems) {
        if (system.second != nullptr) {
            system.second->setRefTime(_lastMsgTime);
            system.second->setDeltaTime(_dt);
            system.second->update();
        }
    }
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    _dt = std::chrono::duration_cast<std::chrono::duration<float>>(now - _lastUpdate).count();
    _lastUpdate = now;
}

void ECS::addClient(std::size_t id, asio::ip::udp::endpoint endpoint)
{
    _clients[id] = endpoint;
    _connected[id] = false;
}

void ECS::removeClient(std::size_t id)
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_connected.find(id) != _connected.end())
        _connected.erase(id);
    if (_clients.find(id) != _clients.end())
        _clients.erase(id);
}

void ECS::setLastEndpoint(asio::ip::udp::endpoint endpoint)
{
    _last_endpoint = endpoint;
}

asio::ip::udp::endpoint ECS::getLastEndpoint()
{
    return _last_endpoint;
}

std::unordered_map<uint64_t, asio::ip::udp::endpoint> &ECS::getClients()
{
    return _clients;
}

SparseArray<Entity> ECS::getEntities()
{
    return _entities;
}

std::size_t ECS::getAvailableSlot() {
    std::size_t currentId = 0;

    bool found = false;

    // _maxID++;
    // // return _maxID;

    while (!found) {
        found = true;
        for (const auto& entity : _entities)
            if (entity.first == currentId) {
                currentId++;
                found = false;
                break;
            }
    }
    return currentId;
}

void ECS::disconnect(std::size_t id) {
    _connected[id] = false;
}

void ECS::connect(std::size_t id) {
    _connected[id] = true;
}

bool ECS::isConnected(std::size_t id) {
    return _connected.find(id) != _connected.end() && _connected.at(id);
}

std::chrono::system_clock::time_point ECS::getLastUpdateTime() const {
    return _lastUpdate;
}

float ECS::getDeltaTime() const {
    return _dt;
}

std::size_t ECS::getNbConnected() const {
    return std::count_if(_connected.begin(), _connected.end(), [](const std::pair<uint64_t, bool> &pair) {
        return pair.second;
    });
}

template <typename C>
SparseArray<C> ECS::getComponents() {
    SparseArray<C> components;

    for (const auto &component : _components)
        if (auto c = std::dynamic_pointer_cast<C>(component); c != nullptr)
            components.insert(components.size(), c);
    return components;
}

void ECS::setTrack(Track &track) {
    _track = track;
}

Track &ECS::getTrack() const {
    return _track;
}
