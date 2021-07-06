/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable_MAIN.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:01:08 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 12:44:49 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_str_is_printable(char *str, int i)
{
	if (*(str + i) < 32)
		return (0);
	return (1);
}

void	char_to_hexa(char c)
{
	char base[16];
	int i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			base[i] = '0' + i;
		else
			base[i] = 'a' + i - 10;
		i++;
	}
	ft_putchar('\\');
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (ft_str_is_printable(str, i) == 1)
			ft_putchar(*(str + i));
		else
			char_to_hexa(*(str + i));
		i++;
	}
}

int main()
{
	char str[] = "Coucou\ntu vas \tbien ?";

	ft_putstr_non_printable(str);
	return(0);
}

