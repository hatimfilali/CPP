#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("<target>", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy) {
    *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy) {
    if (this != &copy)
        AForm::operator=(copy);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    CheckPermision(executor);
    std::string fileName = this->getName() + "_shrubbery";
    std::ofstream outputfile(fileName.c_str());
    if (!outputfile.is_open())
        throw ShrubberyCreationForm::FileException();

    outputfile << "             &&& &&  & &&" << std::endl;
    outputfile << "         && &|/&||& ()|/ @, &&" << std::endl;
    outputfile << "         &|/(/&/&||/& /_/)_&/_&" << std::endl;
    outputfile << "      &() &|/&|()|/&|/ '%' & ()" << std::endl;
    outputfile << "     &_ _&&_  |& |&&/&__%_/_& &&" << std::endl;
    outputfile << "   &&   && & &| &| /& & % ()& /&&" << std::endl;
    outputfile << "    ()&_&&-()&/&&|&&-&&--%---()~" << std::endl;
    outputfile << "               &|||&" << std::endl;
    outputfile << "                |||" << std::endl;
    outputfile << "                |||" << std::endl;
    outputfile << "                |||" << std::endl;
    outputfile << "          , -=-~  .-^- _" << std::endl;
    outputfile << "--------------------------------------------------------" << std::endl;
    outputfile << "             &&& &&  & &&" << std::endl;
    outputfile << "         && &|/&||& ()|/ @, &&" << std::endl;
    outputfile << "         &|/(/&/&||/& /_/)_&/_&" << std::endl;
    outputfile << "      &() &|/&|()|/&|/ '%' & ()" << std::endl;
    outputfile << "     &_ _&&_  |& |&&/&__%_/_& &&" << std::endl;
    outputfile << "   &&   && & &| &| /& & % ()& /&&" << std::endl;
    outputfile << "    ()&_&&-()&/&&|&&-&&--%---()~" << std::endl;
    outputfile << "               &|||&" << std::endl;
    outputfile << "                |||" << std::endl;
    outputfile << "                |||" << std::endl;
    outputfile << "                |||" << std::endl;
    outputfile << "          , -=-~  .-^- _" << std::endl;
    outputfile  <<"------------------------------------------------" << std::endl;
    outputfile << "----------- " << executor << " -----------" << std::endl;
    outputfile  <<"------------------------------------------------" << std::endl;
    outputfile.close();
}