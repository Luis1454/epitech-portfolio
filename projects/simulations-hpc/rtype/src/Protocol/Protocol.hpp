/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Protocol
*/


#ifndef PROTOCOL_HPP_
#define PROTOCOL_HPP_

#include <iostream>
#include <vector>
#include "Buffer/Buffer.hpp"
#include "../server/ECS/ECS.hpp"

typedef struct field_s {
    uint32_t value;
    uint8_t size;
} field_t;

typedef enum request_s {
    r_None,
    r_SendName,
    r_ReceiveName,
    r_AskEntityPos,
    r_SendEntityPos,
    r_ReceiveEntityPos,
    r_CreatePlayer,
    r_SendNewEntity,
    r_ReceiveNewEntity,
    r_LaunchProjectile,
    r_GetEntity,
    r_MovePlayer,
    r_ReceivePlayerMove,
    r_DeleteEntity,
    r_ReceiveEntityDeletion,
    r_SendHealth,
    r_ReceiveHealth,
    r_SendGameEvent,
    r_ReceiveGameEvent,
} RequestType;

template <typename T>
class Protocol {
    public:
        Protocol() = default;
        Protocol(std::size_t size);
        ~Protocol() = default;

        void setBuffer(std::vector<T> buffer);

        void setBufferAt(std::size_t bitshift, T value);
        void setBufferAt(std::size_t bitshift, std::string value);

        std::vector<T> getBuffer() const;

        void clearBuffer();
        void resizeBuffer(std::size_t size);

        void dump(std::size_t batch = 8, std::size_t blockSize = 8) const;
        void dump(std::size_t bitshift, std::size_t batch, std::size_t blockSize) const;

        void runRequest(ECS &ecs);

        static std::vector<uint8_t> createPacket(std::vector<field_t> fields);

    protected:
        Buffer<T> _buffer;
};

#endif /* !PROTOCOL_HPP_ */
