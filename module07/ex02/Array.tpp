#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"
#include <exception>
#include <ostream>


template <typename T>
Array<T>::Array() : elements(NULL), arraySize(0) {
    
}

template<typename T>
Array<T>::Array(const Array<T> &copy) {
    if (this != &copy && copy.size() != 0)
    {
        this->elements = new T[copy.size()];
        this->arraySize = copy.size();
        for (size_t i = 0; i < copy.size(); i++)
            this->elements[i] = copy.elements[i];
    }
}

template<typename T>
Array<T>::Array(unsigned int n) : arraySize(n) {
    elements = new T[arraySize];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy) {
    if (this != &copy) {
        delete[] elements;
        arraySize = copy.arraySize;
        elements = new T[arraySize];
        for (unsigned int i = 0; i < arraySize; ++i)
        {
            this->elements[i] = copy.elements[i];
        }
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index >= arraySize)
        throw std::out_of_range("Index out of bounds");
    return elements[index];
}

template<typename T>
Array<T>::~Array() {
    if (this->elements != NULL)
        delete[] elements;
}

template<typename T>
    unsigned int Array<T>::size() const {
        return arraySize;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &copy)
{
    if (copy.size() == 0)
        return (os);
    for (size_t i = 0; i < copy.size(); i++)
        os << "a[" << i << "] = <" << copy[i] << "> " << std::endl;
    return (os);
}


#endif