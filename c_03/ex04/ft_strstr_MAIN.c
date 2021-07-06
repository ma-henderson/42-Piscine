/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:28:16 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/30 17:15:37 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	
	if (to_find[0] == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}


int main()
{
	char str[] = "abcdefABCaDEF AABCDEFABCDEF";
	char to_find[] = "ABCDEF";

	printf("%s", ft_strstr(str, to_find));
	
	return (0);
}
