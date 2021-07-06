/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:16:59 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 12:27:32 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str, int i)
{
	if (*(str + i) >= 'a' && *(str + i) <= 'z')
		*(str + i) -= 32;
	return (str);
}

char	*ft_strlowcase(char *str, int i)
{
	if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		*(str + i) += 32;
	return (str);
}

int		ft_str_is_alpha(char *str, int i)
{
	if (*(str + i) < '0')
		return (0);
	else if (*(str + i) > '9' && *(str + i) < 'A')
		return (0);
	else if (*(str + i) > 'Z' && *(str + i) < 'a')
		return (0);
	else if (*(str + i) > 'z')
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (i == 0)
			ft_strupcase(str + i, i);
		else
		{
			if (ft_str_is_alpha(str, i - 1) == 1)
				ft_strlowcase(str, i);
			else
				ft_strupcase(str, i);
		}
		i++;
	}
	return (str);
}
