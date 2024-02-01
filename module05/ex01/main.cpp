#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
    try
	{
		std::cout << "too low  Test" << std::endl;
		Form f1("f1", 220, 60);
		std::cout << f1 << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		std::cout << "too HIGH  Test" << std::endl;
		Form f2("f2", 0, 1);
		std::cout << f2 << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n";
	try
	{
		Bureaucrat m_bure("b1", 70);
		Form m_form("piece of paper", 50, 1);
		m_bure.signForm(m_form);

		std::cout << m_bure << std::endl;
		std::cout << m_form << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}