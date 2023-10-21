#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumer;
    std::string DarkSecret;

public:
    Contact(void);
    ~Contact(void);

    std::string GetFirstName(void);
    std::string GetLastName(void);
    std::string GetNickName(void);
    std::string GetPhoneNumber(void);
    std::string GetDarkSecret(void);
    void        SetFirstName(std::string str);
    void        SetLastName(std::string str);
    void        SetNickName(std::string str);
    void        SetPhoneNumber(std::string str);
    void        SetDarkSecret(std::string str);
};

#endif
