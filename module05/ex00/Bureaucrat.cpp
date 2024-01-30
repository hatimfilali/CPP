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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &value) {
    os<< value.getName() << ", bureaucrat grade "<< value.getGrade() << ".";
    return (os);
}