#include <unistd.h>

void	ft_putaddr(char c)
{
	write(1, *&c, 1);
}

int main()
{
	int i;

	i = 0;
	char[16] = "This is a string.";
	

	
	return (0);
}
