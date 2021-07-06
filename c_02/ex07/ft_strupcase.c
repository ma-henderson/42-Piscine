/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/29 09:14:16 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int flag;
	int i;

	i = 0;
	flag = 1;
	while (*(str + i) != 0)
	{
		if (*(str + i) >= 97 && *(str + i) <= 122)
			*(str + i) -= 32;
		i++;
	}
	return (str);
}
