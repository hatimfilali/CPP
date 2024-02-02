#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
private:
    T *elements;
    unsigned int arraySize;
    T Value;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array &operator=(const Array &copy);
    T &operator[](unsigned int index);
    ~Array();
    unsigned int size() const;
};

#include "Array.tpp"

#endif