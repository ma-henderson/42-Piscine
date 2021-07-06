/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:48:18 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/30 15:31:14 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_writer(int x, int y)
{
	int c;

	c = x / 10 + '0';
	write(1, &c, 1);
	c = x % 10 + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = y / 10 + '0';
	write(1, &c, 1);
	c = y % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 100)
	{
		while (y < 100)
		{
			if (x != y)
			{
				ft_writer(x, y);
				if (x != 98 || y != 99)
				{
					write(1, ",", 1);
					write(1, " ", 1);
				}
			}
			y++;
		}
		x++;
		y = x + 1;
	}
}


int main ()
{
	ft_print_comb2();
	return(0);

}
