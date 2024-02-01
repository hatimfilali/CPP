#include "ScalarConvertion.hpp"
#include "tools.hpp"
bool psudoLiteral(std::string str) {
    if (str == "nan" || str == "nanf" || str == "-inf" || str == "+inf" || str == "-inff" || str =="+inff")
        return (true);
    return (false);
}

bool	isNumber(char c) {
	return (c >= '0' && c <= '9');
}

bool isIntType(std::string str, size_t size) {
    size_t i  = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < size) {
        if (!isNumber(str[i]))
            return false;
        i++;
    }
    return true;
}

bool isFloatType(std::string str) {
    int dotPosition = str.find_first_of('.');
    int fPosition = str.find_first_of('f');
    if (dotPosition == -1 || fPosition == -1 || dotPosition > fPosition)
        return false;
    return (isIntType(str, dotPosition) && isIntType(&str[dotPosition + 1], fPosition - dotPosition - 1) && str[str.length() - 1] == 'f');
}

bool isDoubleType(std::string str) {
    int dotPosition = str.find_first_of('.');
    if (dotPosition == -1)
        return false;
    return (isIntType(str, dotPosition) && isIntType(&str[dotPosition + 1], str.length() - dotPosition - 1));
}

int getType(std::string str) {
    if (str.length() == 1 && (str[0] < 48 || str[0] > 57) && std::isprint(str[0]))
		return (charType);
    else if (isIntType(str, str.length()))
        return (intType);
    else if (isFloatType(str))
        return(floatType);
    else if (isDoubleType(str))
        return (doubleType);
    return (noType);
}
