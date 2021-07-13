/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:18:56 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/13 13:01:17 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*check_size(int size, char **strs)
{
	char	*temp;

	if (size == 0)
	{
		temp = malloc(sizeof(char*));
		temp[0] = '\0';
		return (temp);
	}
	else
		temp = (char *)malloc(sizeof(strs));
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sum;
	int		i;
	int		j;
	int		k;
	char	*temp;

	temp = check_size(size, strs);
	if (!temp)
		return (temp);
	sum = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		k = 0;
		while (strs[i][j])
			temp[sum++] = strs[i][j++];
		if (i++ != size - 1)
			while (sep[k])
				temp[sum++] = sep[k++];
	}
	if (size != 0)
		temp[sum] = '\0';
	return (temp);
}
