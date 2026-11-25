#include <stdio.h>

int main() {
	float fff;
	float ts;
	char c;
	printf("Температура: ");
	scanf("%f%c", &ts, &c);
	if (c == 'c' || c == 'C') {
		fff = (ts * 1.8) + 32;
		printf("Итог: %f f\n", fff);
	} else if (c == 'f' || c == 'F') {
		fff = (ts - 32) * (5.0 / 9.0);
		printf("Итог: %f c\n", fff);
	} else {
		printf("Ошибка ввода\n");
	}

}
