/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Buffer
*/

#include "Buffer.hpp"

template <typename T>
Buffer<T>::Buffer()
{
}

template <typename T>
Buffer<T>::Buffer(std::vector<T> buffer)
{
    _buffer = buffer;
}

template <typename T>
Buffer<T>::~Buffer()
{
}

template <typename T>
void Buffer<T>::append(T value)
{
    _buffer.push_back(value);
}

template <typename T>
Buffer<T> Buffer<T>::readAt(std::size_t bitshift, std::size_t size) const
{
    if (bitshift + size > _buffer.size()) {
        throw std::out_of_range("Buffer::readAt - Out of range");
    }
    Buffer<T> buffer;
    for (std::size_t i = bitshift; i < bitshift + size; i++)
        buffer.append(_buffer[i]);
    return buffer;
}

template <typename T>
std::string Buffer<T>::toStr(int from, int to) const
{
    if (from < 0 || to < 0 || from >= to || from >= (int)(_buffer.size() * sizeof(T) * 8)) {
        throw std::out_of_range("Invalid range specified");
    }

    if (to > (int)(_buffer.size() * sizeof(T) * 8)) {
        to = (int)(_buffer.size() * sizeof(T) * 8);
    }

    std::vector<char> output;
    int byteFrom = from / 8;
    int bitFrom = from % 8;
    int byteTo = to / 8;
    int bitTo = to % 8;

    for (int i = byteFrom; i <= byteTo; ++i) {
        char byte = 0;
        for (int bit = 0; bit < 8; ++bit) {
            int bitIndex = i * 8 + bit;
            if (bitIndex >= from && bitIndex < to) {
                byte |= ((_buffer[bitIndex / (sizeof(T) * 8)] >> (bitIndex % (sizeof(T) * 8))) & 1) << bit;
            }
        }
        output.push_back(byte);
    }

    return std::string(output.begin(), output.end());
}

template <typename T>
long long Buffer<T>::toType(int from, int size) const
{
    long long result = 0;
    Buffer<T> tmp;

    for (int i = from; i < from + size && i - from < (int)_buffer.size() * 8 * sizeof(T); i++) {
        tmp.append(_buffer[i / (sizeof(T) * 8)]);
        result = (result << 1) | tmp.getBitAt((sizeof(T) * 8 - i - 1) % (sizeof(T) * 8));
        tmp.clear();
    }
    return result;
}

template <typename T>
T Buffer<T>::getBitAt(std::size_t bitshift) const
{
    if (bitshift >= _buffer.size() * 8 * sizeof(T))
        throw std::out_of_range("Buffer::getBitAt - Out of range");
    std::size_t idx = bitshift / (sizeof(T) * 8);
    std::size_t bit = bitshift % (sizeof(T) * 8);
    if (idx < _buffer.size())
        return (_buffer[idx] >> bit) & 1;
    return 0;
}

template <typename T>
void Buffer<T>::setBitAt(std::size_t bitshift, bool value)
{
    if (bitshift >= _buffer.size() * sizeof(T) * 8)
        throw std::out_of_range("Buffer::setBitAt - Out of range");

    std::size_t idx = bitshift / (sizeof(T) * 8);
    std::size_t bit = bitshift % (sizeof(T) * 8);

    if (idx >= _buffer.size())
        return;

    T mask = 1 << bit;
    if (value)
        _buffer[idx] |= mask;
    else
        _buffer[idx] &= ~mask;
}

#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
void Buffer<T>::overwrite(std::size_t bitshift, std::vector<T> data, std::size_t size) {
    bitshift += (size / 8 - data.size()) * 8 * sizeof(T);
    for (std::size_t i = 0; i < 8 * sizeof(T) * data.size()
    && bitshift + i < 8 * sizeof(T) * _buffer.size() && i < size; i++) {
        if (i / (sizeof(T) * 8) >= data.size())
            break;
        bool bit = (data[i / (sizeof(T) * 8)] >> i % (8 * sizeof(T))) & 1;
        setBitAt(bitshift + i, bit);
    }
}

template <typename T>
std::size_t Buffer<T>::size() const
{
    return _buffer.size();
}

template <typename T>
void Buffer<T>::clear()
{
    _buffer.clear();
}

template <typename T>
void Buffer<T>::reshape(std::size_t size)
{
    _buffer.resize(size);
}

template <typename T>
void Buffer<T>::reverse(std::size_t from, std::size_t to)
{
    Buffer<T> tmp = _buffer;

    if (from > to) {
        std::size_t swap = from;
        from = to;
        to = swap;
    }

    if (from > tmp.size() * 8 * sizeof(T))
        from = tmp.size() * 8 * sizeof(T);

    if (to > tmp.size() * 8 * sizeof(T) || !to)
        to = tmp.size() * 8 * sizeof(T);

    std::cout << "from = " << from << " | to = " << to << " | tmp size = " << tmp.size() << std::endl;

    for (std::size_t i = from; i < to; i++)
        setBitAt(i, tmp.getBitAt(to - (i - from) - 1));
}

