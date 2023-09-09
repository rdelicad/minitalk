/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:03:02 by rdelicad          #+#    #+#             */
/*   Updated: 2023/09/09 20:09:33 by rdelicad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (octet & (1 << i))
			write (1, "1", 1);
		else
			write (1, "0", 1);
	}
}
