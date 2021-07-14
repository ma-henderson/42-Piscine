#include <stdio.h>


int	ft_isspace(

int	ft_find_defs(char ***dict)
{
	// Assuming receive trimmed string like "42" or "10" "100032";
	char str[] = "10"; // look for 
	int str_len;
	int j;

	str_len = 0;
	while (str[str_len])
		str_len++;
	while (last_line > 0)
	{
		j = 0;
		while (dict[last_line - 1][j] == str[j])
		{
			if (str[++j] == '\0' && dict[last_line - 1][j] == ':')
				printf("MATCH of %s\n", dict[last_line-1]);
		}
		last_line--;
	}



}