template <typename T>
void Buffer<T>::shift(std::size_t shift)
{
    std::size_t size = _buffer.size();
    if (!size || !shift || !sizeof(T))
        return;

    bool is_negative = (static_cast<int>(shift) < 0);
    std::size_t abs_shift = is_negative ? -static_cast<int>(shift) : shift;
    std::size_t shift_size = abs_shift / (sizeof(T) * 8);
    std::size_t remainder = abs_shift % (sizeof(T) * 8);

    std::vector<T> new_buffer(size);
    std::size_t new_index;

    for (std::size_t i = 0; i < size; i++) {
        if (is_negative)
            new_index = (i + size - shift_size) % size;
        else
            new_index = (i + shift_size) % size;
        new_buffer[new_index] = _buffer[i];
    }

    _buffer = new_buffer;

    if constexpr (std::is_integral_v<T>) {
        if (is_negative)
            for (auto &val : _buffer)
                val = (val >> remainder) | (val << (sizeof(T) * 8 - remainder));
        else
            for (auto &val : _buffer)
                val = (val << remainder) | (val >> (sizeof(T) * 8 - remainder));
    }
}

template <typename T>
void Buffer<T>::dump(std::size_t batch, std::size_t blockSize) const
{
    std::size_t i = 0;
    std::size_t bits = sizeof(T) * 8;

    if (!sizeof(T))
        return;

    batch = my_max(batch, 1UL);
    blockSize = my_max(blockSize, 1UL);


    std::cout << std::endl << _buffer.size() * sizeof(T) * 8 << " bits with " << bits << " bits per units";
    for (const auto &byte : _buffer) {
        for (std::size_t j = 0; j < bits; j++) {
            if ((i * bits + j) % (batch * blockSize) == 0)
                std::cout << std::endl;
            std::cout << ((byte >> (bits - j - 1)) & 1);
            if ((i * bits + j) % blockSize == blockSize - 1)
                std::cout << " ";
        }
        i++;
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> Buffer<T>::data() const
{
    return _buffer;
}

template <typename T>
T &Buffer<T>::operator[](std::size_t index)
{
    return _buffer[index];
}

template <typename T>
const T &Buffer<T>::operator[](std::size_t index) const
{
    return _buffer[index];
}

template <typename T>
typename std::vector<T>::iterator Buffer<T>::begin()
{
    return _buffer.begin();
}

template <typename T>
typename std::vector<T>::iterator Buffer<T>::end()
{
    return _buffer.end();
}

template <typename T>
typename std::vector<T>::const_iterator Buffer<T>::begin() const
{
    return _buffer.cbegin();
}

template <typename T>
typename std::vector<T>::const_iterator Buffer<T>::end() const
{
    return _buffer.cend();
}

template <typename T>
Buffer<T> Buffer<T>::operator~() const {
    Buffer<T> result;
    for (const T& byte : _buffer)
        result.append(~byte);
    return result;
}

template <typename T>
Buffer<T> Buffer<T>::operator&(const Buffer<T>& other) const {
    if (_buffer.size() != other._buffer.size())
        throw std::invalid_argument("Buffer::operator& - Buffers de tailles différentes");

    Buffer<T> result;
    for (std::size_t i = 0; i < _buffer.size(); i++)
        result.append(_buffer[i] & other._buffer[i]);
    return result;
}

template <typename T>
Buffer<T> Buffer<T>::operator|(const Buffer<T>& other) const {
    if (_buffer.size() != other._buffer.size())
        throw std::invalid_argument("Buffer::operator| - Buffers de tailles différentes");

    Buffer<T> result;
    for (std::size_t i = 0; i < _buffer.size(); i++)
        result.append(_buffer[i] | other._buffer[i]);
    return result;
}

template <typename T>
Buffer<T> Buffer<T>::operator^(const Buffer<T>& other) const {
    if (_buffer.size() != other._buffer.size())
        throw std::invalid_argument("Buffer::operator^ - Buffers de tailles différentes");

    Buffer<T> result;
    for (std::size_t i = 0; i < _buffer.size(); i++)
        result.append(_buffer[i] ^ other._buffer[i]);
    return result;
}

template <typename T>
Buffer<T>& Buffer<T>::operator&=(const Buffer<T>& other) {
    if (_buffer.size() != other._buffer.size())
        throw std::invalid_argument("Buffer::operator&= - Buffers de tailles différentes");

    for (std::size_t i = 0; i < _buffer.size(); i++)
        _buffer[i] &= other._buffer[i];
    return *this;
}

template <typename T>
Buffer<T>& Buffer<T>::operator|=(const Buffer<T>& other) {
    if (_buffer.size() != other._buffer.size())
        throw std::invalid_argument("Buffer::operator|= - Buffers de tailles différentes");

    for (std::size_t i = 0; i < _buffer.size(); i++)
        _buffer[i] |= other._buffer[i];
    return *this;
}

template <typename T>
Buffer<T> &Buffer<T>::operator^=(const Buffer<T>& other) {
    if (_buffer.size() != other._buffer.size())
        throw std::invalid_argument("Buffer::operator^= - Buffers de tailles différentes");

    for (std::size_t i = 0; i < _buffer.size(); i++)
        _buffer[i] ^= other._buffer[i];
    return *this;
}

template <typename T>
Buffer<T> &Buffer<T>::operator>>=(const std::size_t n) {
    for (std::size_t i = 0; i < _buffer.size(); i++)
        _buffer[i] >>= n;
    return *this;
}

template <typename T>
Buffer<T> &Buffer<T>::operator<<=(const std::size_t n) {
    for (std::size_t i = 0; i < _buffer.size(); i++)
        _buffer[i] <<= n;
    return *this;
}


// Explicit instantiations for supported types
template class Buffer<Byte>;
template class Buffer<char>;
template class Buffer<int>;
template class Buffer<uint64_t>;
