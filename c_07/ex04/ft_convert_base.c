/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/13 11:37:50 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

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

void	ft_putnbr_base(int nbr, char *base, char **p_res)
{
	unsigned int	baselen;
	unsigned int	nbr_cp;

	if (check_base(base) == 1)
	{
		baselen = ft_strlen(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
//			*p_res = (char *)malloc(sizeof(char) * (baselen + 2));
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *result;
	char **p_res;
	int decimal;
	
	p_res = &result;
	decimal = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(decimal, base_to, p_res);
	

}
