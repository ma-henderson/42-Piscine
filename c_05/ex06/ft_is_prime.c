/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 21:37:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/05 13:22:24 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_sqrt_prime(int nb)
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
		root = (root + nb / root) / 2;
	}
	return (root);
}

int	ft_is_prime(int nb)
{
	int root;
	int div;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (0);
	else if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	root = ft_sqrt_prime(nb) + 1;
	div = 3;
	while (div < root)
	{
		if (nb % div == 0)
			return (0);
		div += 2;
	}
	return (1);
}
