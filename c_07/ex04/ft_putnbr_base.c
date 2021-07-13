/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:34:11 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/11 16:45:50 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	baselen;
	unsigned int	nbr_cp;

	if (check_base(base) == 1)
	{
		baselen = ft_strlen(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr_cp = (unsigned int)(-1 * nbr);
		}
		else
			nbr_cp = (unsigned int)nbr;
		if (baselen <= nbr_cp)
		{
			ft_putnbr_base(nbr_cp / baselen, base);
			ft_putnbr_base(nbr_cp % baselen, base);
		}
		else
			write(1, base + nbr_cp, 1);
	}
}
