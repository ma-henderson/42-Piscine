/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/05 20:28:18 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
