#pragma once

#include <cstddef>
#include <cassert>

template<typename T, T d>
class Matrix;

template<typename T, T d>
class ProxyValue
{
public:
    ProxyValue(const size_t &x_, const size_t &y_, Matrix<T, d> *m_);
    T& operator = (const T& t_);
    operator T ();
private:
    std::size_t x;
    std::size_t y;
    T t;
    Matrix<T, d>* m;
};

template<typename T, T d>
ProxyValue<T, d>::ProxyValue(const size_t &x_, const size_t &y_, Matrix<T, d>* m_):
    x(x_),
    y(y_),
    m(m_)
{
    assert((x >= 0 && y >= 0));
    auto value = m->map.find(std::make_pair(x,y));
    t = (value == m->map.end()) ? d : value->second;
}

template<typename T, T d>
T& ProxyValue<T, d>::operator=(const T& t_)
{
    t = t_;
    if (t == d)
    {
        m->erase(x, y);
        return t;
    }
    else
        return m->insert(x, y, t);
}

template<typename T, T d>
ProxyValue<T, d>::operator T()
{
    return t;
}

template<typename T, T d>
class ProxyRow {
public:
    ProxyRow(const size_t &x_, Matrix<T, d>* m_);
    ProxyValue<T, d> operator[](const std::size_t& y_);

private:
    std::size_t x;
    Matrix<T, d>* m;
};

template<typename T, T d>
ProxyRow<T,d>::ProxyRow(const size_t &x_, Matrix<T, d>* m_):
    x(x_),
    m(m_)
{ }

template<typename T, T d>
ProxyValue<T, d> ProxyRow<T, d>::operator[](const size_t& y_)
{
    return ProxyValue<T, d>(x, y_, m);
}
