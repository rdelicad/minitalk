/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:07 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/11 19:53:02 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/minitalk.h"

int	g_stop = 0;

void	handler(int pid, char *msn)
{
	int	i;

	i = 0;
	while (*msn != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if (*msn & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(3);
			i--;
		}
		msn++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || !ft_str_isdigit(av[1]))
	{
		ft_printf("Uso: %s <PID del servidor> <mensaje>\n", av[0]);
		return (1);
	}
	handler(ft_atoi(av[1]), av[2]);
	return (0);
}
