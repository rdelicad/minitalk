/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:53 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/07 22:42:20 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void    handler(int pid, const char *msn)
{
    int     i;
    int     codigo;
    char    caracter;
    

    i = 0;
    while (msn[i] != '\0')
    {
        caracter = msn[i];
        codigo = (int)caracter;
        kill(pid, SIGUSR2 + codigo);
        usleep(100);
    }
}

int main(int ac, char **av)
{
    int         pid;
    const char  *msn;

    pid = ft_atoi(av[1]);
    msn = av[2];    
    if (ac != 3)
    {
        ft_printf("Uso: %s <PID del servidor> <mensaje>\n", av[0]);
        return (1);
    }
    handler(pid, msn);
    return 0;
}
