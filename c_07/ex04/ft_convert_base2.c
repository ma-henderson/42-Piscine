/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 13:15:05 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/13 11:19:53 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '-' || base[i] == '+')
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

int	ft_index(char *str, char to_find)
{
	int i;

	if (to_find == '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int i)
{
	int sign;
	int output;

	sign = 1;
	output = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_index(base, str[i]) != 0 && str[i] != '\0')
		return (i * sign);
	return (0);
}

int	ft_power(int nb, int power, int step)
{
	if (step == 0)
	{
		if (power < 0)
			return (0);
		else if (power == 0)
			return (1);
		else if (power == 1)
			return (nb);
		nb *= ft_power(nb, power - 1, 0);
	}
	else if (step == 1)
	{
		if (nb < 0)
			return (-1);
		else
			return (1);
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int		res;
	int		base_len;
	int		i;
	int		loc;

	if (check_base(base) == 0)
		return (0);
	base_len = 0;
	res = 0;
	while (base[base_len])
		base_len++;
	loc = ft_atoi(str, base, 0);
	if (loc < 0)
		loc *= -1;
	while (str[loc] && ft_index(base, str[loc]) >= 0)
	{
		i = 0;
		while (ft_index(base, str[loc + i]) >= 0)
			i++;
		if (ft_index(base, str[loc]))
			res += ft_index(base, str[loc]) * ft_power(base_len, i - 1, 0);
		loc++;
	}
	return (res * ft_power(ft_atoi(str, base, 0), 0, 1));
}
