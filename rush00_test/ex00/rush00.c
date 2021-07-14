/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:34:12 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/28 17:41:47 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_topbot(int col)
{
	int i;

	i = 0;
	if (col >= 1)
		ft_putchar('o');
	while (i < col - 2)
	{
		ft_putchar('-');
		i++;
	}
	if (col >= 2)
		ft_putchar('o');
}

void	ft_mid(int col)
{
	int i;

	i = 0;
	if (col >= 1)
		ft_putchar('|');
	while (i < col - 2)
	{
		ft_putchar(' ');
		i++;
	}
	if (col >= 2)
		ft_putchar('|');
}

void	rush(int x, int y)
{
	int line;

	line = 1;
	while (line <= y && x > 0)
	{
		if (line == 1 || line == y)
			ft_topbot(x);
		else
			ft_mid(x);
		ft_putchar('\n');
		line++;
	}
}
