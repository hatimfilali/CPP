#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name(""), _signed(false), requiredGradeToSign(1), requiredGradeToExecute(1) {

}

Form::~Form() {

}

Form::Form(const Form &copy) : requiredGradeToSign(1), requiredGradeToExecute(1) {
    if (this != &copy)
        *this = copy;
}

Form::Form(std::string name, int requiredGradeToSign, int requiredGradeToExecute) : name(name), _signed(false), requiredGradeToSign(requiredGradeToSign), requiredGradeToExecute(requiredGradeToExecute) {
    if (requiredGradeToExecute < 1 || requiredGradeToSign < 1)
        throw Form::GradeTooHighException();
    else if (requiredGradeToExecute > 150 || requiredGradeToSign > 150)
        throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		*((std::string *)&this->name) = copy.getName();
		this->_signed = copy.getSigned();
		*((int *)&this->requiredGradeToExecute) = copy.getRequiredGradeToExecute();
		*((int *)&this->requiredGradeToSign) = copy.getRequiredGradeToSign();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getRequiredGradeToSign() const
{
	return (this->requiredGradeToSign);
}

int Form::getRequiredGradeToExecute() const
{
	return (this->requiredGradeToExecute);
}

bool Form::beSigned(Bureaucrat &bureaucrat)
{
	return (this->_signed = bureaucrat.getGrade() <= this->requiredGradeToSign);
}

std::ostream &operator<<(std::ostream &os, const Form &value) {
    os << value.getName() << " , " << (value.getSigned() ? "" : "not ") << "signed, required Grade to sign is "
        << value.getRequiredGradeToSign() << " required grade to execute is " << value.getRequiredGradeToExecute() << std::endl;
    return os;
}
