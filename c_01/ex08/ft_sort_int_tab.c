/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:00:31 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 21:11:54 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	}
}
