#include <stdio.h>

int main() {
	int a;
	int n;
	int b;
	scanf("%d %d", &a, &b);
	for (n = a; n % a != 0 || n % b != 0; n++) {
	}
	printf("НОК: %d\n", n);
	return 0;
}
