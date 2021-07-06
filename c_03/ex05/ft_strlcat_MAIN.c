/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_MAIN.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:53:09 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/06 12:41:38 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int d_end;
	unsigned int src_size;

	src_size = 0;
	while (src[src_size])
		src_size++;
	d_end = 0;
	while (dest[d_end])
		d_end++;
	i = 0;
	while (i < size - d_end - 1)
	{
		dest[d_end + i] = src[i];
		i++;
	}
	if (!(size == 0 || d_end >= size))
		dest[d_end + i] = '\0';
	return (d_end + src_size);
}

int main()
{
	char s1[12] = "12345";
	char s2[] = "12345";
	unsigned int n = 10;
	ft_strlcat(s1, s2, n);
	printf("%s", s1);

	return (0);
}
