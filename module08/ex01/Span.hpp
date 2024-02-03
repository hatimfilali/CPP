#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class Span
{
private:
    std::vector<int> container;
    unsigned int N;
    bool isSorted;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    void sort();
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    
};

#endif