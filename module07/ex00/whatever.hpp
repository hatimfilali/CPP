#ifndef TEMP_HPP
#define TEMP_HPP

#include <iostream>

template <typename T>
T myMax(T x, T y) {
    return (x > y ? x : y);
}

template <typename T>
T myMin(T x, T y) {
    return(x < y ? x : y);
}

template <typename T>
void mySwap(T &x, T &y) {
    T temp;
    temp = x;
    x = y;
    y = temp;
}

#endif