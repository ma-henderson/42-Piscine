/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_MAIN.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:15:58 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/27 20:44:58 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}


int main()
{
	int l = 0;

	char the_str[] = "This is a long string, count me!";

	l = ft_strlen(the_str);

	printf("%d", l);
	return(0);	
}
