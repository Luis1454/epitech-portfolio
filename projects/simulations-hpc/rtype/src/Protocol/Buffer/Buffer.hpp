/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Buffer
*/

#ifndef BUFFER_HPP_
#define BUFFER_HPP_

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdint>


typedef unsigned char Byte;

template <typename T>
class Buffer {
    public:
        Buffer();
        Buffer(std::vector<T> vec);
        ~Buffer();

        void append(T value);
        void clear();
        void reshape(std::size_t size);

        void shift(std::size_t size);
        void dump(std::size_t batch = 8, std::size_t blockSize = 8) const;

        std::vector<T> data() const;

        T getBitAt(std::size_t bitshift) const;
        void setBitAt(std::size_t bitshift, bool value);
        void overwrite(std::size_t bitshift, std::vector<T> data, std::size_t size);

        Buffer<T> readAt(std::size_t bitshift, std::size_t size) const;

        void reverse(std::size_t from = 0, std::size_t to = 0);
        std::string toStr(int from, int to) const;
        long long toType(int from, int size) const;

        T &operator[](std::size_t index);
        const T &operator[](std::size_t index) const;

        Buffer<T> operator&(const Buffer<T>& other) const;
        Buffer<T> operator|(const Buffer<T>& other) const;
        Buffer<T> operator^(const Buffer<T>& other) const;
        Buffer<T> operator~() const;

        Buffer<T>& operator&=(const Buffer<T>& other);
        Buffer<T>& operator|=(const Buffer<T>& other);
        Buffer<T>& operator^=(const Buffer<T>& other);

        Buffer<T>& operator<<=(std::size_t bits);
        Buffer<T> operator<<(std::size_t bits) const;
        Buffer<T>& operator>>=(std::size_t bits);
        Buffer<T> operator>>(std::size_t bits) const;

        typename std::vector<T>::iterator begin();
        typename std::vector<T>::iterator end();

        typename std::vector<T>::const_iterator begin() const;
        typename std::vector<T>::const_iterator end() const;
        std::size_t size() const;

        friend std::ostream& operator<<(std::ostream& os, const Buffer<T> &buffer) {
            for (size_t i = 0; i < buffer.size(); ++i)
               os << buffer[i];
            return os;
        }
        static T my_max(const T &a, const T &b) {
            return (a > b) ? a : b;
        }

    private:
        std::vector<T> _buffer;
};

#endif /* !BUFFER_HPP_ */
