/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:53:09 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/06 12:42:06 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
