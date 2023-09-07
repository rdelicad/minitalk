/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:53 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/07 16:53:31 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int main(int ac, char **av)
{
    pid_t target_pid; /* PID del proceso objetivo */
    int signal_to_send; // Selecciona la señal que deseas enviar.
    
    if (ac == 3)
    {
        target_pid = ft_atoi(av[0]);
        signal_to_send = SIGUSR1; 

        if (kill(target_pid, signal_to_send) == -1) {
            ft_error(2, "Error al enviar la señal");
            return 1;
        }

        printf("Señal %d enviada al proceso con PID %d.\n", signal_to_send, target_pid);
    }
    ft_error(2, "No se entregaron los argumentos suficientes.");
    return 0;
}
