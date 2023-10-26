#ifndef REPLACEMENT_HPP
#define REPLACEMENT_HPP

#include <string>
#include <iostream>
#include <fstream>

class Replacement {
    private:
        std::string str;
        std::string rp;
        std::string infileName;
        std::string Replace(std::string line);

    public:
        Replacement(std::string infileName, std::string str, std::string rp);
        ~Replacement();
        void CpyandReplace();
};
#endif
