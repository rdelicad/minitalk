/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:51 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/11 19:52:50 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/minitalk.h"

void	handler_sigusr(int signum)
{
	static char	c = 0;
	static int	bits = 0;

	if (signum == SIGUSR1)
	{
		c = (c << 1) | 1;
	}
	else if (signum == SIGUSR2)
	{
		c = (c << 1) | 0;
	}
	bits++;
	if (bits == 8)
	{	
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
	return (0);
}
