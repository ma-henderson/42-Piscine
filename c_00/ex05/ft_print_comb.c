/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:47:28 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/30 08:47:51 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char x[3];

	x[0] = '0' - 1;
	while (++x[0] <= '9')
	{
		x[1] = x[0];
		while (++x[1] <= '9')
		{
			x[2] = x[1];
			while (++x[2] <= '9')
			{
				write(1, &x[0], 1);
				write(1, &x[1], 1);
				write(1, &x[2], 1);
				if (x[0] != '7' || x[1] != '8' || x[2] != '9')
				{
					write(1, ",", 1);
					write(1, " ", 1);
				}
			}
		}
	}
}
