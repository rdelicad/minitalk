#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	unsigned char	octet;

	if (ac != 2)
		return (1);
	octet = av[1][0];
	printf("Caracter: (%c), Ascii (%d), Binario: ", octet, octet);
	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			printf("1");
		else
			printf("0");
		i--;
	}
	printf("\n");
	return (0);
}