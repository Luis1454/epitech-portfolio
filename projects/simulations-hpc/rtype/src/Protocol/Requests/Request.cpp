#include "Request.hpp"
#include <cstring>
#include <cmath>

template <typename T>
std::string Request<T>::getType() const {
    return _type;
}

template <typename T>
template <typename N>
std::vector<T> Request<T>::toVector(const N n) {
    std::vector<T> v;
    N tmp = n;

    if constexpr (std::is_floating_point_v<N>) {
        // Handle float conversion to 12-bit representation
        static_assert(sizeof(N) <= sizeof(uint64_t), "Unsupported floating-point size");
        uint64_t int_rep;
        std::memcpy(&int_rep, &tmp, sizeof(N));
        while (int_rep) {
            v.push_back(static_cast<T>(int_rep & ((1ULL << (sizeof(T) * 8)) - 1)));
            int_rep >>= sizeof(T) * 8;
        }
    } else {
        while (tmp) {
            v.push_back(static_cast<T>(tmp & ((1ULL << (sizeof(T) * 8)) - 1)));
            tmp >>= sizeof(T) * 8;
        }
    }
    std::reverse(v.begin(), v.end());
    return v;
}

// Explicit instantiations for the toVector method with float type
template std::vector<uint64_t> Request<uint64_t>::toVector<float>(float);
template std::vector<unsigned char> Request<unsigned char>::toVector<float>(float);
template std::vector<int> Request<int>::toVector<float>(float);
template std::vector<char> Request<char>::toVector<float>(float);

// Explicit instantiations for the toVector method with unsigned int type
template std::vector<uint64_t> Request<uint64_t>::toVector<unsigned int>(unsigned int);
template std::vector<unsigned char> Request<unsigned char>::toVector<unsigned int>(unsigned int);
template std::vector<int> Request<int>::toVector<unsigned int>(unsigned int);
template std::vector<char> Request<char>::toVector<unsigned int>(unsigned int);

// Other explicit instantiations
template class Request<uint64_t>;
template class Request<unsigned char>;
template class Request<int>;
template class Request<char>;

template std::vector<uint64_t> Request<uint64_t>::toVector(uint64_t);
template std::vector<uint64_t> Request<uint64_t>::toVector(int);
template std::vector<uint64_t> Request<uint64_t>::toVector(long);

template std::vector<unsigned char> Request<unsigned char>::toVector(uint64_t);
template std::vector<unsigned char> Request<unsigned char>::toVector(int);
template std::vector<unsigned char> Request<unsigned char>::toVector(long);

template std::vector<int> Request<int>::toVector(uint64_t);
template std::vector<int> Request<int>::toVector(int);
template std::vector<int> Request<int>::toVector(long);

template std::vector<char> Request<char>::toVector(uint64_t);
template std::vector<char> Request<char>::toVector(int);
template std::vector<char> Request<char>::toVector(long);