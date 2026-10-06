/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <memory>
#include <iostream>
#include <chrono>
#include "../Components/Component.hpp"

class System {
    public:
        System();
        ~System();

        virtual void update();

        void addComponent(std::shared_ptr<Component> const &component);

        SparseArray<Component> getComponents() const;
        std::shared_ptr<Component> getComponent(size_t idx) const;

        void info() const;

        template <typename Element, typename Container>
        std::shared_ptr<Element> getElementFromContainer(const Container &container, size_t idx) {
            std::size_t i = 0;
            for (const auto &element : container) {
                if (auto cast = std::dynamic_pointer_cast<Element>(element.second); cast != nullptr) {
                    if (i == idx)
                        return cast;
                    i++;
                }
            }
            return nullptr;
        }

        template <typename Element>
        std::shared_ptr<Element> getElement(size_t idx) {
            if constexpr (std::is_base_of_v<Component, Element>)
                return getElementFromContainer<Element>(_components, idx);
            return nullptr;
        }

        void setDeltaTime(float dt);
        float getDeltaTime() const;

        void setRefTime(std::chrono::system_clock::time_point refTime);
        std::chrono::system_clock::time_point getRefTime() const;

    protected:
        float _dt;
        std::string _name;
        SparseArray<Component> _components;
        std::chrono::system_clock::time_point _refTime;
};

template std::shared_ptr<Component> System::getElement<Component>(size_t idx);

#endif /* !SYSTEM_HPP_ */
