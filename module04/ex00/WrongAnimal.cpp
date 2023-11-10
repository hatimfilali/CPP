#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("some WrongAnimal") {
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) {
    std::cout << "WrongAnimal Type Constructor called" << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
    std::cout << "WrongAnimal Copy Assignment operator called" << std::endl;;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "Some Sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}
