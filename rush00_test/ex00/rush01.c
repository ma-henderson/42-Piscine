/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:49:04 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/26 23:04:52 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_top(int x)
{
	int col;

	col = 1;
	if (x >= 1)
		ft_putchar('/');
	while (col <= x - 2)
	{
		ft_putchar('*');
		col++;
	}
	if (x >= 2)
		ft_putchar('\\');
}

void	ft_bottom(int x)
{
	int col;

	col = 1;
	if (x >= 1)
		ft_putchar('\\');
	while (col <= x - 2)
	{
		ft_putchar('*');
		col++;
	}
	if (x >= 2)
		ft_putchar('/');
}

void	ft_mid(int x)
{
	int col;

	col = 1;
	if (x >= 1)
		ft_putchar('*');
	while (col <= x - 2)
	{
		ft_putchar(' ');
		col++;
	}
	if (x >= 2)
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int line;

	line = 1;
	while (line <= y && x > 0)
	{
		if (line == 1)
			ft_top(x);
		else if (line == y)
			ft_bottom(x);
		else
			ft_mid(x);
		ft_putchar('\n');
		line++;
	}
}
