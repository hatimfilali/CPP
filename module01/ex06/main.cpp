#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Invalide Argument number" << std::endl;
        return (1);
    }

    Harl timu = Harl(av[1]);
    
    timu.complain(av[1]);

    return (0);
}
