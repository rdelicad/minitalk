/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:15:01 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/07 22:49:25 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	sigusr1_handler(int codigo_caracter)
{
	char	caracter;

	caracter = (char)codigo_caracter;
	printf("Mensaje recibido del cliente: %c\n", caracter);
	usleep(100);
}

int main()
{
	signal(SIGUSR1, sigusr1_handler);
	ft_printf("Servidor en ejecucion (PID: %d)\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}