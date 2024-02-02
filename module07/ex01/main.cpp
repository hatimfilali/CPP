#include "iter.hpp"

int main () {
    std::string str = "HelloWorld";
    iter(str.c_str(), str.length(), printer);
}