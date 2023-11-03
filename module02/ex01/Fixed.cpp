#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(int initialValue) {
    value = (initialValue << fractionalBits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float initialValue) {
    value = roundf(initialValue * (1 << fractionalBits));
    std::cout << "Float constructor called" << std::endl;
} 

Fixed &Fixed::operator=(const Fixed &copy) {
    std::cout << "Copy assignment operation called" << std::endl;
    if (this != &copy)
        this->value = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}

float Fixed::toFloat(void) const {
    float fl = ((float)this->value / (1 << fractionalBits));
    return fl;
}

int Fixed::toInt(void) const {
    return (this->value / (1 << fractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &value) {
    os << value.toFloat();
    return (os);
}
