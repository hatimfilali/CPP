#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <iostream>
#include <map>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void (Harl::*complains[4])();     

    public:
        Harl();
        
        ~Harl();
        enum ComplainLevels { DEBUG, INFO, WARNING, ERROR };
        void complain(ComplainLevels level);
};     

#endif
