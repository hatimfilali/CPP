#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

public:
    void execute(Bureaucrat const &executor) const;
    class FileException : public std::exception
	{
	  public:
		const char *what() const throw()
		{
			return "Error opening the file.";
		}
	};
};
#endif