/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:07 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/18 15:22:24 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
			usleep(35);
			i--;
		}
		msn++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || ft_atoi(av[1]) <= 0 || ft_str_isdigit(av[2]))
	{
		ft_printf("Uso: %s <PID del servidor> <mensaje>\n", av[0]);
		return (1);
	}
	handler(ft_atoi(av[1]), av[2]);
	return (0);
}
