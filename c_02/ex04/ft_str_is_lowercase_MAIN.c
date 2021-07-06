/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/28 19:29:19 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (*(str + i) != 0)
	{
		if (*(str + i) < 97 || *(str + i) > 122)
			flag = 0;
		i++;
	}
	return (flag);
}


int main()
{
	char str[] = "dasdfasDdfasdf";

	printf("%d", ft_str_is_lowercase(str));
	return (0);
}
