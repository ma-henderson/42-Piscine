/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase_MAIN.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/29 11:46:51 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (*(str + i) != 0)
	{
		if (*(str + i) >= 65 && *(str + i) <= 90)
			*(str + i) += 32;
		i++;
	}
	return (str);
}


int main()
{
	char str[] = "ABCf_asD !1123 dfa\nsdf";

	printf("%s", ft_strlowcase(str));
	return (0);
}
