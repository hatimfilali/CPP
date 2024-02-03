#include "easyfind.hpp"
#include <vector>

int main() {
    std::vector<int> digitalVector;
    digitalVector.push_back(41);
    digitalVector.push_back(42);
    digitalVector.push_back(43);
    digitalVector.push_back(44);
    digitalVector.push_back(45);
    digitalVector.push_back(46);

    try {
        int valueToFind = easyfind(digitalVector, 45);
        std::cout << "Found it in int: " << valueToFind << std::endl;

        char value = easyfind(digitalVector, 45);
        std::cout << "value foundin char: '" << value << "'" << std::endl;

        int notFound = easyfind(digitalVector, 10);
        std::cout  << "the value found in int: " << notFound << std::endl;

        char charValue = easyfind(digitalVector, 20);
        std::cout << "the value found in char: " << charValue << std::endl;
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}