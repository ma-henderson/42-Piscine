/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:29:50 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 21:35:49 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
		return (nb * (ft_recursive_factorial(nb - 1)));
}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d", ft_recursive_factorial(atoi(argv[1])));
	return (0);
}
