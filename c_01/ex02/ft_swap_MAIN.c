/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:42:53 by mhenders          #+#    #+#             */
/*   Updated: 2021/06/27 12:09:23 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}


int main()
{
	int a = 10;
	int b = 15;
	int *pa;
	int *pb;

	pa = &a;
	pb = &b;
	ft_swap(pa, pb);
	printf("a: %d\n", a);
	printf("b: %d", b);


	return(0);
}
