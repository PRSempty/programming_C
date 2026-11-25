#include <stdio.h>
#include <math.h>


int main() {
	float x;
	float y;
	printf("Введите координаты(x y): ");
	if (scanf("%f %f", &x, &y) != 2) {
		printf("Ашибачка\n");
		return 1;
	}

	if (y >= 0) {
		if (x <= 0) {
			if (y <= x + 1.0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if (y <= 1.0 - pow(x, 2)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	} else {
		printf("NO\n");
	}

return 0;
}
