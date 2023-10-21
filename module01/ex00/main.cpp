#include "Zombie.hpp"

int main() {
    Zombie* poo = newZombie("poo");
    poo->announce();
    delete poo;
    randomChump("timu");
    Zombie test("test");
    test.announce(); 
    return 0;
}
