#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form {
    private:
        const std::string name;
        bool _signed;
        const int requiredGradeToSign;
        const int requiredGradeToExecute;
    
    public:
        Form();
        Form(const Form &copy);
        Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
        Form &operator=(const Form &copy);
        ~Form();

        std::string getName() const;
        bool getSigned() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExecute() const;
        bool beSigned(Bureaucrat &Bureaucrat);

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
std::ostream &operator<<(std::ostream &os, const Form &value);

#endif