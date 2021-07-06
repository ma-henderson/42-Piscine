/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 21:57:50 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_fibonacci(int index)
{
	int sum;

	sum = 0;
	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		sum += ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (sum);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d", ft_fibonacci(atoi(argv[1])));
	return (0);
}
