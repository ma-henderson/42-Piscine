/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/05 20:27:53 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*output;
	int		i;

	if (min >= max)
		return (0);
	i = 0;
	output = (int *)malloc(sizeof(int) * min - max);
	while (max - min)
	{
		output[i] = min;
		i++;
		min++;
	}
	return (output);
}

int main(int argc, char **argv)
{
	int *result;

	if (argc == 3)
	{
		result = ft_range(atoi(argv[1]), atoi(argv[2]));
		while (*result)
		{
			printf("%d ", *result);
			result++;
		}
	}
	return (0);
}
