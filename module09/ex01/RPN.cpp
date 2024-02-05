#include "RPN.hpp"

RPN::RPN() {

}

RPN::RPN(std::string expression) {
    for (size_t i = 0; i < expression.size(); i++) {
        if (std::isdigit(expression[i]))
            this->myStack.push(expression[i] - '0'); // Convert character to integer
        else if (expression[i] == '*') {
            if (this->myStack.size() < 2)
                throw std::runtime_error("Invalid operation");
            int n = takeTop();
            int m = takeTop();
            this->myStack.push(m * n);
        }
        else if (expression[i] == '/') {
            if (this->myStack.size() < 2)
                throw std::runtime_error("Invalid operation");
            int n = takeTop();
            int m = takeTop();
            this->myStack.push(m / n);
        }
        else if (expression[i] == '+') {
            if (this->myStack.size() < 2)
                throw std::runtime_error("Invalid operation");
            int n = takeTop();
            int m = takeTop();
            this->myStack.push(m + n);
        }
        else if (expression[i] == '-') {
            if (this->myStack.size() < 2)
                throw std::runtime_error("Invalid operation");
            int n = takeTop();
            int m = takeTop();
            this->myStack.push(m - n);
        }
        else if (expression[i] != ' ')
            throw std::runtime_error("Invalid character");
    }
    std::cout << this->myStack.top() << std::endl;
}



RPN::RPN(const RPN &copy) {
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy) {
    if(this != &copy)
        this->myStack = copy.myStack;
    return *this;
}

RPN::~RPN() {

}

int RPN::takeTop() {
    int result = this->myStack.top();
    this->myStack.pop();
    return (result);
}