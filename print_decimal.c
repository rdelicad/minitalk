#include "libft/libft.h"

int	binary_decimal(char *binary)
{
	int	decimal;
	int	i;

	decimal = 0;
	i = 7;
	while (i >= 0)
	{
		if (binary[i] == '1')
			decimal += 1 << (7 - i);
		i--;
	}
	return (decimal);
}

int main(int ac, char **av)
{
	char	*n_binary;
	int		decimal;

	n_binary = av[1];
	if (ac != 2)
		ft_printf("Uso: %s <numero_binario 8 digitos>\n", av[0]);
	if (ft_strlen(n_binary) != 8)
		ft_error(2, "El numero debe de ser de 8 digitos");
	decimal = binary_decimal(n_binary);
	if (decimal >= 32 && decimal <= 126)
		ft_printf("Caracter ASCII: %c\n", (char)decimal);
	else
		ft_printf("%d no corresponede a un caracter imprimible\n", decimal );
	return (0);
}