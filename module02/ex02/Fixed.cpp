#include"Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0) {}

Fixed::Fixed (int initialValue) {
    value = (initialValue << fractionalBits);
}

Fixed::Fixed (float initialValue) {
    value = roundf(initialValue * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &copy) {
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
    if (this != &copy)
        this->value = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return (value);
}

void Fixed::setRawBits(const int raw) {
    value = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->value / (1 << fractionalBits));
}

int Fixed::toInt(void) const {
    return (this->value / (1 << fractionalBits));
}

Fixed &Fixed::min(Fixed &lp, Fixed &rp) {
    return(lp >= rp ? rp : lp);
}

const Fixed &Fixed::min(const Fixed &lp, const Fixed &rp) {
    return (lp >= rp ? rp : lp);
} 

Fixed &Fixed::max(Fixed &lp, Fixed &rp) {
    return (lp <= rp ? rp : lp);
}

const Fixed &Fixed::max(const Fixed &lp, const Fixed &rp) {
    return (lp <= rp ? rp : lp);
}

Fixed &Fixed::operator++() {
    this->value ++;
    return (*this);
}

Fixed &Fixed::operator--() {
    this->value --;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp;
    tmp.setRawBits(this->getRawBits());
    ++ this->value;
    return (tmp);
}

Fixed Fixed::operator--(int) {
    Fixed tmp;
    tmp.setRawBits(this->getRawBits());
    -- this->value;
    return (tmp);
}

bool Fixed::operator>(const Fixed &rp) const {
    return toFloat() > rp.toFloat();
}

bool Fixed::operator<(const Fixed &rp) const {
    return toFloat() < rp.toFloat();
}

bool Fixed::operator>=(const Fixed &rp) const {
    return toFloat() >= rp.toFloat();
}

bool Fixed::operator<=(const Fixed &rp) const {
    return toFloat() <= rp.toFloat();
}

bool Fixed::operator==(const Fixed &rp) const {
    return toFloat() == rp.toFloat(); 
}

bool Fixed::operator!=(const Fixed &rp) const {
    return toFloat() != rp.toFloat();
}

Fixed Fixed::operator+(const Fixed &rp) {
    return Fixed(toFloat() + rp.toFloat());
}

Fixed Fixed::operator-(const Fixed &rp) {
    return Fixed(toFloat() - rp.toFloat());
}

Fixed Fixed::operator*(const Fixed &rp) {
    return Fixed(toFloat() * rp.toFloat());
}

Fixed Fixed::operator/(const Fixed &rp) {
    return Fixed(toFloat() / rp.toFloat());
}

std::ostream &operator<<(std::ostream &os, const Fixed &value) {
    os << value.toFloat();
    return (os);
}
