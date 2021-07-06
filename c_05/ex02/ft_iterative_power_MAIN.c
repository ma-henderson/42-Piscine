/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 21:49:27 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int base;

	base = nb;
	if (nb == power && nb == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		base *= nb;
		power--;
	}
	return (base);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", ft_iterative_power(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
