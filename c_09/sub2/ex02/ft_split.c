/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 09:35:56 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/14 22:38:34 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i] || c == '\0')
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int		ft_wc(char *str, char *sep)
{
	int i;
	int wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep) && is_sep(str[i + 1], sep))
			wc++;
		i++;
	}
	return (wc);
}

void	ft_populate(char ***ptr_res, char *str, char *sep)
{
	int i;
	int j;
	int wc;
	int start;

	i = 0;
	start = 0;
	wc = 0;
	while (str[i])
	{
		if (i == 0 || (!is_sep(str[i], sep) && is_sep(str[i - 1], sep)))
			start = i;
		if (!is_sep(str[i], sep) && is_sep(str[i + 1], sep))
		{
			ptr_res[0][wc] = malloc(sizeof(char) * (i - start + 2));
			j = -1;
			while (++j < i - start + 1)
				ptr_res[0][wc][j] = str[start + j];
			ptr_res[0][wc][j] = '\0';
			wc++;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	***ptr_res;
	int		wc;

	ptr_res = &result;
	wc = ft_wc(str, charset);
	result = malloc(sizeof(char*) * (wc + 1));
	ft_populate(ptr_res, str, charset);
	result[wc] = 0;
	return (result);
}
