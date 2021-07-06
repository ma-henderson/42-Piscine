/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_MAIN.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:50:01 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 12:34:57 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int str_len;

	str_len = 0;

	if (size > 0)
	{
		while (*(src + str_len))
		{
			if (str_len == size)
			{
				str_len--;
				break ;
			}
			*(dest + str_len) = *(src + str_len);
			str_len++;
		}
	}
	*(dest + str_len) = '\0';
	while (*(src + str_len))
		str_len++;	
	return (str_len);
}

int main()
{

	char src[] =  "1234567";
	char dest[12];
	unsigned int a = 5;

	printf("str len: %u - size: %u - printed: %s - src: %s",
			ft_strlcpy(dest, src, a),
			a,
			dest,
			src
			);
		

	return(0);
}
