#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "tools.hpp"

class Phonebook
{
    private:
        Contact _contact[8];
        int     _index;
    public:
        Phonebook(void);
        ~Phonebook(void);
        void    add(void);
        void    search(void);
        void    print(Contact contact);
        Contact get_contacts(int index);
};

#endif