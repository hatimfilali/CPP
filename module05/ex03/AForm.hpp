#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;
class AForm {
    private:
        const std::string name;
        bool singed;
        const int requiredGradeToSign;
        const int requiredGradeToExecute;
    
    public :
        AForm();
        AForm(const AForm &copy);
        AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute);
        AForm &operator=(const AForm &copy);
        virtual ~AForm();

        std::string getName() const;
        bool getSigned() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExecute() const;
        bool beSigned(Bureaucrat &Bureaucrat);
        void CheckPermision(Bureaucrat const &executor) const;
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception {
            public :
                const char *what() const throw() {
                    return "Too high grade.";
                }
        };
        class GradeTooLowException : public std::exception {
            public :
                const char *whta() const throw() {
                    return "Too low grade.";
                }
        };
        class UnSignedException : public std::exception {
            public : 
                const char *what() const throw() {
                    return "The form is not signed.";
                }
        };
};
std::ostream &operator<<(std::ostream& os, const AForm &value);

#endif