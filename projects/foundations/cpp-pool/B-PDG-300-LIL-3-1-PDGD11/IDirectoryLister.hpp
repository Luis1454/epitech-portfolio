/*
** EPITECH PROJECT, 2024
** IDirectoryLister.hpp
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
#define IDIRECTORYLISTER_HPP_

#include <iostream>

class IDirectoryLister {
    public:
        IDirectoryLister(){}
        virtual ~IDirectoryLister(){}
        virtual bool open(const std::string &path, bool hidden) = 0;
        virtual std::string get() = 0;

        class NoMoreFileException : public std::exception {
            public:
                NoMoreFileException(){}
                ~NoMoreFileException() throw(){}
                const char *what() const throw() {return "No more file";}
        };

        class OpenFailureException : public std::exception {
            public:
                OpenFailureException(const std::string &path) : _path(path) {}
                ~OpenFailureException() throw(){}
                const char *what() const throw() {return _path.c_str();}
            protected:
                std::string _path;
        };
};

#endif /* !IDIRECTORYLISTER_HPP_ */
