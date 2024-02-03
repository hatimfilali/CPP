#include "whatever.hpp"
#include <iostream>

int main () {
    int a = 12;
    int b = 0;

    std::cout << "The bigger number is " << ::max(a, b) << std::endl;
    ::swap(a, b);
    std::cout << "The smaller number is " << ::min(a, b) << std::endl;

    char  c = 'a';
    char d = 'b';

    std::cout << "The bigger character is " << ::max(c, d) << std::endl;
    ::swap(c, d);
    std::cout << "The smaller character is " << ::min(c, d) << std::endl;

    std::string str = "HelloWorld";
    std::string str2 = "SalutToutLeMond";

    std::cout << "The bigger string is " << ::max(str, str2) << std::endl;
    std::cout << "The smaller string is " << ::min(str, str2) << std::endl;

    return 0;
}