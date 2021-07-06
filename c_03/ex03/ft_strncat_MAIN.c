/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:59:28 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/06 12:07:51 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0 && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i + 1] = '\0';
	return (dest);
}

int main()
{
	char dest[100] = "this is a ";
	char *src = "test";
	unsigned int n = 5;

	//printf("with n = %u  result: %s\n", n, ft_strncat(dest, src, n));

	n = 3;
	printf("with n = %u  result: %s\n", n, ft_strncat(dest, src, n));
	
	return (0);
}
