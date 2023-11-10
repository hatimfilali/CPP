#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat Default Constructor Called" <<std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "WrongCat Copy Constructor Called" << std::endl;    
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
    std::cout << "WrongCat Copy Assignment Operator Called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meaw Meaw" << std::endl;
}

