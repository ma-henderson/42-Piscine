#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*get_word(char *nbr, char ***arr)
{
	int i;

	i = -1;
	while (++i < 41)
		if (!compare(nbr, arr[i][0]))
			return (arr[i][1]);
	return (NULL);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, " ", 1);
}

void	pronounce_1(char a, char ***arr)
{
	char *ptr;

	ptr = arr[a - '0'][1];
	ft_putstr(ptr);
}

void	pronounce_2(char a, char b, char ***arr)
{
	char ptr[3];

	ptr[0] = a;
	ptr[1] = b;
	ptr[2] = '\0';
	ft_putstr(get_word(ptr, arr));
}

void	print_3_digits(char *nbr, int index, int order, char ***arr)
{
	int counter;

	counter = 0;
	if (nbr[index] != '0')
	{
		pronounce_1(nbr[index], arr);
		write(1, "hundred ", 8);
		counter++;
	}
	if (nbr[index + 1] == '1')
	{
		pronounce_2(nbr[index + 1], nbr[index + 2], arr);
		counter++;
	}
	else if (nbr[index + 2] != '0')
	{
		if (nbr[index + 1] != '0')
			pronounce_2(nbr[index + 1], '0', arr);
		pronounce_1(nbr[index + 2], arr);
		counter++;
	}
	if (order && counter)
		ft_putstr(arr[order + 28][1]);
}

int		str_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*fill_zero(char *str)
{
	int		zeros;
	int		len;
	int		i;
	char	*output;

	len = str_len(str);
	zeros = 3 - (len % 3);
	if (!zeros)
		return (str);
	output = (char*)malloc(zeros + len + 1);
	i = 0;
	while (zeros - i)
		output[i++] = '0';
	while (len + zeros - i)
	{
		output[i] = str[i - zeros];
		i++;
	}
	output[i] = 0;
	return (output);
}

int		ft_find_defs(char **nbr, char ***arr)
{
	int		size;
	int		i;
	
	*nbr = fill_zero(*nbr);
	size = str_len(*nbr);
	i = 0;
	while (i * 3 < size)
	{
		print_3_digits(*nbr, i * 3, size / 3 - i - 1, arr);
		i++;
	}
	return (0);
}
