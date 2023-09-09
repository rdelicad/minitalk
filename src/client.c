/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:53 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/09 17:19:50 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	g_stop = 0;

static void	send_bits(int pid, unsigned char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_stop = 1;
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(2, "SIGURSR1 bad pid\n");
		}
		else if (bit == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(2, "SIGUSR2 bad pid\n");
		}
		while (g_stop == 0)
			usleep(1000);
		i--;
	}
}

static void	handler(int pid, const char *msn)
{
	int	i;

	i = 0;
	while (msn[i] != '\0')
	{
		send_bits(pid, msn[i]);
		i++;
	}
	//send_bits(pid, '\0');
}

void	success(int sig)
{
	(void)sig;
	g_stop = 1;
	ft_printf("Los datos has sido recibidos.\n");
}

int	main(int ac, char **av)
{
	int			pid;
	const char	*msn;

	if (ac != 3 || !ft_str_isdigit(av[1]))
	{
		ft_printf("Uso: %s <PID del servidor> <mensaje>\n", av[0]);
		return (1);
	}
	msn = av[2];
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		ft_error(2, "bad pid\n");
	signal(SIGUSR1, success);
	signal(SIGUSR2, success);
	handler(pid, msn);
	return (0);
}
