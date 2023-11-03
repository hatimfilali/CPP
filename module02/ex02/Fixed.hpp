#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include<cmath>

class Fixed {
    private:
        int value;
        static const int fractionalBits;

    public:
        Fixed();
        Fixed(int initialValue);
        Fixed(float initialValue);
        Fixed(Fixed const &copy);
        Fixed &operator=(const Fixed &copy);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed &min(Fixed &lp, Fixed &rp);
        static const Fixed &min(const Fixed &lp, const Fixed &rp);
        static Fixed &max(Fixed &lp, Fixed &rp);
        static const Fixed &max(const Fixed &lp, const Fixed &rp);

        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        bool operator>(const Fixed &rp) const;
        bool operator<(const Fixed &rp) const;
        bool operator>=(const Fixed &rp) const;
        bool operator<=(const Fixed &rp) const;
        bool operator==(const Fixed &rp) const;
        bool operator!=(const Fixed &rp) const;
        Fixed operator+(const Fixed &rp);
        Fixed operator-(const Fixed &rp);
        Fixed operator*(const Fixed &rp);
        Fixed operator/(const Fixed &rp);

};

std::ostream &operator<<(std::ostream &os, const Fixed &value);

#endif