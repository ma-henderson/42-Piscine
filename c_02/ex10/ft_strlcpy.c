/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:50:01 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 12:36:15 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
