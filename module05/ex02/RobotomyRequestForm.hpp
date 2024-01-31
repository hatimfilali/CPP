#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    private :
        static int success;
    
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const &executor) const;
};

#endif