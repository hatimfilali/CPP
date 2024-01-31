#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("<target>", 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5){

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy) {
    *this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
    if(this != &copy)
        AForm::operator=(copy);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    CheckPermision(executor);
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox."<< std::endl;
}