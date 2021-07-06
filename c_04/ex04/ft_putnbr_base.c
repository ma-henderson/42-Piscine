/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:34:11 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 18:17:19 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_alpha(char *str, int i)
{
	if (*(str + i) < '0')
		return (0);
	else if (*(str + i) > '9' && *(str + i) < 'A')
		return (0);
	else if (*(str + i) > 'Z' && *(str + i) < 'a')
		return (0);
	else if (*(str + i) > 'z')
		return (0);
	return (1);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (ft_str_is_alpha(base, i) == 0)
			return (0);
		j = 0;
		while (base[j + i + 1])
		{
			if (base[i] == base[i + j + 1])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		j;
	char	output[1000];

	if (check_base(base) == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		i = 0;
		while (base[i])
			i++;
		j = 0;
		while (nbr != 0)
		{
			output[j] = base[nbr % i];
			j++;
			nbr /= i;
		}
		while (j-- >= 0)
			write(1, output + j, 1);
	}
}
