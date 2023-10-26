#include "Harl.hpp"

int main() {
    Harl timu;
    timu.complain("DEBUG");
    std::cout << "[WAITER]: Okay sir you will have to give me 2 dollars more for the extra meat you asked for." << std::endl;
    timu.complain("INFO");
    std::cout << "[WAITER]: It's just how things work here sir." << std::endl;
    timu.complain("WARNING");
    std::cout << "[WAITER]: You still have to pay the 2 dollars sir or I will call the security on you!" << std::endl;
    timu.complain("ERROR");
}
