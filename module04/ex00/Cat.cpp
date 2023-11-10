#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat Default Constructor Called" <<std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat Copy Constructor Called" << std::endl;    
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy) {
    std::cout << "Cat Copy Assignment Operator Called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meaw Meaw" << std::endl;
}

