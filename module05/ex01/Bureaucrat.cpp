#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    *this = copy;
}

Bureaucrat::~Bureaucrat() {


}

Bureaucrat::Bureaucrat(const std::string name, int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    *((std::string *)&this->name) = name;
    this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy) {
        this->grade = copy.getGrade();
        *((std::string *)&this->name) = copy.getName();
    }
    return (*this);
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

void Bureaucrat::increment() {
    this->grade -= 1;
    if(this->grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrement() {
    this->grade += 1;
    if (this->grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) {
    if (form.beSigned(*this))
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else 
        std::cout << this->name << " couldn't sign " << form.getName() << " because Bureaucrat is has low rank" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &value) {
    os<< value.getName() << ", bureaucrat grade "<< value.getGrade() << ".";
    return (os);
}