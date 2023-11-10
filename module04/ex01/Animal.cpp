#include "Animal.hpp"

Animal::Animal() : type("some animal") {
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type) {
    std::cout << "Animal Type Constructor called" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
    std::cout << "Animal Copy Assignment operator called" << std::endl;;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Some Sound" << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}
