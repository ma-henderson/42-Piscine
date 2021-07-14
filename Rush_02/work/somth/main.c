/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mal-yafe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:20:07 by mal-yafe          #+#    #+#             */
/*   Updated: 2021/07/10 23:49:49 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./ft_atoi.c"
#include "./str_num_clean.c"
#include "./create_dict.c"
#include "./ft_find_defs.c"

int	ft_atoi(char *str);

void str_num_clean(char *str, char upper, char lower, char **ptr);

int create_dict(char ****p_dict);

int	ft_find_defs(char **nbr, char ***dict);

#include <stdio.h>

int main(int argc, char **argv)
{
	char *temp;
	char **pt_temp;
	char ***dict;
	char ****p_dict;

	p_dict = &dict;
	pt_temp = &temp;
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) == 1)
		{
			str_num_clean(argv[1], '9', '0', pt_temp);
			create_dict(p_dict);
			ft_find_defs(pt_temp, dict);
		}
		else
			printf("Dict Error.");
	}

	//else if (argc == 3)
	//{}
	else
		printf("Dict Error.");
	return (0);

}
