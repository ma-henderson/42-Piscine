/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/05 11:02:04 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	smart_guess(int nb)
{
	int i;
	int temp;

	temp = nb;
	i = 0;
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	i /= 2;
	while (i > 0)
	{
		i--;
		temp /= 10;
	}
	return (temp);
}

int	ft_sqrt(int nb)
{
	int root;
	int old_root;
	
	if (nb < 0)
		return (0);
	old_root = -1;
	root = smart_guess(nb);
	while (old_root != root)
	{
		if (root * root == nb)
			return (root);
		old_root = root;
		root = (root + nb/root) / 2;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d", ft_sqrt(atoi(argv[1])));
	return (0);
}
