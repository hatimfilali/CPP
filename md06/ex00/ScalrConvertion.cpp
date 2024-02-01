#include "ScalarConvertion.hpp"
#include <cstring>
#include <climits>

enum Type {
    charType = 0,
    intType = 1,
    floatType =2,
    doubleType = 3
};

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

bool psudoLiteral(std::string str) {
    if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "-inff" || str =="+inff")
        return (true);
    return (false);
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
    if (psudoLiteral(str))
        std::cout << "impossible" << std::endl;
    else 
        std::cout << charValue << std::endl;
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

bool isIntType(std::string str, size_t size) {

}

bool isFloatType(std::string str) {

}

int getType(std::string str) {
    if (str.length() == 1 && (str[0] < 48 || str[0] > 57) && std::isprint(str[0]))
		return (charType);
    else if (isIntType(str, str.length()))
        return (intType);
    else if (isFloatType(str))
        return(floatType);
}

void ScalarConvertion::convert(std::string parameter) {
    int type;
    type = getType(parameter);

}
