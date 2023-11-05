#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Name Constructor called" << std::endl;
    this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->name = copy.name;
        this->hitPoints = copy.hitPoints;
        this->energyPoints = copy.energyPoints;
        this->attackDamage = copy.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " has no Energy Points" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
     if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " has died." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " took damage, losing " << amount << " points of Hit Points" << std::endl;
    this->hitPoints -= amount;
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " << this->name << " has died." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " has no Energy Points to be repaired" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " has repaired " << amount << " of his Hit Points" << std::endl;
    this->hitPoints += amount;
    this->energyPoints--;
}