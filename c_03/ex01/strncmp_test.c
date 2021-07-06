#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "abcd", str2[] = "abce", str3[] = "abcd";
  int result;
  int n;

  n = 3;
  while (n <= 5)
  {
  	// comparing strings str1 and str2
  	result = strncmp(str1, str2, n);
  	printf("strncmp(str1, str2) = %d  //  n = %d\n", result, n);

  	// comparing strings str1 and str3
  	result = strncmp(str1, str3, n);
  	printf("strncmp(str1, str3) = %d  //  n = %d\n", result, n);
	n++;
  }

  return 0;
}
