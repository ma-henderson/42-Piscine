#include <unistd.h>
#include <stdio.h>

int main()
{
	int i;
	char c = 0;

	i = 0;
	while (i < 128)
	{
		c = 0 + i;
		printf("%d: %c\n", i, c);
//		write(1, &c, 1);
//		write(1, "\n", 1);
		i++;
	}
	return(0);
}
