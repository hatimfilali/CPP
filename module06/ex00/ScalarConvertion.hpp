#ifndef SCALARCONVERTION_HPP
#define SCALARCONVERTION_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "tools.hpp"

class ScalarConvertion
{
private:
    static std::string str;
    static int intValue;
    static char charValue;
    static float floatValue;
    static double doubleValue;
    static bool unprintable;

    ScalarConvertion();
    ScalarConvertion(const ScalarConvertion &copy);

    static void printInt();
    static void printChar();
    static void printFloat();
    static void printDouble();

public:
    ScalarConvertion &operator=(const ScalarConvertion &copy);
    ~ScalarConvertion();

    static void convert(std::string parameter);

};

#endif