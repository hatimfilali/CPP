#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

std::string Contact::GetFirstName(void)
{
    return (this->FirstName);
}

std::string Contact::GetLastName(void)
{
    return (this->LastName);
}

std::string Contact::GetNickName(void)
{
    return (this->NickName);
}

std::string Contact::GetPhoneNumber(void)
{
    return (this->PhoneNumer);
}

std::string Contact::GetDarkSecret(void)
{
    return (this->DarkSecret);
}

void Contact::SetFirstName(std::string str)
{
    this->FirstName = str;
}

void Contact::SetLastName (std::string str)
{
    this->LastName = str;
}

void Contact::SetNickName (std::string str)
{
    this->NickName = str;
}

void Contact::SetPhoneNumber (std::string str)
{
    this->PhoneNumer = str;
}

void Contact::SetDarkSecret (std::string str)
{
    this->DarkSecret = str;
}
