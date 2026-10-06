/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Protocol
*/

#include "../server/ECS/ECS.hpp"
#include "Protocol.hpp"
#include "Requests/ReceiveName.hpp"
#include "Requests/ReceiveEntityPos.hpp"
#include "Requests/SendEntityPos.hpp"
#include "Requests/AskEntityPos.hpp"
#include "Requests/SendNewEntity.hpp"
#include "Requests/ReceiveNewEntity.hpp"
#include "Requests/LaunchProjectile.hpp"
#include "Requests/GetEntity.hpp"
#include "Requests/MovePlayer.hpp"
#include "Requests/ReceivePlayerMove.hpp"
#include "Requests/DeleteEntity.hpp"
#include "Requests/ReceiveEntityDeletion.hpp"
#include "Requests/SendHealth.hpp"
#include "Requests/ReceiveHealth.hpp"
#include "Requests/SendGameEvent.hpp"
#include "Requests/ReceiveGameEvent.hpp"
#include <memory>
#include <functional>

template <typename T>
Protocol<T>::Protocol(std::size_t size)
{
    _buffer.reshape(size);
}

template <typename T>
void Protocol<T>::setBuffer(std::vector<T> buffer)
{
    _buffer.clear();
    for (int i = 0; i < buffer.size(); i++)
        _buffer.append(buffer[i]);
}

template <typename T>
void Protocol<T>::setBufferAt(std::size_t bitshift, T value)
{
    _buffer[bitshift] = value;
}

template <typename T>
void Protocol<T>::setBufferAt(std::size_t bitshift, std::string value)
{
    for (const auto &byte : value)
        _buffer[bitshift++] = byte;
}

template <typename T>
std::vector<T> Protocol<T>::getBuffer() const
{
    return _buffer.data();
}

template <typename T>
void Protocol<T>::clearBuffer()
{
    _buffer.clear();
}

template <typename T>
void Protocol<T>::resizeBuffer(std::size_t size)
{
    _buffer.reshape(size);
    for (int i = 0; i < size; i++)
        _buffer[i] = 0;
}

template <typename T>
void Protocol<T>::dump(std::size_t bitshift, std::size_t batch, std::size_t blockSize) const
{
    Buffer<T> buffer(_buffer.data());
    buffer.shift(bitshift);
    buffer.dump(batch, std::min(blockSize, buffer.size() * sizeof(T) * 8));
}

template <typename T>
void Protocol<T>::dump(std::size_t batch, std::size_t blockSize) const
{
    return dump(0, batch, blockSize);
}

template <typename T>
void Protocol<T>::runRequest(ECS &ecs)
{
    // std::cout << "RUN REQUEST" << std::endl;
    if (!_buffer.size()) {
        std::cerr << "Error : Empty protocol buffer" << std::endl;
        return;
    }
    //std::cout << "BUFFER SIZE : " << _buffer.size() << std::endl;
    std::lock_guard<std::mutex> lock(ecs._mutex);
    Byte type = _buffer.toType(0, 8);

    std::map<int, std::function<void()>> handlers = {
        {2, [&]() { ReceiveName<T>().execute(_buffer, ecs); }},
        {3, [&]() { AskEntityPos<T>().execute(_buffer, ecs); }},
        {4, [&]() { SendEntityPos<T>().execute(_buffer, ecs); }},
        {5, [&]() { ReceiveEntityPos<T>().execute(_buffer, ecs); }},
        {7, [&]() { SendNewEntity<T>().execute(_buffer, ecs); }},
        {8, [&]() { ReceiveNewEntity<T>().execute(_buffer, ecs); }},
        {9, [&]() { LaunchProjectile<T>().execute(_buffer, ecs); }},
        {10,[&]() { GetEntity<T>().execute(_buffer, ecs); }},
        {11,[&]() { MovePlayer<T>().execute(_buffer, ecs); }},
        {12,[&]() { ReceivePlayerMove<T>().execute(_buffer, ecs); }},
        {13,[&]() { DeleteEntity<T>().execute(_buffer, ecs); }},
        {14,[&]() { ReceiveEntityDeletion<T>().execute(_buffer, ecs); }},
        {15,[&]() { SendHealth<T>().execute(_buffer, ecs); }},
        {16,[&]() { ReceiveHealth<T>().execute(_buffer, ecs); }},
        {17,[&]() { SendGameEvent<T>().execute(_buffer, ecs); }},
        {18,[&]() { ReceiveGameEvent<T>().execute(_buffer, ecs); }}
    };

    auto it = handlers.find(type);
    if (it != handlers.end())
        it->second();
}

template <typename T>
std::vector<uint8_t> Protocol<T>::createPacket(std::vector<field_t> fields) {
    std::vector<uint8_t> packet;
    uint8_t current_byte = 0;
    uint8_t bit_position = 0;

    for (const auto& field : fields) {
        uint32_t value = field.value;
        uint8_t bits_left = field.size;

        while (bits_left > 0) {
            uint8_t bits_to_write = std::min(bits_left, static_cast<uint8_t>(8 - bit_position));

            current_byte |= static_cast<uint8_t>((value >> (bits_left - bits_to_write))
            & ((1 << bits_to_write) - 1)) << (8 - bit_position - bits_to_write);

            bit_position += bits_to_write;
            bits_left -= bits_to_write;

            if (bit_position == 8) {
                packet.emplace(packet.end(), current_byte);
                current_byte = 0;
                bit_position = 0;
            }
        }
    }

    if (bit_position > 0)
        packet.emplace(packet.end(), current_byte);
    return packet;
}

template class Protocol<char>;
template class Protocol<Byte>;
template class Protocol<int>;
template class Protocol<uint64_t>;
