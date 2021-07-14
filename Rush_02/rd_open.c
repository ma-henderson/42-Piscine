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
	char	buf[1];
	char	**dict;	// Will need to properly alloc (and free)
	int		fd;
	int		read_ret;
	int		i = 0;
	int		nl = 0;
	int		last_line = 0;

	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	/* stops when it reaches the end */
	while ((read_ret = read(fd, buf, 1)))
		i++;
	/* close file for next read sequence */
	close(fd);
	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
		printf("Error opening file");
	/* malloc by number of lines */
	dict = malloc(sizeof(char*) * i);

	i = 0;
	last_line = 0;
	nl = 0;
	while ((read_ret = read(fd, buf, 1)))
	{
		i++;
		if (buf[0] == '\n')
		{
			dict[nl][i - last_line] = *buf;
			nl++;
			printf("Wrote line %d into dict - %d bytes long\n", nl, i - last_line);
			last_line = i;
		}
	}
	/* test if it stored it correctly */	

	printf("The file is %d bytes long\n", i);

	close(fd);
}
