/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_num_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:59:47 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/10 19:59:55 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	str_num_clean(char *str, char upper, char lower, char **ptr)
{
	int i;
	int num_start;
	int str_len;

	i = 0;
	num_start = 0;
	str_len = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	num_start = i;
	while (str[i] >= lower && str[i] <= upper)
	{
		str_len++;
		i++;
	}
	// FIX FOR LEFT ONLY TRIMMING but ONLY spaces (32)
	*ptr = (char *)malloc(sizeof(char) * (str_len + 1));
	i = 0;
	while (i < str_len)
		ptr[0][i++] = str[num_start++];
	ptr[0][i] = '\0';
}
