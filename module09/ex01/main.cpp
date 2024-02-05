#include "RPN.hpp"

int main (int arc, char **arv) {
    if (arc != 2) {
        std::cout << "Please Enter a valid expretion like: Num1 Num2 + Num3 - ..." <<std::endl;
        return 1;
    }
    try {
        RPN rp(arv[1]);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}