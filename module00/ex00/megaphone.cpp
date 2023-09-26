
#include <iostream>

int main (int arc, char **arv)
{
    int		i;
	int		j;

	if (arc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	j = -1;
	while (arc > 1 && arv && arv[++j])
	{
		i = -1;
		while (j > 0 && arv[j][++i])
			std::cout << (char)std::toupper(arv[j][i]);
	}
	std::cout << std::endl;
	return (0);
}