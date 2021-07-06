/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab_MAIN.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:00:31 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 21:22:46 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i)
		{
			if (*(tab + j) > *(tab + j + 1))
			{
				temp = *(tab + j + 1);
				*(tab + j + 1) = *(tab + j);
				*(tab + j) = temp;
			}
		j++;
		}
	i++;
	j = 0;
	for (int k = 0; k < size; k++) printf("%d, ", tab[k]);
	printf("\n");
	}
}


int main()
{
	int tab[] = {5, 0, 3, 2, 1};
	int size = 5;

	ft_sort_int_tab(tab, size);
	for (int k = 0; k < size; k++) printf("%d,", tab[k]);
	return(0);
}
