#include <iostream>
#include "Array.hpp"
#include <string>

struct User
{
    int id;
    std::string _name;
    std::string phone_number;
    std::string _passowrd;
    long day_of_birth_as_timestamp;
};

User new_user()
{
    User m_user;
    m_user.day_of_birth_as_timestamp = 1692387713;
    m_user.id = 0;
    m_user.phone_number = "+2129854612";
    m_user._passowrd = "@@@@122121@@";
    m_user._name = "m_user";
    return m_user;
}


int main()
{
    Array<int> org(5);

    Array<int> COPY_ASSINGMENT = org;

    Array<int> COPY_CONSTRUCTOR(org);

    std::cout
        << "Default Values of org"
        << std::endl;
    std::cout << org;
    std::cout
        << "*********************** \n"
        << std::endl;

    std::cout << "Default Values of COPY_ASSINGMENT" << std::endl;
    std::cout << COPY_ASSINGMENT;
    std::cout << "*********************** \n"
              << std::endl;

    std::cout << "Default Values COPY_CONSTRUCTOR" << std::endl;
    std::cout << COPY_CONSTRUCTOR;
    std::cout << "*********************** \n"
              << std::endl;

    // CHANGE VALUES
    std::cout << "Change the 3 arrays Values \n"
              << std::endl;

    std::cout << "\033[32m"
              << "Change Values of org"
              << "\033[0m" << std::endl;
    for (size_t i = 0; i < org.size(); i++)
        org[i] = i * 2;
    std::cout
        << "*********************** \n"
        << std::endl;

    std::cout << "\033[32m"
              << "Change Values of COPY_ASSINGMENT"
              << "\033[0m" << std::endl;
    for (size_t i = 0; i < org.size(); i++)
        org[i] = i + 2;
    std::cout << "*********************** \n"
              << std::endl;

    std::cout << "\033[32m"
              << "Change Values COPY_CONSTRUCTOR"
              << "\033[0m" << std::endl;
    for (size_t i = 0; i < org.size(); i++)
        org[i] = i - 2;
    std::cout << "*********************** \n"
              << std::endl;

    std::cout << "New Values of org" << std::endl;
    std::cout << org;
    std::cout
        << "*********************** \n"
        << std::endl;

    std::cout << "New Values of COPY_ASSINGMENT" << std::endl;
    std::cout << COPY_ASSINGMENT;
    std::cout << "*********************** \n"
              << std::endl;

    std::cout << "New Values COPY_CONSTRUCTOR" << std::endl;
    std::cout << COPY_CONSTRUCTOR;
    std::cout << "*********************** \n"
              << std::endl;
    try
    {
        std::cout << "out of index   : " << org[3000] << ">" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    Array<User> users(20);
    users[0] = new_user();
    std::cout << "name " << users[0]._name << std::endl;
}