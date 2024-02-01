#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &copy) {
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
    (void)copy;
    return(*this);
}

int FindIndex(int listSize, std::string list[], std::string toFind) {
    for (int i = 0; i < listSize; i++)
    {
        if (list[i] == toFind)
            return i;
    }
    return -1;
}

AForm *Intern::makeForm(std::string name, std::string target) {
    std::string FormNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *AvailibaleForms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
    AForm *selected = NULL;
    int index = FindIndex(3, FormNames, name);
    if (index == -1)
        throw Intern::InvalidFormException();
    selected = AvailibaleForms[index];
    for (int i = 0; i < 3; i++)
    {
        if(i != index)
            delete AvailibaleForms[i];
    }
    std::cout << "Intern creates " << *selected << std::endl;
    return selected;
}

Intern::~Intern() {
    
}