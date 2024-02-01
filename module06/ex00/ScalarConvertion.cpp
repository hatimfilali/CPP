#include "ScalarConvertion.hpp"
#include "tools.hpp"
#include <cstring>
#include <climits>


int ScalarConvertion::intValue = 0;
char ScalarConvertion::charValue = 0;
float ScalarConvertion::floatValue = 0;
double ScalarConvertion::doubleValue = 0;
std::string ScalarConvertion::str = "";
bool ScalarConvertion::unprintable = false;

ScalarConvertion::ScalarConvertion() {

}

ScalarConvertion::ScalarConvertion(const ScalarConvertion &copy) {
    *this = copy;
}

ScalarConvertion &ScalarConvertion::operator=(const ScalarConvertion &copy) {
    (void)copy;
    return *this;
}

ScalarConvertion::~ScalarConvertion() {

}

void ScalarConvertion::printInt() {
    std::cout << "int: ";
    if (psudoLiteral(str))
        std::cout << "impossible" << std::endl;
    else 
        std::cout << intValue << std::endl;
}

void ScalarConvertion::printChar() {
    std::cout << "char: ";
    if (psudoLiteral(str) || unprintable)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(charValue))
        std::cout<< "Non Displayable" << std::endl;
    else 
        std::cout << "'"<< charValue << "'" << std::endl;
}

void ScalarConvertion::printFloat() {
    std::cout << "float: ";
    if (psudoLiteral(str)) {
        if (str == "+inf")
			std::cout << "+inff" << std::endl;
		else if (str == "-inf")
			std::cout << "-inff" << std::endl;
		else if (str == "nan")
			std::cout << "nanf" << std::endl;
		else
			std::cout << str << std::endl;
    }
    else 
        std::cout << floatValue << std::endl;
}

void ScalarConvertion::printDouble() {
    std::cout << "double: ";
    if (psudoLiteral(str)) {
        if (str == "+inff")
			std::cout << "+inf" << std::endl;
		else if (str == "-inff")
			std::cout << "-inf" << std::endl;
		else if (str == "nanf")
			std::cout << "nan" << std::endl;
		else
			std::cout << str << std::endl;
    }
    else 
        std::cout << doubleValue << std::endl;
}

void ScalarConvertion::convert(std::string parameter) {
    int type;
    type = getType(parameter);
    str = parameter;
    switch (type)
    {
    case charType:
        charValue = static_cast<char>(parameter.at(0));
        intValue  = static_cast<int>(charValue);
        floatValue = static_cast<float>(charValue);
        doubleValue = static_cast<double>(charValue);
        break;
    case intType:
        intValue = atoi(parameter.c_str());
        if (intValue < CHAR_MIN || intValue > CHAR_MAX)
            unprintable = true;
        else 
            charValue = static_cast<char>(intValue);
        floatValue = static_cast<float>(intValue);
        doubleValue = static_cast<double>(intValue);
        break;
    case floatType:
        floatValue = atof(parameter.c_str());
        if(floatValue < CHAR_MIN || floatValue > CHAR_MAX)
            unprintable = true;
        else 
            charValue = static_cast<char>(floatValue);
        intValue = static_cast<int>(floatValue);
        doubleValue = static_cast<double>(floatValue);
        break;
    case doubleType:
        doubleValue = atof(parameter.c_str());
        if(doubleValue < CHAR_MIN || doubleValue > CHAR_MAX)
            unprintable = true;
        else
            charValue = static_cast<char>(doubleValue);
        intValue = static_cast<int>(doubleValue);
        floatValue = static_cast<float>(doubleValue);
        break;
    case noType:
        break;
    }
    printChar();
    printInt();
    printFloat();
    printDouble();
}
