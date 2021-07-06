/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_MAIN.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:45:08 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/06 11:52:42 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return(0);
}

int main()
{
	char *s1 = "this is a test";
	char *s2 = "this is the second test";
	unsigned int n = 8;

	printf("%d", ft_strncmp(s1, s2, n));
	printf("%d", ft_strncmp(s1, s2, n + 1));
	return (0);
}
