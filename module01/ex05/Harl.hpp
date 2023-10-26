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
        std::map<std::string, void(Harl::*) ()> complains_list;       

    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

#endif
