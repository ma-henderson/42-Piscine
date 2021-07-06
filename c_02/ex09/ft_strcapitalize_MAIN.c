/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_MAIN.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 09:16:59 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/04 12:23:59 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	ft_str_is_alpha(char *str, int i)
{
	if (*(str + i) < '0')
		return (0);
	else if (*(str + i) > '9' && *(str + i) < 'A' )
		return (0);
	else if (*(str + i) > 'Z' && *(str + i) < 'a')
		return (0);
	else if (*(str + i) > 'z')
		return (0);
//	printf("loc: %d - letra: %c - flag: %d\n", loc, *(str + loc), flag);
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
			if (ft_str_is_alpha(str, i-1) == 1)
				ft_strlowcase(str, i);
			else
				ft_strupcase(str, i);
		}
		ft_putchar(*(str + i));
		i++;
	}
	return(str);
}

int main()
{
	char str[] = "hey tHere ? 42isn't it_great+weather?salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
//	char str[] = "8k}|G5nz=Kcvhp17$Kfkka(}1@/Enck8z#>~X8qgbrwvk 	[X-Q0gzz^&]>Zi*Kh[Teol*:G~Xly,P$2:Ff:I~Lkh|K9[}Hjvs~,DpV-A9e@0l7%^J*S@@Fhffsi%T7 +Zz>Bq H}5^/Dz&@Oq]Pv@:H:Nczpim9Jjf+Uut_Frf>Kp,[.:K3&{Cz)2)4c#{(Scu#Sln&|P6&C,Ty-5%<}Ze1yr^9[J{>H}<El,D2	&R7*Xf@_Ftotvhp>*2w*}!Uod}D6ig{'>-,Dfgh3n9*Aa Iz@G1Null   Rekt17+Lol Mdr Mdr 4242l428k}|G5nz=Kcvhp17$Kfkka(}1@/Enck$";

	ft_strcapitalize(str);
	return (0);
}
