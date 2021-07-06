/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable_MAIN.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/29 19:52:08 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (*(str + i) != 0)
	{
			if (*(str + i) < 32 || *(str + i) > 126)
				flag = 0;
			else
				write(1, str + i, 1);
			i++;

			
	}
	return (flag);
}


int main()
{
	char str[] = "LKSDJFKdëádf\nLSDJF";

	printf("%d", ft_str_is_printable(str));
	return (0);
}
