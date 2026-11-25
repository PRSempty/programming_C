#include <stdio.h>

int main()
{
	printf("|%d|\n", 555);
	printf("|%6d|\n", 555);
	printf("|%-6d|\n", 555);
	printf("Words: %8d\n", 59);
	printf("Letters: %6d\n", 1004);
	printf("a = %.8f; b = %.8f\n", 0.20000, 0.0000001); 
	printf("a + b = %.9f\n", 0.1 + 0.2);
	int max = 2147483647;
	printf("%d\n", max+100);
	unsigned int maxx = 4294967295;
	unsigned int a = 0;
	printf("%u\n", a-1);
	signed char min = -128;
	printf("%hhd\n", min-1);
	return 0;
}

