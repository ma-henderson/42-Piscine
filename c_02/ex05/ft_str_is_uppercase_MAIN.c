/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase_MAIN.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 11:57:51 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) < 65 || *(str + i) > 90)
			return (0);
		i++;
	}
	return (1);
}


int main()
{
	char str[] = "ABCDEF";

	printf("%d", ft_str_is_uppercase(str));
	return (0);
}
