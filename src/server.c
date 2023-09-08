/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:15:01 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/08 18:10:05 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	sig_handler(int sig)
{
	static char	c;
	static int	bit_cont;

	if (sig == SIGUSR1)
		c = c | (1 << (7 - bit_cont));
	bit_cont++;
	if (bit_cont == 8)
	{
		printf("Mensaje recibido del cliente: %c\n", c);
		c = 0;
		bit_cont = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_printf("Servidor en ejecucion (PID: %d)\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
