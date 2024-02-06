#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string infileName) {
    this->infile.open(infileName.c_str());
    if (!this->infile.is_open()) {
        std::cout << "couldn't open the file :" << infileName << std::endl;
        exit (1);
    }
    initDate();
    loadData();
    loadInfile();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy) {
        // this->data = copy.data;
        // this->infile = copy.infile;
        // this->MonthDay = copy.MonthDay;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::initDate() {
    this->MonthDay[1] = 31;
    this->MonthDay[3] = 31;
    this->MonthDay[4] = 30;
    this->MonthDay[5] = 31;
    this->MonthDay[6] = 30;
    this->MonthDay[7] = 31;
    this->MonthDay[8] = 31;
    this->MonthDay[9] = 30;
    this->MonthDay[10] = 31;
    this->MonthDay[11] = 30;
    this->MonthDay[12] = 31;
}

void BitcoinExchange::loadData() {
    std::ifstream dataFile("data.csv");
    std::string line;
    std::istringstream line_stream;
    if (!dataFile.is_open()) {
        throw std::runtime_error("Failed to open data file.");
    }
    while (std::getline(dataFile, line)) {
        std::string date;
        std::string value;
        double btc_value = 0.0;
        line_stream.str(line);
        std::getline(line_stream, date, ',');
        std::getline(line_stream, value);
        try
        {
            validDate(date);
            if(!value.empty())
                btc_value = std::atof(value.c_str());
            this->data[date] = btc_value;
        }
        catch(const std::exception& e)
        {
        }
        line_stream.clear();
    }
}

void BitcoinExchange::loadInfile() {
    std::string line;
    std::string str_date;
    std::string sep;
    std::string value;
    double btc_value;
    std::istringstream line_stream;
    std::getline(this->infile, line);
    while (std::getline(this->infile, line)) {
        line_stream.str(line);
        line_stream >> str_date >> sep >> value;
        try {
            checkFormate("dddd-dd-dd | f", line);
            validDate(str_date);
            btc_value = atof(value.c_str());
            range(btc_value, 0.0, 1000.0);
            std::map<std::string, double>::iterator it = this->data.lower_bound(str_date);
            if(it->first != str_date)
                it--;
            std::cout << str_date << " => " << it->second * btc_value << std::endl;
        }
        catch(const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        line_stream.clear();
    }
}
void BitcoinExchange::validDate(std::string str) {
    date v_date;
    std::istringstream ss(str);
    char dash;
    ss >> v_date.year >> dash >> v_date.month >> dash >> v_date.day;
    range(v_date.year, 2009, INT_MAX);
    range(v_date.month, 1, 12);
    if (v_date.month == 2) {
        if(v_date.year % 4 == 0 && (v_date.year % 100 == 0 && v_date.year % 400 != 0))
            range(v_date.day, 1, 29);
        else 
            range(v_date.day, 1, 28);
    }
    else 
    range(v_date.day, 1, this->MonthDay[v_date.month]);
}
bool is_double (std::string str) {
    bool dot = false;
    std::string::iterator it = str.begin();
    if (*it == '-' || *it == '+')
        it ++;
    while (it != str.end())
    {
        if (*it == '.') {
            if (dot == true)
                return false;
            else 
                dot = true;
        }
        else if (!std::isdigit(*it))
            return false;
        it++;
    }
    return true;
}

void checkFormate(std::string formate, std::string line) {
    for (size_t i = 0; i < formate.size(); i++)
	{
		if (formate[i] == 'd')
		{
			if (!std::isdigit(line[i]))
				throw std::runtime_error("Error: bad input => " + line);
		}
		else if (formate[i] == 'f')
		{
			if (!is_double(&line[i]))
				throw std::runtime_error("Error: bad input => " + line);
		}
		else
		{
			if (formate[i] != line[i])
				throw std::runtime_error("Error: bad input => " + line);
		}
	}
}