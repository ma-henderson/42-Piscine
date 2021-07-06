/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/05 21:24:39 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	if (min >= max)
		return (0);
	i = 0;
	range = (int **)malloc(sizeof(int*) * min - max);
	if (range == NULL)
		return (-1);
	while (max - min)
	{
		range[i] = (int *)malloc(sizeof(int));
		range[i][0] = min;
		i++;
		min++;
	}
	return (sizeof(range));
}

int main(int argc, char **argv)
{
	int **result;
	int i = 0;

	if (argc == 3)
	{
		ft_ultimate_range(result, atoi(argv[1]), atoi(argv[2]));
		while (result[i])
		{
			printf("%d ", *result);
			result++;
		}
	}
	return (0);
}
