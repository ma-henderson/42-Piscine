#include <stdio.h>

/* for read / write */
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h> // Also for close

/* for open */
#include <fcntl.h>

/* for malloc */
#include <stdlib.h>

int	ft_outer_alloc(char ***dict)
{
	int fd;
	int i;
	int read_count;
	char buf[1];
	
	// 1st Loop - **dict malloc
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
	int fd;
	int i;
	int cc;
	char buf[1];
	int read_count;

	// 2nd loop - *dict 's malloc
	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return(0);
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

int ft_store_dict(char ***dict)
{
	int fd;
	int i;
	int cc;
	int read_count;
	char buf[1];

	// 3rd loop - store each char appropriately
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


int main ()
{
	int read_count;
	int last_line;
	char **dict;
	char ***p_dict;

	p_dict = &dict;
	last_line = ft_outer_alloc(p_dict);
	if (last_line == -1)
		return (0);

	if (!(ft_inner_alloc(p_dict)))
		return (0);

	if (!(ft_store_dict(p_dict)))
		return (0);
	// Assuming receive trimmed string like "42" or "10" "100032";
	char *str = "10";

	int i;
	int cc;
	i = 0;
	cc = 0;
	while (i < 41)
	{
		while (dict[i][cc])
		{
			write(1, &dict[i][cc], 1);
			cc++;
		}
		cc = 0;
		write(1, "\n", 1);
		i++;
	}	




}
