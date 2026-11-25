#include <stdio.h>

void swchone(unsigned int a, int k) {
	unsigned int r;
	r = (a << k) | ((1 << k) - 1);
	printf("%d\n", r);
}

int main() {
	unsigned int a;
	int k;
	scanf("%d", &a);
	scanf("%d", &k);
	swchone(a, k);

	return 0;
}
