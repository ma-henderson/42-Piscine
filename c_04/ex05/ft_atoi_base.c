/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:04:14 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 18:42:26 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (*(str + i) < '0')
			return (0);
		else if (*(str + i) > '9' && *(str + i) < 'A')
			return (0);
		else if (*(str + i) > 'Z' && *(str + i) < 'a')
			return (0);
		else if (*(str + i) > 'z')
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
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

int		check_base(char *base)
{
	int i;
	int j;

	if (ft_str_is_alpha(base) == 0)
		return (0);
	i = 0;
	while (base[i])
	{
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

int		check_neg(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	return (nbr);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;
	char	output[1000];
	int		nbr;

	nbr = ft_atoi(str);
	if (check_base(base) == 0)
		return (0);
	nbr = check_neg(nbr);
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
	return (1);
}
