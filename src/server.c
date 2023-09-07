/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:15:01 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/07 16:53:26 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	sigint_handler(int __attribute__((unused)) signo)
{
	printf("Señal SIGINT recibida. Saliendo...\n");
	exit(1);
}

int main()
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Servidor a la espera con PID: %d\n", pid);
	struct sigaction sa;
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("Error al configurar el manejador de señales");
		return 1;
	}
	printf ("Ejecuta Ctrl + C para enviar una señal SIGINT.\n");
	while (1)
	{

	}
	return (0);
}