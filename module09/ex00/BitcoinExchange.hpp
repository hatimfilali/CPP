#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <sstream>

struct date
{
    int day;
    int month;
    int year;
};


class BitcoinExchange
{
private:
    std::ifstream infile;
    std::map<int , int> MonthDay;
    std::map<std::string, double> data;
    void initDate();
    void loadData();
    void loadInfile();
    void validDate(std::string);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange(std::string infileName);
    BitcoinExchange &operator=(const BitcoinExchange &copy);
    ~BitcoinExchange();


};
void checkFormate(std::string formate, std::string line);
bool is_double(std::string str);

template <typename T>
void range(T value, T min, T max) {
    if (value < 0)
        throw std::runtime_error("Error: not a positive number.");
    if (value > max)
        throw std::runtime_error("Error: too large a number.");
    if (value < min)
        throw std::runtime_error("Error: too small a number.");
}

#endif