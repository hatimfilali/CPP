#include "Span.hpp"

int main() {
    // try {
    // Span span(20000);
    // std::vector<int> vec(10000);
    // std::iota(vec.begin(), vec.end(), 1);



    // span.addRange(vec.begin(), vec.end());

    // std::cout << span.shortestSpan() << std::endl;
    // std::cout << span.longestSpan() << std::endl;

    // span.addNumber(500000);

    // std::cout << span.shortestSpan() << std::endl;
    // std::cout << span.longestSpan() << std::endl;
    // }
    // catch(std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }
    Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;

}