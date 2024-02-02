#include "whatever.hpp"
#include <iostream>

int main () {
    int a = 12;
    int b = 0;

    std::cout << "The bigger number is " << myMax(a, b) << std::endl;
    mySwap(a, b);
    std::cout << "The smaller number is " << myMin(a, b) << std::endl;

    char  c = 'a';
    char d = 'b';

    std::cout << "The bigger character is " << myMax(c, d) << std::endl;
    mySwap(c, d);
    std::cout << "The smaller character is " << myMin(c, d) << std::endl;

    std::string str = "HelloWorld";
    std::string str2 = "SalutToutLeMond";

    std::cout << "The bigger string is " << myMax(str, str2) << std::endl;
    std::cout << "The smaller string is " << myMin(str, str2) << std::endl;

    return 0;
}