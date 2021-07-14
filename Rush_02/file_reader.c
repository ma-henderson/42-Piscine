#include <stdio.h>

/* for read / write */
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h> // Also for close

/* for open */
#include <fcntl.h>



/* Searches document, returns exact # of bytes to jump to reach desired dest*/
// Step 1) find str_len (we need to parse in this quantity) AFTER cleaning of isspace
// Step 2) seek through dictionary for a match of first char, then verify
// Step 3) Verification?
int	ft_seek(char *str, int fd)
{
	int ret;
	int i;
	int j;
	char buf[2];

	j = 0;
	i = 0;
	while ((ret = read(fd, buf, 1)))
	{
		if (str[j] == *buf)
			j++;
		else
			j = 0;
		if (str[j] = '\0')
			return (i - j);
			j++;
		i++;
	}
	return (i);
}


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
	while ((read_ret = read(fd, buf, 1)))
	{
		i++;
		if (buf[0] == '\n')
		{
			nl++;
			printf("Line #%d is %d bytes long\n", nl, i - last_line);
			last_line = i;
		}
	}
	printf("The file is %d bytes long\n", i);

	close(fd);
}
