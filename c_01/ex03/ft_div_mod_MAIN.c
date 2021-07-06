/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:11:10 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/27 12:23:32 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main()
{
	int a;
	int b;
	int div, mod = 0;
	int *p_div;
	int *p_mod;

	p_div = &div;
	p_mod = &mod;
	a = 42;
	b = 10;

	ft_div_mod(a, b, p_div, p_mod);
	printf("%d\n", div);
	printf("%d\n", mod);
	return (0);
}
