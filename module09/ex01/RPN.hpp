#ifndef RPN_CPP
#define RPN_CPP
#include <stack>
#include <string>
#include <iostream>

class RPN
{
private:
    std::stack<int> myStack;
public:
    RPN();
    RPN(std::string expersion);
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);
    ~RPN();
    int takeTop();
};


#endif