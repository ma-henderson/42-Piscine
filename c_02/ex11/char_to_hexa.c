#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	char_to_hexa(char c)
{
	char base[] = "0123456789abcdef";

	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

int main()
{
	char_to_hexa('k'); //6b ou 107
	return(0);
}
