#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private :
        int grade;
        const std::string name;

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

