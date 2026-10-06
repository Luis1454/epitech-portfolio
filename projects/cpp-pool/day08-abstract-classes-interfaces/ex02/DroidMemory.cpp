/*
** EPITECH PROJECT, 2024
** DroidMemory.cpp
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

std::ostream &operator<<(std::ostream &stream, DroidMemory const &droidMemory)
{
    stream << "DroidMemory '" << droidMemory.getFingerprint() << "', " << droidMemory.getExp();
    return stream;
}

DroidMemory::DroidMemory(){
    _fingerprint = random();
    _exp = 0;
}

DroidMemory::~DroidMemory(){}

size_t DroidMemory::getFingerprint() const {return _fingerprint;}

size_t DroidMemory::getExp() const {return _exp;}

void DroidMemory::setFingerprint(size_t fingerprint) {_fingerprint = fingerprint;}

void DroidMemory::setExp(size_t exp) {_exp = exp;}

void DroidMemory::addExp(size_t exp) {_exp += exp;}

DroidMemory &DroidMemory::operator<<(DroidMemory const &droidMemory)
{
    _exp += droidMemory._exp;
    _fingerprint ^= droidMemory._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &droidMemory) const
{
    droidMemory._exp += _exp;
    droidMemory._fingerprint ^= _fingerprint;
    return droidMemory;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &droidMemory)
{
    _exp += droidMemory._exp;
    _fingerprint ^= droidMemory._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    _exp += exp;
    _fingerprint ^= exp;
    return *this;
}

DroidMemory &DroidMemory::operator+(DroidMemory const &droidMemory) const
{
    DroidMemory *newDroidMemory = new DroidMemory();
    newDroidMemory->_exp = _exp + droidMemory._exp;
    newDroidMemory->_fingerprint = _fingerprint ^ droidMemory._fingerprint;
    return *newDroidMemory;
}

DroidMemory &DroidMemory::operator+(size_t exp) const
{
    DroidMemory *newDroidMemory = new DroidMemory();
    newDroidMemory->_exp = _exp + exp;
    newDroidMemory->_fingerprint = _fingerprint ^ exp;
    return *newDroidMemory;
}

bool DroidMemory::operator==(DroidMemory const &droidMemory) const
{
    return _exp == droidMemory._exp && _fingerprint == droidMemory._fingerprint;
}

bool DroidMemory::operator!=(DroidMemory const &droidMemory) const
{
    return _exp != droidMemory._exp || _fingerprint != droidMemory._fingerprint;
}

bool DroidMemory::operator<(DroidMemory const &droidMemory) const
{
    return _exp < droidMemory._exp;
}

bool DroidMemory::operator<=(DroidMemory const &droidMemory) const
{
    return _exp <= droidMemory._exp;
}

bool DroidMemory::operator>(DroidMemory const &droidMemory) const
{
    return _exp > droidMemory._exp;
}

bool DroidMemory::operator>=(DroidMemory const &droidMemory) const
{
    return _exp >= droidMemory._exp;
}

bool DroidMemory::operator<(size_t exp) const
{
    return _exp < exp;
}

bool DroidMemory::operator<=(size_t exp) const
{
    return _exp <= exp;
}

bool DroidMemory::operator>(size_t exp) const
{
    return _exp > exp;
}

bool DroidMemory::operator>=(size_t exp) const
{
    return _exp >= exp;
}

bool DroidMemory::operator==(size_t exp) const
{
    return _exp == exp;
}

bool DroidMemory::operator!=(size_t exp) const
{
    return _exp != exp;
}
