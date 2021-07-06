#include <unistd.h>
#include <stdio.h>



int main()
{
	int i = 42;
	int *ptr;
	int **ptr2;

	ptr = &i;
	printf("%d\n", *ptr);

	ptr2 = &ptr;
	printf("%d", **ptr2);
	
}
