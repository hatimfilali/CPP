#include "Replacement.hpp"

Replacement::Replacement(std::string infileName, std::string str, std::string rp) {
    this->infileName = infileName;
    this->str = str;
    this->rp = rp;
}

Replacement::~Replacement() {

}

std::string Replacement::Replace(std::string line) {
    std::string temp;
    std::string result;
    for(size_t i = 0; i < line.length(); i++) {
        temp += line[i];
        if (temp == str) {
            result += rp;
            temp.clear();
        }
        else if (temp.length() >= str.length()) {
            result += temp.at(0);
            temp.erase(temp.begin());
        }
    }
    result += temp;
    return (result);
}

void Replacement::CpyandReplace() {
    std::ifstream infile(infileName.c_str());
    std::string line;
    if (!infile.is_open() || !infile.good()) {
        std::cout << "Error opening the file" << infileName << std::endl;
        return;
    }
    std::ofstream outfile((infileName + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cout << "Error creanting the relpace file: " << std::endl;
        return;
    }
    while (std::getline(infile, line)) {
        if (infile.peek() != EOF) 
            line += "\n";
        else 
            line += "";
        outfile << Replace(line);
    }
    infile.close();
    outfile.close();
}
