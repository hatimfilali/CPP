#include "Bureaucrat.hpp"

int main () {
    try {
        std::cout << "-------When fine...-------"<< std::endl;
        Bureaucrat fineBureaucrat("FineOne", 71);
        std::cout << fineBureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "-------When Too low-------" << std::endl;
        Bureaucrat tooLowOne("TooLow", 151);
        std::cout << tooLowOne << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "-------When Too High-------" << std::endl;
        Bureaucrat tooHighOne("TooHigh", 0);
        std::cout << tooHighOne << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "-------Increment-------" << std::endl;
        Bureaucrat inc("Inc", 150);
        for (int i = 0; i < 150; i++) {
            inc.increment();
            std::cout << inc << std::endl;
        }
    }
    catch(Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "-------Decrement-------" << std::endl;
        Bureaucrat dec("Dec", 1);
        for (int i = 0; i < 150; i++) {
            dec.decrement();
            std::cout << dec << std::endl;
        }
    }
    catch(Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
}