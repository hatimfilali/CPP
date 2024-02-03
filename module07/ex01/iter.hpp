#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *ptr, int size, void (function)(T &)) {
    for (int i = 0; i < size; i++)
        function(ptr[i]);
}

template <typename T>
void iter(const T *ptr, int size, void (function)(const T &)) {
    for (int i = 0; i < size; i++)
        function(ptr[i]);
}


template <typename T>
void printer(T elem) {
    std::cout << elem << std::endl;
}

#endif