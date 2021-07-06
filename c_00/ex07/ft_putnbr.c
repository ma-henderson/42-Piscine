/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:31:43 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/30 09:02:26 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int temp;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			write(1, "-2", 2);
			nbr = 147483648;
		}
		else
		{
			ft_putchar('-');
			nbr *= -1;
		}
	}
	if (nbr < 10)
		ft_putchar(48 + nbr);
	else
	{
		temp = nbr / 10;
		ft_putnbr(temp);
		ft_putchar(48 + (nbr % 10));
	}
}
