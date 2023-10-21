#include "Phonebook.hpp"

int main (void)
{
    Phonebook   ph;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << "Enter a command > ";
        std::getline(std::cin, str);
        if (str == "ADD")
            ph.add();
        else if (str == "SEARCH")
            ph.search();
        if (std::cin.eof())
        {
            std::cout << std ::endl;
            return (0);
        }
    }
    return (0);
}
