#include <stdio.h>
#include <string.h>

int main() {
  char str1[10] = "abcd", str2[] = "abce";

  	strncat(str1, str2, 6);
  	// comparing strings str1 and str2
  	printf("strcat(str1, str2) = %s", str1);

  return 0;
}
