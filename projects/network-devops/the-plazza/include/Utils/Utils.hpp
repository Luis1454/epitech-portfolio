/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

    #include <iostream>
    #include <unistd.h>
    #include <stdexcept>
    #include <vector>

namespace Utils
{
    class Pipe {
        public:
            void create(int *pipefd);
            void write_pipe(int fd, const void *buf, size_t count);
            void close_pipe(int fd);
            std::string read_pipe(int fd, size_t count);
    };

    class Fork {
        public:
            pid_t create();
    };

}

#endif /* !UTILS_HPP_ */