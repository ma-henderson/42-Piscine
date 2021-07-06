/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:31:43 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/30 21:01:00 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int temp;

	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2", 2);
			nb = 147483648;
		}
		else
		{
			ft_putchar('-');
			nb *= -1;
		}
	}
	if (nb < 10)
		ft_putchar(48 + nb);
	else
	{
		temp = nb / 10;
		ft_putnbr(temp);
		ft_putchar(48 + (nb % 10));
	}
}
