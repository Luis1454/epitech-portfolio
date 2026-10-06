/*
** EPITECH PROJECT, 2024
** AComponent.hpp
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "IComponent.hpp"

namespace nts {
    class AComponent : public IComponent {
        public:
            virtual void simulate(std::size_t tick,
            std::vector<std::unique_ptr<nts::AComponent>> &components);
            virtual nts::Tristate compute(std::size_t tick);
            virtual void setLink(std::size_t pin, const std::unique_ptr<nts::AComponent>
                &other, std::size_t otherPin);
            virtual void setChild(std::size_t pin, const std::unique_ptr<nts::AComponent>
                &other, std::size_t otherPin);
            virtual void setName(std::string name) {_name = name;}
            virtual void setCategory(std::string type) {_category = type;}
            virtual void setPin(std::size_t pin, nts::Tristate state);
            virtual void setOldPin(std::size_t pin, nts::Tristate state);
            virtual void setPinState(std::string state);

            virtual std::string getName() {return _name;}
            virtual std::string getCategory() {return _category;}
            virtual nts::Tristate getPin(std::size_t pin);
            virtual nts::Tristate getOldPin(std::size_t pin);
            virtual std::string getPinState();
            virtual std::map<std::size_t, nts::Tristate> getPins();
            virtual std::map<std::size_t, link_t> getLinks() {return _links;}
            virtual std::map<std::size_t, link_t> getChilds() {return _childs;}

        protected:
            std::size_t _refPin = 1;
            std::string _name;
            std::string _category;
            std::map<std::size_t, link_t> _links;
            std::map<std::size_t, link_t> _childs;
            std::map<std::size_t, nts::Tristate> _pins;
            std::map<std::size_t, nts::Tristate> _oldPins;
    };
}

#endif /* !ACOMPONENT_HPP_ */
