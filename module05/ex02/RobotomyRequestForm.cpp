#include "RobotomyRequestForm.hpp"

int RobotomyRequestForm::success = 0;

RobotomyRequestForm::RobotomyRequestForm() : AForm("<target>", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy) {
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &copy) {
    if (this != &copy)
        AForm::operator=(copy);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    CheckPermision(executor);
    std::cout << executor.getName() << " " << ((++success) % 2 ? "has been robotmized successfully" : "robotmy failed" ) << std::endl;
}