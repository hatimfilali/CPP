#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(""), singed(false), requiredGradeToSign(1), requiredGradeToExecute(1){

}

AForm::AForm(const AForm &copy) : requiredGradeToSign(1), requiredGradeToExecute(1)
{
	*this = copy;
}

AForm::AForm(std::string name, int requiredGradeToSign, int requiredGradeToExecute) : name(name), singed(false), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute)
{
	if (requiredGradeToExecute < 1 || requiredGradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (requiredGradeToExecute > 150 || requiredGradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm	&AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		*((std::string *)&this->name) = copy.getName();
		this->singed = copy.getSigned();
		*((int *)&this->requiredGradeToExecute) = copy.getRequiredGradeToExecute();
		*((int *)&this->requiredGradeToSign) = copy.getRequiredGradeToSign();
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getSigned() const
{
	return (this->singed);
}

int	AForm::getRequiredGradeToSign() const
{
	return (this->requiredGradeToSign);
}

int	AForm::getRequiredGradeToExecute() const
{
	return (this->requiredGradeToExecute);
}

bool	AForm::beSigned(Bureaucrat &bureaucrat)
{
	return (this->singed = bureaucrat.getGrade() <= this->requiredGradeToSign);
}

void	AForm::CheckPermision(Bureaucrat const & executor) const
{
	if(!this->singed)
		throw AForm::UnSignedException();
	if(this->requiredGradeToExecute < executor.getGrade())
		throw AForm::GradeTooLowException();
}

AForm::~AForm () {
	
}
std::ostream &operator<<(std::ostream &os, const AForm &value) {
    os << value.getName() << " , " << (value.getSigned() ? "" : "not ") << "signed, required Grade to sign is "
        << value.getRequiredGradeToSign() << " required grade to execute is " << value.getRequiredGradeToExecute() << std::endl;
    return os;
}

