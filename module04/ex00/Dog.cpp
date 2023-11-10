#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog Default Constructor Called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy) { 
    std::cout << "Dog Copy Constructor Called"  << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << " Dog Copy Assignment Operator Called" << std::endl;
    if(this != &copy)
        this->type = copy.type;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}

