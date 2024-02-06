#include "PergeMe.hpp"

int main (int arc, char **arv) {
    if (arc > 1) {
        try {
            PergeMe(arc, arv);
        }
        catch (std::exception &e) {
            std::cout << e.what() <<std::endl;
        }
    } else 
        std::cout << "You should Enter the numbers you want to sort" << std::endl;
}