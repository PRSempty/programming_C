#include <stdio.h>

void print_oct(unsigned int a) {
    	if (a == 0) {
		return;
	}
	print_oct(a >> 3);
    	int maskr = a & 7;
    	printf("%d", maskr);
}

int main() {
	unsigned int a;
    	printf("Введите число a (> 0): ");
    	if (scanf("%u", &a) != 1 || a == 0) {
        	printf("Ошибка\n");
        	return 1;
    	}

	printf("Oct: ");
	print_oct(a);
	printf("\n");
	return 0;
}

