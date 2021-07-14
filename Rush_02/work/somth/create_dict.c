/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:32:19 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/10 23:51:47 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

int	ft_outer_alloc(char ****dict)
{
	int		fd;
	int		i;
	int		j;
	int		read_count;
	char	buf[1];

	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while ((read_count = read(fd, buf, 1)))
		if (buf[0] == '\n')
			i++;
	dict[0] = (char ***)malloc(sizeof(char **) * i);
	j = 0;
	while (j < i)
		dict[0][j++] = (char **)malloc(sizeof(char *) * 2);
	close(fd);
	return (i / 2);
}

int	ft_inner_alloc(char ****dict)
{
	int		fd;
	int		i;
	int		cc;
	char	buf[1];
	int		read_count;

	if ((fd = open("./numbers.dict", O_RDONLY)) == -1)
		return (0);
	i = 0;
	cc = 0;
	while ((read_count = read(fd, buf, 1)))
	{
		cc++;
		if (buf[0] == '\n' || buf[0] == ':')
		{
			dict[0][i / 2][i % 2] = (char *)malloc(sizeof(char) * (cc));
			i++;
			cc = 0;
		}
	}
	close(fd);
	return (1);
}

int	ft_store_dict(char ****dict)
{
	int		fd;
	int		i;
	int		cc;
	int		read_count;
	char	buf[1];

	if (!(fd = open("./numbers.dict", O_RDONLY)))
		return (0);
	i = 0;
	cc = 0;
	while ((read_count = read(fd, buf, 1)))
	{
		if (buf[0] == '\n' || buf[0] == ':' || buf[0] == EOF)
		{
			dict[0][i / 2][i % 2][cc++] = '\0';
			cc = 0;
			i++;
		}
		else
		{
			dict[0][i / 2][i % 2][cc++] = buf[0];
		}
	}
	close(fd);
	return (1);
}

int	create_dict(char ****p_dict)
{
	int last_line;

	last_line = ft_outer_alloc(p_dict);
	if (last_line == -1)
		return (0);
	if (!(ft_inner_alloc(p_dict)))
		return (0);
	if (!(ft_store_dict(p_dict)))
		return (0);
	return (last_line);
}
