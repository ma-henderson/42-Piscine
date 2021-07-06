/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_MAIN.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 20:56:02 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 11:44:51 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* assuming *dest already has 'sized' the addresses */
char	*ft_strcpy(char *dest, char *src)
{
	int size;
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

int main()
{
	char t[] = "abcd";
	char dest[] = "12345";
	char *out;	

	out = ft_strcpy(dest, t);
	printf("%s", out);

	return(0);
}
