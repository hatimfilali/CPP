#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <iostream>

class Span
{
private:
    

public:
    Span();
    Span(unsigned int n);
    Span(const Span &copy);
    Span &operator=(const Span &copy);
    ~Span();
    void addNumber(int number);


    class SpanFullException : public std::exception {
        public :
            const char *what() const throw(){
                return "The Span is full.";
            }
    };
    
};

#endif