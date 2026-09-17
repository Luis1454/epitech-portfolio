/*
** EPITECH PROJECT, 2024
** DroidMemory.hpp
** File description:
** DroidMemory
*/

#include <iostream>

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

class DroidMemory {
    public:
        DroidMemory();
        ~DroidMemory();

        size_t getFingerprint() const;
        size_t getExp() const;
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);
        void addExp(size_t exp);

        DroidMemory &operator<<(DroidMemory const &droidMemory);
        DroidMemory &operator>>(DroidMemory &droidMemory) const;
        DroidMemory &operator+=(DroidMemory const &droidMemory);
        DroidMemory &operator+=(size_t exp);
        DroidMemory &operator+(DroidMemory const &droidMemory) const;
        DroidMemory &operator+(size_t exp) const;

        bool operator==(DroidMemory const &droidMemory) const;
        bool operator!=(DroidMemory const &droidMemory) const;
        bool operator<(DroidMemory const &droidMemory) const;
        bool operator<=(DroidMemory const &droidMemory) const;
        bool operator>(DroidMemory const &droidMemory) const;
        bool operator>=(DroidMemory const &droidMemory) const;

        bool operator<(size_t exp) const;
        bool operator<=(size_t exp) const;
        bool operator>(size_t exp) const;
        bool operator>=(size_t exp) const;
        bool operator==(size_t exp) const;
        bool operator!=(size_t exp) const;

    private:
        size_t _fingerprint;
        size_t _exp;
};

std::ostream &operator<<(std::ostream &stream, DroidMemory const &droidMemory);

#endif /* !DROIDMEMORY_HPP_ */
