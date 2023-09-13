/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:07 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/13 19:01:20 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	recibed_sig(int signum)
{
	if (signum == SIGUSR1)
		printf("señal recibida.\n");
}

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
			usleep(200); //35 en Mac y 175 wsl
			i--;
		}
		msn++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Uso: %s <PID del servidor> <mensaje>\n", av[0]);
		return (1);
	}
	signal(SIGUSR1, recibed_sig);
	handler(atoi(av[1]), av[2]);
	// signal(SIGUSR2, recibed_sig);
	return (0);
}
