#include "iter.hpp"

int main () {
    int table[] = {1, 2, 3, 4, 5, 6, 7};

    ::iter(table, 6, printer<const int>);

    ::iter(table, 6, printer<int>);
    
}