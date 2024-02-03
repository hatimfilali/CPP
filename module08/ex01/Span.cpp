#include "Span.hpp"

Span::Span() : N(0), isSorted(false) {
    
}

Span::Span(unsigned int n) : N(n), isSorted(false) {

}

Span::Span(const Span &copy) {
    *this = copy;
}

Span &Span::operator=(const Span &copy) {
    if (this != &copy) {
        this->N = copy.N;
        for (size_t i = 0; i < copy.container.size(); i++)
        {
            this->container.push_back(copy.container.at(i));
        }
    }
    return *this;
}

Span::~Span() {

}

void Span::addNumber(int number) {
    if (container.size() >= N)
        throw std::runtime_error("Span is full.");
    container.push_back(number);
    isSorted = false;
}

void Span::sort() {
    if (!isSorted)
        std::sort(container.begin(), container.end());
    isSorted = true;
}

int Span::shortestSpan() {
    if (this->container.size() == 1 || this->N == 0)
        throw std::runtime_error("there no short distance because you have less than 2 numbers");
    int distance = std::numeric_limits<int>::max();
    sort();
    int tmp = 0;
    for (std::vector<int>::iterator i = this->container.begin(); i != this->container.end(); i++) {
        tmp = *(i +1) - *i;
        if (tmp < distance && tmp > 0)
            distance = tmp;
    }
    return (distance);
}

int Span::longestSpan() {
    if (this->container.size() == 1 || this->N == 0)
        throw std::runtime_error("there no short distance because you have less than 2 numbers");
    sort();
    return (this->container.at(this->container.size() - 1) - this->container.at(0));
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    this->container.insert(this->container.end(), begin, end);
}