#pragma once

#include <cstddef>
#include <map>
#include <memory>

#include "proxy.h"

template<typename T>
using matrixMap = std::map<std::pair<std::size_t, std::size_t>, T>;

template<typename T, T d = 0>
class Matrix
{
public:
    Matrix() = default;
    std::size_t size();
    typename matrixMap<T>::iterator begin();
    typename matrixMap<T>::iterator end();
    ProxyRow<T, d> operator[](const size_t& x_);

private:
    matrixMap<T> map;
    T& insert(const std::size_t& x, const std::size_t& y, const T& t);
    void erase(const std::size_t& x, const std::size_t& y);
    friend class ProxyValue<T, d>;
};


template<typename T, T d>
std::size_t Matrix<T, d>::size()
{
    return map.size();
}

template<typename T, T d>
typename matrixMap<T>::iterator Matrix<T, d>::begin()
{
    return map.begin();
}

template<typename T, T d>
typename matrixMap<T>::iterator Matrix<T, d>::end()
{
    return map.end();
}

template<typename T, T d>
ProxyRow<T,d> Matrix<T,d>::operator[](const size_t& x)
{
    return ProxyRow<T, d>(x, this);
}

template<typename T, T d>
T& Matrix<T, d>::insert(const size_t &x, const size_t &y, const T& t)
{
    return map[std::make_pair(x, y)] = t;
}

template<typename T, T d>
void Matrix<T, d>::erase(const size_t &x, const size_t &y)
{
    map.erase(std::make_pair(x, y));
}

