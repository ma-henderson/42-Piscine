#include <stdio.h>

/* for read / write */
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h> // Also for close

/* for open */
#include <fcntl.h>

int main ()
{
	char	buf[12]; // Will need to properly alloc (and free)
	int		fd;
	int		read_ret;
	int		i = 0;
	int		nl = 1;
	int		last_line = 0;

	fd = open("./numbers.dict", O_RDONLY);

	if (fd == -1)
		printf("Error opening file");

	/* stops when it reaches the end */
	while ((read_ret = read(fd, buf, 2)))
	{
		write(1, buf, 1);
	}
	printf("The file is %d bytes long\n", i);

	close(fd);
}
