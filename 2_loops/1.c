#include <stdio.h>

int main() {
	int i;
	int n1;
	int n2;
	scanf("%d %d", &n1, &n2);
	for (i = n1; i > 0; i--) {
		if (n1 % i == 0 && n2 % i == 0) {
			printf("НОД: %d\n", i);
			break;
		}
	}
	return 0;
}

