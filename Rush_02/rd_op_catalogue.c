#include <stdio.h>

/* for read / write */
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h> // Also for close

/* for open */
#include <fcntl.h>

/* for malloc */
#include <stdlib.h>

int main ()
{
	int fd;
	char **dict;
	int read_count;
	int i;
	int cc;
	char buf[1];

	// 1st Loop - **dict malloc
	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while ((read_count = read(fd, buf, 1)))
		if (buf[0] == '\n')
			i++;
	dict = (char **)malloc(sizeof(char *) * i);
	close(fd);

	// 2nd loop - *dict 's malloc
	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	cc = 0;
	while ((read_count = read(fd, buf, 1)))
	{
		cc++;
		if (buf[0] == '\n') // || buf[0] == EOF
		{
			dict[i] = (char *)malloc(sizeof(char) * (cc));
			i++;
			cc = 0;
		}
	}
	close(fd);

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
			dict[i++][cc++] = '\0';
			cc = 0;
		}
		else
		{
			dict[i][cc++] = buf[0];
		}
	}
	close(fd);
	


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
