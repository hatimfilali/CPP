#include "Harl.hpp"

Harl::Harl() {
    complains[DEBUG] = &Harl::debug;
    complains[INFO] = &Harl::info;
    complains[WARNING] = &Harl::warning;
    complains[ERROR] = &Harl::error;
}

Harl::~Harl() {

}

void Harl::complain(ComplainLevels level) {
    std::string Levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    std::cout << "[" << Levels[level] << "]: ";
    
    (this->*complains[level])();
}

void Harl::debug(void) {
    std::cout <<  "I love having extra meat for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout <<  "I cannot believe adding extra meat costs more money. You didn’t put enough meat in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout <<  "I think I deserve to have some extra meat for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout <<  "This is unacceptable! I want to speak to your boss now." << std::endl;
}
