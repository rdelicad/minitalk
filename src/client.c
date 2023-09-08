/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:53 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/08 18:10:26 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	g_end_msn = 0;

static void	sigusr_handler(int g_end_msn)
{
	if (g_end_msn == 1)
		exit (0);
}

static void	send_bits(int pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i > 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(42);
		i--;
	}
	if (i == 0)
		sigusr_handler(1);
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
}

int	main(int ac, char **av)
{
	int			pid;
	const char	*msn;

	pid = ft_atoi(av[1]);
	msn = av[2];
	if (ac != 3)
	{
		ft_printf("Uso: %s <PID del servidor> <mensaje>\n", av[0]);
		return (1);
	}
	handler(pid, msn);
	return (0);
}
