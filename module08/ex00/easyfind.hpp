#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <iterator>
#include <algorithm>
#include <iostream>


class invaliValueException : public std::exception {

    private :
        const char *message;
    public :
        invaliValueException(const char *msg) : message(msg) {

        }
        const char *what() const throw() {
            return message;
        }
};

template <typename T>
typename T::value_type easyfind(T &container, int value) {
    typename T::iterator val = std::find(container.begin(), container.end(), value);
    if (val = )
}

#endif