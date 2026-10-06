/*
** EPITECH PROJECT, 2024
** Port.cpp
** File description:
** Port
*/

#include "../../include/Renderer.hpp"

/**
 * @brief set the port

 * @param port
 */
void Renderer::setPort(int port)
{
    _port = port;
}

/**
 * @brief get the port

 * @return int
 */
int Renderer::getPort() const
{
    return _port;
}
