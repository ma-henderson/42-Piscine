/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:06:59 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/14 11:35:03 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;
	int			str_size;

	i = 0;
	result = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (0);
	while (i < ac)
	{
		str_size = 0;
		while (av[i][str_size])
			str_size++;
		result[i].size = str_size;
		result[i].str = av[i];
		result[i].copy = malloc(sizeof(char) * str_size + 1);
		if (!result[i].copy)
			return (0);
		ft_strcpy(result[i].copy, result[i].str);
		i++;
	}
	result[i].str = 0;
	return (result);
}
