/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** ECS
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include "Sparse.hpp"
#include "Components/Position.hpp"
#include "Components/Component.hpp"
#include "Systems/System.hpp"
#include "Entities/Entity.hpp"

#include "Systems/Gravity.hpp"
#include "Systems/Motion.hpp"

#include "../Level.hpp"
#include "../Track.hpp"

#include <memory>
#include <iostream>
#include <asio.hpp>

class ECS {
    public:
        ECS(Track &track);
        ~ECS();

        std::mutex _mutex;

        void addEntity(std::shared_ptr<Entity> entity);
        void addEntity(std::size_t id, std::shared_ptr<Entity> entity);
        void dropEntity(std::shared_ptr<Entity> const &entity);
        void dropEntity(std::size_t idx);
        SparseArray<Entity> getEntities();

        std::size_t getNbEntities() const;
        std::size_t getAvailableSlot();

        void addComponent(std::shared_ptr<Component> const &component);
        void addComponent(std::size_t id, std::shared_ptr<Component> const &component);
        void dropComponent(std::shared_ptr<Component> const &component);

        void addSystem(std::shared_ptr<System> const &system);
        void addSystem(std::size_t id, std::shared_ptr<System> const &system);
        void dropSystem(std::shared_ptr<System> const &system);

        void setLastMsgTime(std::chrono::time_point<std::chrono::system_clock> time);
        std::chrono::time_point<std::chrono::system_clock> getLastMsgTime() const;

        void setClientId(std::size_t id);
        std::size_t getClientId() const;

        // int getEntityID();
        // void setEntityID(int Entityid);
        template <typename C>
        SparseArray<C> getComponents();
    
        template <typename Element, typename Container>
        std::shared_ptr<Element> getElementFromContainer(const Container container, size_t idx, bool absolute) {
            std::size_t i = 0;

            if (absolute)
                if constexpr (std::is_same_v<Container, SparseArray<Element>>)
                    if (container.find(idx) != container.end())
                        return container.at(idx);

            for (const auto &element : container) {
                if (auto cast = std::dynamic_pointer_cast<Element>(element.second); cast != nullptr) {
                    if (i == idx)
                        return cast;
                    i++;
                } else if (absolute)
                    i++;
            }
            return nullptr;
        }

        template <typename Element>
        std::shared_ptr<Element> getElement(size_t idx, bool absolute = false) {
            if constexpr (std::is_base_of_v<Entity, Element>)
                return getElementFromContainer<Element>(_entities, idx, absolute);
            if constexpr (std::is_base_of_v<Component, Element>)
                return getElementFromContainer<Element>(_components, idx, absolute);
            if constexpr (std::is_base_of_v<System, Element>)
                return getElementFromContainer<Element>(_systems, idx, absolute);
            return nullptr;
        }

        void info() const;
        void update();

        std::unordered_map<uint64_t, asio::ip::udp::endpoint> &getClients();
        void addClient(std::size_t id, asio::ip::udp::endpoint endpoint);
        void removeClient(std::size_t id);
        void setLastEndpoint(asio::ip::udp::endpoint endpoint);
        asio::ip::udp::endpoint getLastEndpoint();

        void disconnect(std::size_t id);
        void connect(std::size_t id);
        bool isConnected(std::size_t id);

        std::size_t getNbConnected() const;

        std::chrono::system_clock::time_point getLastUpdateTime() const;
        float getDeltaTime() const;

        void setTrack(Track &track);
        Track &getTrack() const;

    private:
        SparseArray<Entity> _entities;
        SparseArray<Component> _components;
        SparseArray<System> _systems;

        asio::ip::udp::endpoint _last_endpoint;
        std::unordered_map<uint64_t, asio::ip::udp::endpoint> _clients;
        std::unordered_map<uint64_t, bool> _connected;
        std::size_t _client_id;
        int _maxID;

        std::chrono::system_clock::time_point _lastMsgTime;
        std::chrono::system_clock::time_point _lastUpdate;
        float _dt;

        Track &_track;
};

template std::shared_ptr<Component> ECS::getElement<Component>(size_t, bool);
template std::shared_ptr<Entity> ECS::getElement<Entity>(size_t, bool);
template std::shared_ptr<System> ECS::getElement<System>(size_t, bool);

#endif /* !ECS_HPP_ */
