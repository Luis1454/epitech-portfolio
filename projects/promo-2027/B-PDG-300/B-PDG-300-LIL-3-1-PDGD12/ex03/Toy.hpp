/*
** EPITECH PROJECT, 2024
** Toy.hpp
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"
#include <iostream>

class Toy {
    public:
        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};
        Toy();
        Toy(const ToyType &type, const std::string &name,
            const std::string &file);
        Toy(const Toy &toy);
        virtual ~Toy() = default;

        ToyType getType() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);

        virtual void speak(const std::string &statement) {
            std::cout << name << " \"" << statement << "\"" << std::endl;
        }

        Toy &operator=(const Toy &toy);

    protected:
        std::string name;
        Picture picture;
        ToyType type;
};

std::ostream &operator<<(std::ostream &os, const Toy &toy);

#endif /* !TOY_HPP_ */
