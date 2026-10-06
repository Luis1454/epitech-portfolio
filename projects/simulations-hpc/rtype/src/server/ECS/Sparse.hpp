#ifndef SPARSE_HPP_
#define SPARSE_HPP_

#include <unordered_map>
#include <memory>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T>
class SparseArray {
public:
    using size_type = std::size_t;
    using reference = std::shared_ptr<T>&;
    using const_reference = const std::shared_ptr<T>&;
    using iterator = typename std::unordered_map<size_type, std::shared_ptr<T>>::iterator;
    using const_iterator = typename std::unordered_map<size_type, std::shared_ptr<T>>::const_iterator;

    const_reference operator[](size_type idx) const {
        if (_data.find(idx) == _data.end())
            return nullptr;
        return _data.find(idx)->second;
    }

    iterator find(size_type idx) {
        return _data.find(idx);
    }

    const_iterator find(size_type idx) const {
        return _data.find(idx);
    }

    reference at(size_type idx) {
        auto it = _data.find(idx);
        if (it == _data.end())
            throw std::out_of_range("Index out of range");
        return it->second;
    }

    const_reference at(size_type idx) const {
        auto it = _data.find(idx);
        if (it == _data.end())
            throw std::out_of_range("Index out of range");
        return it->second;
    }

    size_type getIndex(const std::shared_ptr<T>& value) const {
        auto it = std::find_if(_data.begin(), _data.end(), [&value](const auto& pair) {
            return pair.second == value;
        });
        return (it != _data.end()) ? it->first : -1;
    }

    iterator begin() {
        return _data.begin();
    }

    const_iterator begin() const {
        return _data.begin();
    }

    const_iterator cbegin() const {
        return _data.cbegin();
    }

    iterator end() {
        return _data.end();
    }

    const_iterator end() const {
        return _data.end();
    }

    const_iterator cend() const {
        return _data.cend();
    }

    size_type size() const {
        return _data.size();
    }

    bool isEmpty() const {
        return _data.empty();
    }

    void clear() {
        _data.clear();
    }

    void insert(size_type idx, const std::shared_ptr<T> &value) {
        _data.insert_or_assign(idx, value);
    }

    void erase(size_type pos) {
        _data.erase(pos);
    }

private:
    std::unordered_map<size_type, std::shared_ptr<T>> _data;
};

#endif /* !SPARSE_HPP_ */
