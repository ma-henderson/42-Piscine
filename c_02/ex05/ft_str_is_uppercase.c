/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:30:17 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 11:58:22 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != 0)
	{
		if (*(str + i) < 65 || *(str + i) > 90)
			return (0);
		i++;
	}
	return (1);
}
