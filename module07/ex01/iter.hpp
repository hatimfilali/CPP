#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename TT>
void iter(T *ptr, int size, void (function)(TT )) {
    for (int i = 0; i < size; i++)
        function(ptr[i]);
}

template <typename T>
void printer(T elem) {
    std::cout << elem << std::endl;
}

#endif