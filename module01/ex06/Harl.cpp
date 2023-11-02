#include "Harl.hpp"
#include <climits>
Harl::Harl(std::string filter) : filter(filter) {
        complaints[DEBUG] = &Harl::debug;
        complaints[INFO] = &Harl::info;
        complaints[WARNING] = &Harl::warning;
        complaints[ERROR] = &Harl::error;
    }

Harl::~Harl() {

}

void Harl::complain(std::string level) {
        this->level = level;
        int currentLevel = -1;

        if (level == "DEBUG") {
            currentLevel = DEBUG;
        } else if (level == "INFO") {
            currentLevel = INFO;
        } else if (level == "WARNING") {
            currentLevel = WARNING;
        } else if (level == "ERROR") {
            currentLevel = ERROR;
        }

        switch (currentLevel) {
            case DEBUG:
                (this->*complaints[DEBUG])();
                // Intentional fall-through 
            case INFO:
                (this->*complaints[INFO])();
                // Intentional fall-through
            case WARNING:
                (this->*complaints[WARNING])();
                // Intentional fall-through
            case ERROR:
                (this->*complaints[ERROR])();
                break;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        }
    }

void Harl::debug(void) {
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra meat for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO]" << std::endl;
    std::cout <<  "I cannot believe adding extra meat costs more money. You didn’t put enough meat in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl;
    std::cout <<  "I think I deserve to have some extra meat for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl;
    std::cout <<  "This is unacceptable! I want to speak to your boss now." << std::endl;
    std::cout << std::endl;
}
