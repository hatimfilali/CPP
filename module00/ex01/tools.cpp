#include "tools.hpp"

std::string add_spaces(int n)
{
    std::string str;

    while (n--)
        str.append(" ");
    return (str);
}

std::string fix_size(std::string str, long unsigned max)
{
    if (str.size() > max)
    {
        str.resize(max);
        str[str.size() - 1] = '.';
    }
    return str;
}

int search_phonebook(Contact contact[8])
{
    char		c;
	int			i;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contact[c - 1 - '0'].GetFirstName().size() && ++i)
		{
			str = c;
			str = fix_size(str, 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_size(contact[c - 1  - '0'].GetFirstName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_size(contact[c - 1 - '0'].GetLastName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			str = fix_size(contact[c - 1 - '0'].GetNickName(), 10);
			std::cout << "|" << add_spaces(10 - str.size()) << str;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
	return (i);
}