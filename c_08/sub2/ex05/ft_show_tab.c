/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:06:59 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/14 11:33:11 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
	return (0);
}
