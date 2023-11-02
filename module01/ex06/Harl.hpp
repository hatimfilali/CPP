#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <iostream>
#include <map>
#include <functional>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void (Harl::*complaints[4])();     
        std::string filter;
        std::string level;
    public:
        Harl(std::string filter);
        ~Harl();
        enum ComplaintLevel { DEBUG, INFO, WARNING, ERROR };
        void complain(std::string level);
};

#endif
