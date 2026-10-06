/*
** EPITECH PROJECT, 2024
** UniquePointer.hpp
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

template <typename T>
class UniquePointer {
    public:
        UniquePointer() : ptr(nullptr) {}
        UniquePointer(const UniquePointer&) = delete;
        explicit UniquePointer(T* pointer) : ptr(pointer) {}

        ~UniquePointer() {delete ptr;}

        UniquePointer& operator=(const UniquePointer&) = delete;
        UniquePointer& operator=(T* pointer) {
            delete ptr;
            ptr = pointer;
            return *this;
        }

        void reset() {
            delete ptr;
            ptr = nullptr;
        }

        T* get() const {return ptr;}
        T* operator->() const {return ptr;}

    private:
        T* ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
