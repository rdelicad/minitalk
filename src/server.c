/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:51 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/13 18:59:12 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits = 0;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
	{
		c = (c << 1) | 1;
		//kill(info->si_pid, SIGUSR1);
	}
	else if (signum == SIGUSR2)
	{
		c = (c << 1) | 0;
		//kill(info->si_pid, SIGUSR2);
	}
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		kill(info->si_pid, SIGUSR1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	printf("PID: %d\n", pid);
	action.sa_sigaction = handler_sigusr;
	//sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
