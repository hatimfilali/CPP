#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include <string>
#include <exception>

class Intern {
    public :
        Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);
        class InvalidFormException : public std::exception {
            public :
                const char *waht() const throw() {
                    return "Invalid Form";
                }
        };
};

#endif