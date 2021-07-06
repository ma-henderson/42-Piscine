/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:51:27 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/27 20:41:35 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_put_tab(int *tab, int size)
{
	int i;
	char c;

	i = 0;
	while (i < size)
	{
		c = 48 + *(tab + i);
		write(1, &c, 1);
		i++;
	}
	printf("\n");
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = size;
	while(i > size/2)
	{
		temp = *(tab + i - 1);
		*(tab + i - 1) = *(tab + (size - i));
		*(tab + (size - i)) = temp;

		ft_put_tab(tab, size);

		i--;
	}

}

int main()
{
	int tab[] = {1, 2, 3, 4, 5, 123, 2132, 777};
	int size = 8;

	ft_rev_int_tab(tab, size);
	ft_put_tab(tab, size);
	return (0);
}
