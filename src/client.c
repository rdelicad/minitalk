/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:07 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/14 17:25:54 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_stop = 1;

void	recibed_sig(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("señal recibida.\n");
		g_stop = 0;
	}
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
			g_stop = 1;
			if (*msn & (1 << i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(35);
			i--;
		}
		while (g_stop)
			usleep(1);
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
	return (0);
}
