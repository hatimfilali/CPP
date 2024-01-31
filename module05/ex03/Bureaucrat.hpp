#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat {
    private: 
        const std::string name;
        int grade;

    public :
        Bureaucrat();
        Bureaucrat(const Bureaucrat &coppy);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &copy);
        Bureaucrat(const std::string name, int grade);

        int getGrade() const;
        std::string getName() const;
        void increment();
        void decrement();
        void signForm(AForm &form);
        void executeForm(AForm const &form);

        class GradeTooHighException : public std::exception {
            public :
                const char *what() const throw() {
                    return "Too high grade.";
                }
        };
        class GradeTooLowException : public std::exception {
            public :
                const char *what() const throw() {
                    return "Too low grade.";
                }
        };
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &value);

#endif