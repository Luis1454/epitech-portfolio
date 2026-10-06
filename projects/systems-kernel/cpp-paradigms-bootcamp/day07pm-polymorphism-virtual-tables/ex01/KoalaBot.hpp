/*
** EPITECH PROJECT, 2024
** KoalaBot.hpp
** File description:
** KoalaBot
*/

#include "Parts.hpp"

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

class KoalaBot {
    public:
        KoalaBot();
        ~KoalaBot();

        void setParts(const Arms &arms);

        void setParts(const Legs &legs);

        void setParts(const Head &head);

        void swapParts(Arms &arms);

        void swapParts(Legs &legs);

        void swapParts(Head &head);

        void informations() const;

        bool status() const;

    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial = "Bob-01";
};

#endif /* !KOALABOT_HPP_ */
