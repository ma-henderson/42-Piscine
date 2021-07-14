/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:06:59 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/14 11:32:32 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int 		i;
	t_stock_str *result;
	int 		str_size;

	i = 0;
	result = malloc(sizeof(t_stock_str) * (ac + 1));
		if (!result)
			return (0);
	while (i < ac)
	{
		str_size = 0;
		while (av[i][str_size])
			str_size++;
		result[i].size = str_size;
		result[i].str = av[i];
		result[i].copy = malloc(sizeof(char) * str_size + 1);
			if (!result[i].copy)
				return (0);
		result[i].copy = ft_strcpy(result[i].copy, result[i].str);	
		i++;
	}
	result[i].str = 0;
	return (result);
}

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

int main (int argc, char **argv)
{
	t_stock_str *res;
	int i;

	i = 0;
	res = ft_strs_to_tab(argc, argv);
	while (i < argc)
	{
		ft_putstr(res[i].str);
		ft_putnbr(res[i].size);
		write(1, "\n", 1);
		ft_putstr(res[i].copy);
		i++;
	}
		
	
	return (0);
}
