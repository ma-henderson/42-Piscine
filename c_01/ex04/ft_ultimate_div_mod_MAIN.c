/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:42:18 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/27 12:52:26 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;
	c = *a;
	*a = *a / *b;
	*b = c % *b;
}


int main()
{
	int a;
	int b;
	int *pa;
	int *pb;

	pa = &a;
	pb = &b;
	a = 42;
	b = 5;

	ft_ultimate_div_mod(pa, pb);
	printf("%d\n", a);
	printf("%d\n", b);
	return(0);
}
