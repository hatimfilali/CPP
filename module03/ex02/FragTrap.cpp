#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap Default Constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Name Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    std::cout << "FragTrap Copy Assignment called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy);
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "high fives you people !!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (this->energyPoints <= 0) {
        std::cout << "FragTrap " << this->name << " has no energy left" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}
