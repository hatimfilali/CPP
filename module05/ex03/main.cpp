#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
    try
    {
        Bureaucrat bureaucrat("ash", 1); // error with 200
        AForm *form1, *form2, *form3;
        
        std::cout << "\n--------------- Intern Creates Forms ---------------" << std::endl;
        Intern someRandomIntern;
        form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        form3 = someRandomIntern.makeForm("presidential pardon", "presidential");
        form1 = someRandomIntern.makeForm("shrubbery creation", "shrubbery");
        
        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);
        
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        bureaucrat.executeForm(*form2);
        
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(*form3);
        bureaucrat.executeForm(*form3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
