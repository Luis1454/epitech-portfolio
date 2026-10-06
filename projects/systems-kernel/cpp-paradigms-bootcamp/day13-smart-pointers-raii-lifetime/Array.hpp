/*
** EPITECH PROJECT, 2024
** Array.hpp
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>

#include <iostream>
#include <functional>

template<typename Type, std::size_t Size>
class Array {
    public:
        Array() {
            for (std::size_t i = 0; i < Size; i++)
                data[i] = Type();
        }
        ~Array() = default;

        Type& operator[](std::size_t index) {
            if (index >= Size)
                throw std::out_of_range("Out of range");
            return data[index];
        }

        const Type& operator[](std::size_t index) const {
            if (index >= Size)
                throw std::out_of_range("Out of range");
            return data[index];
        }

        template<typename U>
        Array<U, Size> convert(const std::function<U(const Type&)>& converter) const {
            Array<U, Size> result;

            for (std::size_t i = 0; i < Size; i++)
                result[i] = converter(data[i]);
            return result;
        }

        std::size_t size() const {return Size;}

        void forEach(const std::function<void(const Type&)>& task) const {
            for (std::size_t i = 0; i < Size; i++)
                task(data[i]);
        }

    private:
        Type data[Size];
};

template<typename Type, std::size_t Size>
std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& arr) {
    os << "[ ";
    for (std::size_t i = 0; i < Size; i++) {
        os << arr[i];
        if (i < Size - 1)
            os << " , ";
    }
    os << " ]";
    return os;
}

#endif /* !ARRAY_HPP_ */
