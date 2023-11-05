#include "ClapTrap.hpp"

int main () {
    ClapTrap cp1("timu");
    ClapTrap cp2("duny");

    cp1.attack("duny");
    cp2.beRepaired(10);
    cp2.attack("timu");
    cp1.takeDamage(50);
    cp1 = cp2;
}