/*
** EPITECH PROJECT, 2024
** handling.hpp
** File description:
** handling
*/

#ifndef HANDLING_HPP_
    #define HANDLING_HPP_

    #include <iostream>
    #include <ostream>

namespace err {
    class ErrorSoFile : public std::exception {
        public:
            ErrorSoFile() {}
            const char *what() const noexcept override {
                return "Error: Not a valid .so file";
            }
        private:
            std::string _message;
    };

    class NotEnoughArguments : public std::exception {
        public:
            NotEnoughArguments() {}
            const char *what() const noexcept override {
                return "Not enough arguments";
            }
    };

    class NotValidSoFile : public std::exception {
        public:
            NotValidSoFile() {}
            const char *what() const noexcept override {
                return "Error: Not a valid .so file";
            }
    };

    class NoFileFound : public std::exception {
        public:
            NoFileFound() {}
            const char *what() const noexcept override {
                return "Error: No file found";
            }
    };
}

#endif /* HANDLING_H_ */
