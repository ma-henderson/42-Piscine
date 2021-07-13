/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_MAIN.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:27:29 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/13 15:07:14 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>

int ft_is_sep(char c, char *seps)
{
	int i;

	i = 0;
	while (seps[i])
	{
		if (seps[i] == c || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int ft_wc(char *str, char *sep)
{
	int wc;
	int i;

	wc = 0;
	i = 0;
	while (str[i])
	{
		if ((!ft_is_sep(str[i], sep) && ft_is_sep(str[i + 1], sep)))
		{
			printf("start of word at i: %d  and  char: %c\n", i, str[i]);
			wc++;
		}
		i++;
	}
	return (wc);
}

void	ft_word_place(char ***ptr_res, char *str, char *sep)
{
	int wc;
	int i;
	int j;
	int start;

	wc = 0;
	start = 0;
	i = 1;
	while (str[i])
	{
		if (!ft_is_sep(str[i], sep) && ft_is_sep(str[i - 1], sep))
			start = i;
		if (!ft_is_sep(str[i], sep) && ft_is_sep(str[i + 1], sep))
		{
			ptr_res[0][wc] = (char*)malloc(sizeof(char) * (i - start + 2));
			ptr_res[0][wc][i - start + 1] = '\0';
			j = -1;
			while (++j < i - start + 1)
				ptr_res[0][wc][j] = str[start + j];
			wc++;
		}
		i++;
	}
}

char **ft_split(char *str, char *charset)
{
	char **result;
	char ***ptr_res;
	int wc;
	
	ptr_res = &result;
	wc = ft_wc(str, charset);
	result = (char **)malloc(sizeof(char*) * (wc + 1));	
	ft_word_place(ptr_res, str, charset);
	result[wc] = (char*)malloc(sizeof(char) * 1); 
	result[wc] = 0;

	int i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	
	return 0;
}


int main()
{
	//char *str = "abcdefgacdegafhiwza";
	char *str = "D27wMIEUmUD7MaVFWA8FdrIwIyhdKACs4lgCA4E5nOalUsnL";
	char *seps = "!";
	
	ft_split(str, seps);
	return 0;
}
