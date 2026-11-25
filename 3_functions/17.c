#include <stdio.h>


void pup(int n) {
	printf("%*s", n, "");
}


int main() {
	char z = '*';
	int i;
	int h;
	scanf("%d", &h);
	for (int i = 1; i <= h; i++) {
		pup(h - i);
		for (int n = 1; n <= (2 * i - 1); n++) {
			printf("%c", z);
		}
	printf("\n");
	}





}



