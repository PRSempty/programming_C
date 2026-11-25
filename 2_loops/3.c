#include <stdio.h>

//Определяет число простое или составное

int main() {
	int n;
	int a;
	scanf("%d", &a);
	for (n=2; n<a; n++)
		if (a%n==0) break;

	if (n==a) puts("1");
	else puts("0");

	return 0;
}
