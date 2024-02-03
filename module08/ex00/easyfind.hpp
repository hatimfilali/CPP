#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <iterator>
#include <algorithm>
#include <iostream>

template <typename T>
typename T::value_type easyfind(T &container, int value) {
    typename T::iterator val = std::find(container.begin(), container.end(), value);
    if (val == container.end())
        throw std::runtime_error("This value is not found");
    return *val;
}
#endif