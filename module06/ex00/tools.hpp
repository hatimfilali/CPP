#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <string>
#include <cstdlib>
#include <climits>
#include <iostream>

enum Type {
    noType = -1,
    charType = 0,
    intType = 1,
    floatType =2,
    doubleType = 3
};

bool psudoLiteral(std::string str);
bool	isNumber(char c);
bool isIntType(std::string str, size_t size);
bool isFloatType(std::string str);
bool isDoubleType(std::string str);
int getType(std::string str);

#endif