/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-yafe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:49:47 by mal-yafe          #+#    #+#             */
/*   Updated: 2021/07/10 19:58:49 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
		else if (str[i] == '+' && flag == 0)
			flag = 1;
		else
			return (0);
		i++;
	}
	if (str[i] >= 48 && str[i] <= 57)
		while (48 <= str[i] && str[i] <= 57)
			i++;
	else
		return (0);
	return (1);
}
