#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

    if (ac != 2)
    {
        std::cout << "please provide a inpute file" << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange btc(av[1]);
    }catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}