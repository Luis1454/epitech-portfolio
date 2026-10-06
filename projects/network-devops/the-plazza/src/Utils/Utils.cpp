/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Utils
*/

#include "../../include/Utils/Utils.hpp"

void Utils::Pipe::create(int *pipefd)
{
    if (pipe(pipefd) == -1)
        throw std::runtime_error("Failed to create pipe");
}

void Utils::Pipe::write_pipe(int fd, const void *buf, size_t count)
{
    if (write(fd, buf, count) == -1)
        throw std::runtime_error("Failed to write to pipe");
}

void Utils::Pipe::close_pipe(int fd)
{
    if (close(fd) == -1)
        throw std::runtime_error("Failed to close pipe");
}

std::string Utils::Pipe::read_pipe(int fd, size_t count)
{
    std::vector<char> buffer(count);
    ssize_t bytesRead = read(fd, buffer.data(), count);
    if (bytesRead == -1)
        throw std::runtime_error("Failed to read from pipe");
    return std::string(buffer.data(), bytesRead);
}

pid_t Utils::Fork::create()
{
    pid_t pid = fork();
    if (pid == -1)
        throw std::runtime_error("Failed to create fork");
    return pid;
}
