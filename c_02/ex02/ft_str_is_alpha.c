/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/28 19:19:36 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (*(str + i) != 0)
	{
		if (*(str + i) >= 91 && *(str + i) <= 96)
			flag = 0;
		if (*(str + i) >= 123)
			flag = 0;
		if (*(str + i) <= 64)
			flag = 0;
		i++;
	}
	return (flag);
}
