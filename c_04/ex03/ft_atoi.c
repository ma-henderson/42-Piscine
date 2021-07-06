/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:19:08 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 17:25:57 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int sign;
	int n_flag;
	int output;

	output = 0;
	n_flag = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-' && n_flag == 0)
			sign *= -1;
		if (*str <= '9' && *str >= '0')
		{
			n_flag = 1;
			output *= 10;
			output += *str - 48;
		}
		else if (n_flag == 1)
			return (sign * output);
		str++;
	}
	return (sign * output);
}
