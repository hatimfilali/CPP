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
        std::map<std::string, int> levels;       
        typedef void (Harl::*harl_voice) ();
        std::string filter;
        std::string level;
    public:
        Harl(std::string filter);
        ~Harl();
        void complain(std::string level);
};

#endif
