#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->_index = 0;
    std::cout << "Welcome to the Phonebook, where you can store up to 8 conacts." << std::endl;
}

Phonebook::~Phonebook(void)
{
    std::cout << "Have a ggod day sir.." << std::endl;
}

void Phonebook::add(void)
{
    std::string str;
    str = "";
    if (this->_index > 7)
        std::cout << "Warning : you're about to overwrite " << this->_contact[this->_index % 8].GetFirstName() << std::endl;
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter First Name: ";
        if (std::getline(std::cin, str) && str!="")
            this->_contact[this->_index % 8].SetFirstName(str);
    }
    str = "";
    while (!std::cin.eof() && str == "")
    {
        std::cout << "Enter " << this->_contact[this->_index % 8].GetFirstName() << "'s last name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index%8].SetLastName(str);
    }
    str = "";
    while (!std::cin.eof() && str =="")
    {
        std::cout << "Enter " << this->_contact[this->_index % 8].GetFirstName() << "'s nick name: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index%8].SetNickName(str);
    }
    str = "";
    while (!std::cin.eof() && str =="")
    {
        std::cout << "Enter " << this->_contact[this->_index % 8].GetFirstName() << "'s Phone number: ";
        if (std::getline(std::cin, str) && str != "")
            this->_contact[this->_index%8].SetPhoneNumber(str);
    }
    str = "";
    while (!std::cin.eof() && str =="")
    {
        std::cout << "Enter " << this->_contact[this->_index % 8].GetFirstName() << "'s darkest secret: ";
        if (std::getline(std::cin, str) && str != "")
        {
            this->_contact[this->_index%8].SetDarkSecret(str);
            std::cout << this->_contact[this->_index%8].GetFirstName() << " Successfully to the phonbook [" << this->_index % 8 + 1 << "/8]" << std::endl;
        }
    }
    this->_index++;
}

Contact Phonebook::get_contacts(int index)
{
    return (this->_contact[index % 8]);
}

void    Phonebook::print(Contact contact)
{
    std::cout << "Requesting Contact informations from the Phonebook ..." << std::endl;
    if (!contact.GetFirstName().size())
    {
        std::cout << "Failed to get informations for this Contact!" << std::endl;
        return ;
    }
    std::cout << "First Name: " << contact.GetFirstName() << std::endl;
    std::cout << "Last Name: " << contact.GetLastName() << std::endl;
    std::cout << "Nick Name: " << contact.GetNickName() << std::endl;
    std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.GetDarkSecret() << std::endl;
}

void    Phonebook::search (void)
{
    std::string str;
    str ="";

    if(!search_phonebook(this->_contact))
    {
        std::cout << std::endl << "Phonebook is empty." << std::endl;
        return ;
    }
    while(!std::cin.eof())
    {
        std::cout << "Select an index: " << std::endl;
        if (std::getline(std::cin, str) && str != "")
        {
            if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contact[str[0] - 1 -'0'].GetFirstName().size())
                break;
        }
        if (str != "")
            std::cout << "invalid index!" << std::endl;
    }
    if(!std::cin.eof())
        this->print(this->_contact[str[0] - 1 - '0']);
}
