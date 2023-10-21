
#include "Zombie.hpp"

int main(){
    Zombie *m_zombies = zombieHorde(7, "Freakers");
    
    for (size_t i = 0; i < 7; i++)
        m_zombies[i].announce();
    delete[] m_zombies;
    return (0);
}
