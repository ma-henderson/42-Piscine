/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:32:19 by mhenders          #+#    #+#             */
/*   Updated: 2021/07/10 19:33:27 by mhenders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_outer_alloc(char ***dict)
{
	int		fd;
	int		i;
	int		read_count;
	char	buf[1];

	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while ((read_count = read(fd, buf, 1)))
		if (buf[0] == '\n')
			i++;
	*dict = (char **)malloc(sizeof(char *) * i);
	close(fd);
	return (i);
}

int	ft_inner_alloc(char ***dict)
{
	int		fd;
	int		i;
	int		cc;
	char	buf[1];
	int		read_count;

	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	cc = 0;
	while ((read_count = read(fd, buf, 1)))
	{
		cc++;
		if (buf[0] == '\n')
		{
			dict[0][i] = (char *)malloc(sizeof(char) * (cc));
			i++;
			cc = 0;
		}
	}
	close(fd);
	return (1);
}

int	ft_store_dict(char ***dict)
{
	int		fd;
	int		i;
	int		cc;
	int		read_count;
	char	buf[1];

	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	cc = 0;
	while ((read_count = read(fd, buf, 1)))
	{
		if (buf[0] == '\n' || buf[0] == EOF)
		{
			dict[0][i++][cc++] = '\0';
			cc = 0;
		}
		else
		{
			dict[0][i][cc++] = buf[0];
		}
	}
	close(fd);
	return (1);
}

int	create_dict(char ***p_dict)
{
	int read_count;
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
