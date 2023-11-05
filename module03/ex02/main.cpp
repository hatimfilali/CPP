#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>
#include <sstream>

int main(void)
{
	FragTrap one("ONE");
	FragTrap two("TWO");
	one.attack("TWO");
	two.takeDamage(20);
	two.beRepaired(2);
	two.highFivesGuys();

	two.attack("ONE");
	one.takeDamage(60);

	return (0);
}
