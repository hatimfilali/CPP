
#include <iostream>

int main (int arc, char **arv)
{
    int		i;
	int		j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	j = -1;
	while (argc > 1 && argv && argv[++j])
	{
		i = -1;
		while (j > 0 && argv[j][++i])
			std::cout << (char)std::toupper(argv[j][i]);
	}
	std::cout << std::endl;
	return (0);
}